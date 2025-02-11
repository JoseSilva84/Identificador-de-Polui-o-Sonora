#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <math.h>
#include "hardware/pwm.h"

/*
 * Microcontrolador: BitDogLab (RP2040) + linguagem C
 * Projeto: Identificador de Poluição Sonora
 * Autor: José Evangelista da Silva Filho
 */

#define ADC_PIN 28        // Pino do microfone no BitDogLab (verifique o correto)
#define VREF 3.3          // Tensão de referência (ajuste se necessário)
#define ADC_MAX 4095.0    // Resolução do ADC (12 bits)
#define V_REF_MIC 1.0     // Tensão de referência do microfone (ajuste conforme necessário)
#define LIMITE_DB 65.0    // Limite para considerar som alto
#define EPSILON 0.001     // Pequeno valor para evitar log(0)

#define LED_VERDE 11      // LED verde no GPIO 11
#define LED_VERMELHO 13   // LED vermelho no GPIO 13

#define BUZZER_PIN 21
#define BUZZER_FREQ_HZ 3200 // Frequência do buzzer (Hz)
#define PWM_WRAP 4096       // Ajuste para o PWM
#define PWM_OFF 0

void inicia_buzzer_pwm() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    
    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, 4.0); // Ajuste para a frequência do buzzer
    pwm_config_set_wrap(&cfg, PWM_WRAP);
    
    pwm_init(slice_num, &cfg, true);
    pwm_set_gpio_level(BUZZER_PIN, PWM_OFF);
}

void buzzer_ligar() {
    pwm_set_gpio_level(BUZZER_PIN, PWM_WRAP / 2);
}

void buzzer_desligar() {
    pwm_set_gpio_level(BUZZER_PIN, PWM_OFF);
}

float calcular_db(float tensao) {
    if (tensao < EPSILON) {
        return 0.0;
    }
    return 20 * log10(tensao / V_REF_MIC);
}

int main() {
    stdio_init_all();
    sleep_ms(1000);
    adc_init();

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    adc_gpio_init(ADC_PIN);
    adc_select_input(2); // Confirme se é o ADC correto na BitDogLab

    inicia_buzzer_pwm();

    while (1) {
        uint16_t adc_valor = adc_read();
        float tensao = adc_valor * (VREF / ADC_MAX); // Conversão do ADC para tensão
        float db = calcular_db(tensao);

        if (db == 0.0) {
            printf("Som: 0 dB\n");
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_VERMELHO, 0);
            buzzer_ligar();
        } 
        else if (db > LIMITE_DB) {
            printf("Som Alto: %.2f dB\n", db);
            gpio_put(LED_VERDE, 0);
            gpio_put(LED_VERMELHO, 1);
            buzzer_ligar();
        } 
        else {
            printf("Som Normal: %.2f dB\n", db);
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_VERMELHO, 0);
            buzzer_desligar();
        }

        sleep_ms(100);
    }

    return 0;
}
