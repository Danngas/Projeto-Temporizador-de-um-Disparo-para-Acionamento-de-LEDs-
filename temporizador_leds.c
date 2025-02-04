#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definindo os pinos dos LEDs e do botão
const uint PINO_LED_AZUL = 11;     // LED Azul no GPIO 11
const uint PINO_LED_VERMELHO = 12; // LED Vermelho no GPIO 12
const uint PINO_LED_VERDE = 13;    // LED Verde no GPIO 13
const uint PINO_BOTAO = 5;         // Botão no GPIO 5

// Variáveis de estado
bool leds_ativos = false; // Indica se os LEDs estão ativos
int estado_led = 0;       // Controla o estado atual dos LEDs

// Array para armazenar os pinos dos LEDs
const uint PINOS_LEDS[] = {PINO_LED_AZUL, PINO_LED_VERMELHO, PINO_LED_VERDE};

// Função de callback para desligar os LEDs sequencialmente
int64_t callback_desligar_leds(alarm_id_t id, void *user_data)
{
    // Desliga o LED atual
    gpio_put(PINOS_LEDS[estado_led], false);

    // Verifica se todos os LEDs foram desligados
    if (estado_led == 2)
    {
        leds_ativos = false; // Desativa o controle dos LEDs
        estado_led = 0;      // Reinicia o estado do LED
        return 0;            // Finaliza a sequência
    }

    // Avança para o próximo LED
    estado_led++;

    // Agenda outro alarme para continuar a sequência após 3 segundos
    add_alarm_in_ms(3000, callback_desligar_leds, NULL, false);
    return 0;
}

int main()
{
    // Inicializa a comunicação serial (para printf)
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    for (int i = 0; i < 3; i++)
    {
        gpio_init(PINOS_LEDS[i]);
        gpio_set_dir(PINOS_LEDS[i], GPIO_OUT);
    }

    // Configura o pino do botão como entrada com pull-up
    gpio_init(PINO_BOTAO);
    gpio_set_dir(PINO_BOTAO, GPIO_IN);
    gpio_pull_up(PINO_BOTAO);

    // Loop principal
    while (true)
    {
        // Verifica se o botão foi pressionado e os LEDs não estão ativos
        if (gpio_get(PINO_BOTAO) == 0 && !leds_ativos)
        {
            sleep_ms(50);                  // Debounce simples (aguarda 50ms para evitar ruído)
            if (gpio_get(PINO_BOTAO) == 0) // Confirma o pressionamento do botão
            {
                // Liga todos os LEDs
                for (int i = 0; i < 3; i++)
                {
                    gpio_put(PINOS_LEDS[i], true);
                }

                // Atualiza o estado
                leds_ativos = true;
                estado_led = 0;

                // Inicia a sequência de desligamento após 3 segundos
                add_alarm_in_ms(3000, callback_desligar_leds, NULL, false);
            }
        }
        sleep_ms(10); // Aguarda um curto período para evitar uso excessivo da CPU
    }

    return 0;
}