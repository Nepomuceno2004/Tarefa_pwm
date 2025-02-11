#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_SERVO 22 //pino do servo conectado a GPIO como PWM
const uint16_t WRAP_PERIOD = 20000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM

const uint16_t STEP = 5; //passo de incremento/decremento para o duty cycle do LED
uint16_t level = 500; //nível inicial do pwm (duty cycle)

void pwm_setup();

//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    
    pwm_setup(); //configura o PWM

    uint up_down = 1; //variável para controlar se o nível do servo aumenta ou diminui

    //loop principal
    while (true) {
        
        pwm_set_gpio_level(PWM_SERVO, level); //define o nível atual do PWM (duty cycle)

        if (up_down) 
        {
            level += STEP; // Incrementa o nível do servo
            if (level >= 2400)
                up_down = 0; // Muda direção para diminuir quando atingir o período máximo
        }
        else
        {
            level -= STEP; // Decrementa o nível do servo
            if (level <= 500)
                up_down = 1; // Muda direção para aumentar quando atingir o mínimo
        }
        
        sleep_ms(10);
    }
}

//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM 125,0

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap 2000

    pwm_set_gpio_level(PWM_SERVO, 2400); //definir o cico de trabalho (duty cycle) do pwm
    
    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
    
    sleep_ms(5000);
    
    pwm_set_gpio_level(PWM_SERVO, 1470); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_SERVO, 500); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);
}