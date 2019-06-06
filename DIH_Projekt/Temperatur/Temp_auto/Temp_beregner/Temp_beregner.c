/*
 * Temp_beregner.c
 *
 * Created: 03-06-2019 11:14:51
 *  Author: kenne
 */ 

#define F_CPU 16E6
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "stdio_setup.h"
#include <avr/io.h>
#include "lcd/lcd.h"
#include "../Temperatur/Temp_auto/Temp_auto_display/Temp_auto_display.h"


///beregner temperaturen så den vises korrekt, samt ændre hastigheden på blæseren.
void Temp_beregner()
{	
	unsigned int ADC_data;
	
	if (!(ADCSRA & (1 << ADSC)))
	{
		
		ADC_data = ADC;
		
		float Temp = log(10000.0 * ((1024.0/ADC_data) -1));
		float TempK = 1/(0.001129148+(0.000234125+(0.0000000876741*Temp*Temp))*Temp);
		float TempC = TempK - 273.15;
		
		Temp_auto_display(TempC);
		
		/*if (TempC < 20)
		{
			OCR1B = 0;		//Slukker blæseren hvis temperaturen er under 20 Grader
		}*/
		
		if (TempC > 25)
		{
			OCR1B = 250;	//Sætter hastigheden op hvis temperaturen er over 25 Grader
		}
		
		if (TempC < 25)
		{
			OCR1B = 128;	//Hastigheden på blæseren er middel hvis temperaturen er imellem 20 og 25 Grader
		}
		
		ADCSRA |= (1 << ADSC);
		_delay_ms(1000);		
		
	}	
}