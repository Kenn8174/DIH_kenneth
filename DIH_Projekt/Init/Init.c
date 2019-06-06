/*
 * Init.c
 *
 * Created: 28-05-2019 13:21:17
 *  Author: kenne
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "stdio_setup.h"


/// Init initializere portene som skal bruges, laver dem enten til Output eller Input.
void Init(){
	
	
	/* Matrix Keyboard */
	// Column sat til høj
	DDRK |= (1<<PK0);
	DDRK |= (1<<PK1);
	DDRK |= (1<<PK2);
	DDRK |= (1<<PK3);

	// Row sat til input
	PORTK |= (1<<PK4);
	PORTK |= (1<<PK5);
	PORTK |= (1<<PK6);
	PORTK |= (1<<PK7);
	
	
	/* Afstandsmåleren */
	
	DDRL = (1<<PL1);				// Trigger sat til Output
	
	//PORTL &= ~(1<<PL4);				// Echo sat til Input
	
	
	/* Temperaturmåler */
	
	ADMUX = (1 << REFS0);	// 5V supply used for ADC reference, select ADC channel 0, datasheet 28.9.1
	DIDR0 = (1 << ADC0D);	// disable digital input on ADC0 pin, datasheet 28.9.6
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	// enable ADC, start ADC, ADC clock = 16MHz / 128 = 125kHz, datasheet 28.9.2
	
	
	/* DC Motor */
	
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1C1);	//Non inverting mode
	TCCR1A |= (1<<WGM10);	//Fast PWM
	TCCR1B |= (1<<WGM12);	//^^
	TCCR1B |= (1<<CS11) | (1<<CS10);	//Sætter prescaleren til 64
	
	DDRB |= (1<<PB6);	//PB6 Sat til høj
	
}