# ⏳ Projeto: Temporizador de Disparo (One Shot Timer) no Raspberry Pi Pico

## 📌 Descrição
Este projeto implementa um sistema de temporização utilizando a função **add_alarm_in_ms()** do **Pico SDK**. Um botão (pushbutton) aciona um temporizador que controla a transição de LEDs RGB conectados ao Raspberry Pi Pico. Os LEDs acendem em sequência e apagam gradualmente em intervalos de **3 segundos**, com controle para evitar novas ativações durante a execução.

## 🎯 Objetivos
- Aplicar **timers de disparo único (one shot timer)**.
- Utilizar **interrupções de botões** e **debouncing via software**.
- Manipular **GPIOs** para controle de LEDs RGB.

## 🛠️ Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico (Placa BitDogLab)
- **LED RGB** (conectado às GPIOs 11, 12 e 13)
- **Botão (Pushbutton)** (conectado à GPIO 5)
- **Linguagem**: C (Pico SDK)

## 🔌 Ligações dos Pinos
| Componente  | GPIO |
|------------|------|
| LED Azul   | 11   |
| LED Vermelho | 12   |
| LED Verde  | 13   |
| Botão     | 5    |

## 📜 Funcionamento
1. Quando o **botão** é pressionado, **todos os LEDs acendem** simultaneamente.
2. Após **3 segundos**, **apenas dois LEDs permanecem acesos**.
3. Após mais **3 segundos**, **somente um LED permanece aceso**.
4. Após mais **3 segundos**, **todos os LEDs são desligados**, permitindo um novo acionamento do botão.
5. Durante esse processo, **o botão não pode reiniciar a sequência até que os LEDs estejam todos apagados**.

## 🚀 Como Executar o Código
1. Clone este repositório ou copie o código para seu ambiente de desenvolvimento.
2. Compile o código utilizando o **Pico SDK**.
3. Transfira o arquivo **.uf2** gerado para a Raspberry Pi Pico.
4. Pressione o **botão** e observe o comportamento dos LEDs conforme o temporizador executa as transições.

## 📂 Estrutura do Projeto
```
/
├── src/
│   ├── main.c  # Código principal do projeto
│   ├── CMakeLists.txt  # Configuração do CMake para compilação
│
└── README.md  # Este arquivo com a documentação
```

## 🔧 Dependências
- **Raspberry Pi Pico SDK** (deve estar configurado no ambiente de desenvolvimento)
- **Compilador GCC ARM** para gerar o código binário

## 📑 Referências
- [Documentação oficial do Raspberry Pi Pico SDK](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
- [Uso de Timers no RP2040](https://www.raspberrypi.com/documentation/microcontrollers/)

