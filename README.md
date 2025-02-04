# 🚦 Projeto: Temporizador de um Disparo para Acionamento de LEDs  
**(Daniel Silva de Souza) - Danngas**


## 📌 Descrição  

Este projeto implementa um sistema de temporização para acionamento de LEDs utilizando um **Raspberry Pi Pico W**. O sistema é ativado por um botão (pushbutton) e desliga os LEDs sequencialmente a cada **3 segundos**, conforme os requisitos da atividade.  

O projeto foi desenvolvido como parte de uma atividade prática que exigia o uso da função `add_alarm_in_ms()` do **Pico SDK** para criar um temporizador de um disparo (one-shot) e controlar a mudança de estados dos LEDs.

---

## 🛠️ Componentes Utilizados  

- **Microcontrolador:** Raspberry Pi Pico W  
- **LEDs:**  
  - 1x LED Azul  
  - 1x LED Vermelho  
  - 1x LED Verde  
- **Resistores:** 3x Resistores de 330 Ω  
- **Botão:** 1x Pushbutton  
- **Ferramenta de Simulação:** Wokwi  
- **Linguagem de Programação:** C  
- **Frameworks:** Pico SDK  

---

## 🎯 Funcionalidades  

✔️ **Acionamento por botão:** O sistema é ativado ao pressionar o botão, ligando todos os LEDs.  
✔️ **Desligamento sequencial:** Após 3 segundos, os LEDs são desligados um por um, com intervalo de 3 segundos entre cada desligamento.  
✔️ **Bloqueio de acionamento:** O botão só pode ser pressionado novamente após todos os LEDs serem desligados.  
✔️ **Debounce simples:** Implementação de um debounce básico para evitar leituras falsas do botão.  

---

## 📋 Requisitos da Atividade  

1. **Acionamento dos LEDs:** Ao pressionar o botão, todos os LEDs são ligados.  
2. **Temporização de 3 segundos:** Cada LED é desligado sequencialmente, com intervalo de 3 segundos.  
3. **Função de callback:** A mudança de estado dos LEDs é implementada na função de callback do temporizador.  
4. **Bloqueio do botão:** O botão só pode ser pressionado novamente após o último LED ser desligado.  
5. **Simulação no Wokwi:** O projeto foi simulado no Wokwi, conforme o diagrama sugerido.  


---

## 🛠️ Estrutura do Código  

O código foi organizado da seguinte forma:  

### 🔹 Arquivo Principal: `temporizador_leds..c`  
- **Inicialização dos pinos:** Configura os pinos dos LEDs como saída e o pino do botão como entrada com pull-up.  
- **Loop principal:** Verifica o estado do botão e inicia a sequência de acionamento dos LEDs.  
- **Debounce simples:** Aguarda 50 ms para confirmar o pressionamento do botão.  

### 🔹 Função de Callback: `callback_desligar_leds`  
- **Desligamento sequencial:** Desliga os LEDs um por um, com intervalo de 3 segundos.  
- **Finalização:** Reinicia o estado do sistema após o último LED ser desligado.  

### 🔹 Constantes e Definições  
- **Pinos dos LEDs:**  
  ```c
  #define PINO_LED_AZUL 11
  #define PINO_LED_VERMELHO 12
  #define PINO_LED_VERDE 13

## 🚀 Como Executar o Projeto

### 📌 Requisitos

* Hardware:

    Raspberry Pi Pico W

    3x LEDs (vermelho, amarelo, verde)

    3x Resistores de 330 Ω

    1x Pushbutton

    Protoboard e jumpers

* Software:

    Pico SDK instalado e configurado

    Compilador ARM GCC

    Ferramenta CMake


### 🚀 Passos para Compilação e Upload  

1. **Clonar o repositório**  
   ```sh
    git clone https://github.com/Danngas/Projeto-Temporizador-de-um-Disparo-para-Acionamento-de-LEDs-.git
    cd semaforo-pico


2. **Configurar e compilar o projeto**  

``mkdir build && cd build``
``cmake ..``
``make``

3. **Transferir o firmware para a placa**

Conectar a placa BitDogLab ao computador
Copiar o arquivo .uf2 gerado para o drive da placa
4. **Testar o projeto**


## 📜 Licença  

Este projeto está sob a licença MIT. Sinta-se à vontade para utilizá-lo e modificá-lo conforme necessário.  
