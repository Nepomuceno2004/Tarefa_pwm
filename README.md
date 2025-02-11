# Atividade: Controle de servomotor por PWM. 

Este projeto visa simular o controle de um servomotor utilizando o módulo PWM (Pulse Width Modulation) presente no microcontrolador RP2040. A implementação será realizada com a ferramenta Pico SDK e testada no simulador de eletrônica online Wokwi. O objetivo é ajustar o ângulo do servomotor variando o ciclo de trabalho do sinal PWM.

### Componentes Utilizados

1. Microcontrolador Raspberry Pi Pico W
2. Servomotor (micro servo padrão no Wokwi)
3. Requisitos da Implementação

### Configuração do PWM e Controle do Servomotor

1. Configurar a GPIO 22 com uma frequência de PWM de aproximadamente 50Hz (período de 20ms).
2. Ajustar o ciclo ativo do PWM para 2.400µs (0,12%) para posicionar o servomotor em 180° e aguardar 5 segundos.
3. Ajustar o ciclo ativo do PWM para 1.470µs (0,0735%) para posicionar o servomotor em 90° e aguardar 5 segundos.
4. Ajustar o ciclo ativo do PWM para 500µs (0,025%) para posicionar o servomotor em 0° e aguardar 5 segundos.
5. Criar uma rotina para movimentar suavemente o servomotor entre 0° e 180°, com incrementos de ±5µs e atraso de 10ms por ajuste.

### Como usar

1. Baixe o Código
2. Compile o Código
3. Carregue no Raspberry Pi Pico W
4. Teste no Simulador Wokwi

### Vídeo de funcionamento
[DRIVE](https://drive.google.com/file/d/1FJEo0KXXgcMCLifiKODautK_ANq76UAA/view?usp=sharing)

# Autor
## Matheus Nepomuceno Souza
