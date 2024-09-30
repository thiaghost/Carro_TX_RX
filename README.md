# README

## Visão Geral
Este conjunto de códigos para Arduino implementa um sistema de controle de um motor usando comunicação sem fio e um sensor ultrassônico para detectar a distância. O sistema pode acelerar ou frear o motor com base nas mensagens recebidas ou nas leituras do sensor de distância.

## Requisitos de Hardware
- Placa Arduino (ex: Arduino Uno)
- Módulo de comunicação sem fio (ex: RF 433 MHz)
- Motor DC controlado por H-Bridge (ex: L298N)
- Sensor ultrassônico (ex: HC-SR04)
- LED para indicação
- Fios de conexão e protoboard para montagem

## Funcionalidades
- **Comunicação Sem Fio**: O sistema usa a biblioteca VirtualWire para enviar e receber comandos que controlam o motor.
- **Controle do Motor**: Permite que o motor se mova para frente, para trás ou pare, dependendo das mensagens recebidas.
- **Detecção de Distância**: O sensor ultrassônico mede a distância e controla o motor com base em sua leitura.
- **Indicação Visual**: Um LED é acionado quando a distância medida está abaixo de um certo limite.

## Estrutura do Código

### Definições e Inicializações
- **Bibliotecas**: Inclui a biblioteca `VirtualWire` para comunicação sem fio e `Ultrasonic` para o sensor de distância.
- **Variáveis**: Define variáveis para armazenar mensagens recebidas e pinos para controle do motor e sensor.

### Configuração de Pinos e Inicializações
- **`setup()`**: Inicializa a comunicação serial, configura os pinos do motor e do LED, e inicia o sistema de comunicação sem fio.

### Controle do Motor
- **`sentidoTras()` e `sentidoFrente()`**: Funções para controlar a direção do motor.
- **`acelerar()`**: Acelera o motor e envia uma mensagem via comunicação sem fio.
- **`freio()`**: Para o motor e envia uma mensagem via comunicação sem fio.

### Loop Principal (`loop()`)
- **Primeiro Código**: 
  - Verifica se uma mensagem foi recebida.
  - Se a mensagem é '1', acelera o motor. Se a mensagem é '2', freia o motor.
- **Segundo Código**: 
  - Lê a distância do sensor ultrassônico.
  - Se a distância é maior que 30 cm, acelera o motor; se não, aciona o LED e freia o motor.

## Como Funciona
1. **Inicialização**: O microcontrolador inicializa a comunicação serial, os pinos do motor, do LED e do sensor ultrassônico.
2. **Comunicação Sem Fio**: O módulo de comunicação sem fio permite receber comandos para controlar o motor.
3. **Detecção de Distância**: O sensor ultrassônico mede a distância continuamente. Se a distância for maior que 30 cm, o motor acelera; se não, o motor é freado e um LED é acionado.
4. **Feedback Visual**: O LED indica quando o motor está em freio, fornecendo uma indicação visual da situação do motor.

## Compilação e Uso
- Para compilar e carregar o código, utilize um IDE compatível com Arduino (ex: Arduino IDE).
- Conecte o módulo de comunicação sem fio, o motor e o sensor ultrassônico conforme a configuração definida nos pinos.
- Após carregar o código no Arduino, o sistema começará a operar automaticamente, respondendo a comandos recebidos e lendo distâncias do sensor.

## Notas
- Certifique-se de que as conexões estão corretas para evitar danos ao hardware.
- Ajuste a distância de referência (30 cm) de acordo com a aplicação desejada.
- O código pode ser expandido para incluir mais funcionalidades, como controle remoto, ajustes de velocidade, etc.
