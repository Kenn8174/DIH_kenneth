/*
 * ReadRow.c
 *
 * Created: 29-05-2019 10:29:21
 *  Author: kenne
 */ 

//#include <stdio.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
//#include "stdio_setup.h"


///ReadRow
/** ReadRow tjekker om en knap i en bestemt r�kke bliver trykket p�. Derefter returner den et nummer som s� bliver brugt til at decoding af hvad der er blevet trykket p�.
(f.eks. Den �verste r�kke er 40, dvs. knap 43 er R�kke 4 (40) og Kolonne 3 (4) som s� er [3] p� Keyboardet */
int ReadRow(){
	_delay_ms(10);
	if (!(PINK & (1<<PINK4)))
	{
		return 10;
	}
	if (!(PINK & (1<<PINK5)))
	{
		return 20;
	}
	if (!(PINK & (1<<PINK6)))
	{
		return 30;
	}
	if (!(PINK & (1<<PINK7)))
	{
		return 40;
	}
	return 90;
}