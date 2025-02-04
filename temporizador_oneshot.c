#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_PIN_RED 12
#define LED_PIN_GREEN 13
#define LED_PIN_BLUE 11
#define BUTTON_PIN 5

volatile bool leds_ligados = false;  // Bloqueia novas execuções enquanto a sequência não termina

// Função para desligar o último LED (callback do temporizador)
int turn_off_blue_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_PIN_BLUE, 0);  // Apaga LED azul
    leds_ligados = false;  // Permite nova ativação pelo botão
    return 0;
}

// Função para desligar o segundo LED (callback do temporizador)
int turn_off_green_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_PIN_GREEN, 0);  // Apaga LED verde
    add_alarm_in_ms(3000, turn_off_blue_callback, NULL, false);
    return 0;
}

// Função para desligar o primeiro LED (callback do temporizador)
int turn_off_red_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_PIN_RED, 0);  // Apaga LED vermelho
    add_alarm_in_ms(3000, turn_off_green_callback, NULL, false);
    return 0;
}

// Função que verifica se o botão foi pressionado
void check_button() {
    if (gpio_get(BUTTON_PIN) == 0 && !leds_ligados) {  // Se o botão foi pressionado e LEDs estão apagados
        leds_ligados = true;  // Bloqueia novas execuções

        // Liga os 3 LEDs
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_GREEN, 1);
        gpio_put(LED_PIN_BLUE, 1);

        // Inicia a sequência de temporização
        add_alarm_in_ms(3000, turn_off_red_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Inicializa os LEDs como saída
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);

    // Inicializa o botão como entrada com resistor pull-up
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        check_button();  // Monitora o botão
        sleep_ms(100);   // Pequeno atraso para evitar leituras repetitivas
    }

    return 0;
}