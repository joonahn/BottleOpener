/*
 * for문을 사용한 코드
 *
 * PB1 - PWMA
 * PB2 - PWMB
 * 
 */

#define F_CPU 8000000
#define ubrr 51
#define badu 9600

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <string.h>
#include <stdio.h>
#include "tools.h"

//port configuration
#define AIN1 PC0
#define AIN2 PC1
#define BIN1 PD0
#define BIN2 PD1

int main()
{
	// PORT Init
	DDRB = 6;
	DDRC = 0x03;
	DDRD = 0x03;

	// PWM Init
	pwm_init();
	pwm(1, 20);
	pwm(2, 20);

	//Motor Signal Initialization
	PORTD = 0;
	PORTC = 0;


	while(1)
	{
		PORTC |= (1<<PC0);
		PORTD |= (1<<PD1);
		_delay_ms(300);
		PORTC = 0;
		PORTD = 0;
		_delay_ms(300);
		PORTC |= (1<<PC1);
		PORTD |= (1<<PD0);
		_delay_ms(300);
		PORTC = 0;
		PORTD = 0;
		_delay_ms(300);
	}
}