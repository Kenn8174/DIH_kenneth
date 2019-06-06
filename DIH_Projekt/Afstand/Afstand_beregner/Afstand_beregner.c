/*
 * Afstand_beregner.c
 *
 * Created: 04-06-2019 12:19:47
 *  Author: kenne
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#define F_CPU 16E6
#include "util/delay.h"
#include <stdlib.h>
#include "stdio_setup.h"
#include "lcd/lcd.h"
#include "../Afstand/Pulse/Pulse.h"

#define START_TIMER TCCR1B |= ((1 << CS11) | (1 << CS10))
#define STOP_TIMER TCCR1B &= ~((1 << CS11) | (1 << CS10))

volatile unsigned int pulseStart;
volatile unsigned int pulseEnd;
volatile unsigned int pulseInUs = 2013;
volatile unsigned char edge =0;
volatile unsigned int success = 0;
volatile unsigned int failure = 0;

void Afstand_beregner()
{
	TCCR1A = 0;
	
	Pulse();
	
}