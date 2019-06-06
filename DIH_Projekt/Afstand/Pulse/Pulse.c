/*
 * CFile1.c
 *
 * Created: 04-06-2019 12:23:42
 *  Author: kenne
 */ 

#include "avr/io.h"
#define F_CPU 16E6
#include "util/delay.h"


void Pulse()
{
	PORTL |= (1<<0);
	_delay_us(10);
	PORTL &= ~(1<<0);
}