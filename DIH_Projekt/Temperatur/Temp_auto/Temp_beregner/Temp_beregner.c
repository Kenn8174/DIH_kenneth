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
#include "../Temp_beregner/Temp_beregner.h"
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

void DHT_Init(void)
{
	clear_bit(DHT_PORT, DHT_BIT);			// Output
	set_bit(DHT_DDR, DHT_BIT);				// Lav
	_delay_ms(18);							// Delay så at DHT11 kan vide at den skal være aktiv
	clear_bit(DHT_PORT, DHT_BIT)			// Input
	set_bit(DHT_DDR, DHT_BIT);				// Høj
}

int DHT_GetResponse(void)
{
	int count = 0;
	
	while (bit_is_set(DHT_PIN, DHT_BIT))	// Venter på svar fra DHT11
	{
		_delay_us(2);
		count += 2;
		if (count >= 60)				// Hvis det tager mere end 60 us, så er der ingen forbindelse
		{
			return 0;
		}
	}
	
	while (bit_is_clear(DHT_PIN, DHT_BIT))	// Venter til at svaret er færdig
	{
		
	}
	
	while (bit_is_set(DHT_PIN, DHT_BIT))	// Retunere når den har fået svar fra DHT11
	{
		return 1;
	}
}

void DHT_Read(int (*array)[8])
{
	//Waits for the DHT11 to start transmitting
	while(bit_is_set(DHT_PIN, DHT_BIT))
	{
		//Breaks when the DHT11 start transmitting
		if(bit_is_clear(DHT_PIN, DHT_BIT))
		break;
	}
	int i;
	int j;
	//Loop for each byte
	for (i = 0; i < 5; i++){
		//Loop for each bit
		for (j = 0; j < 8; j++){
			int timer = 0;
			//Waits for the LOW part of the transmission to end
			while(bit_is_clear(DHT_PIN, DHT_BIT)){}
			
			//Begins counting the time the bit is HIGH
			while(bit_is_set(DHT_PIN, DHT_BIT)){
				_delay_us(2);
				timer += 2;
			}
			//If the bit is HIGH for less than 23us the bit is Logic 0/LOW
			if (timer < 23 || timer == NULL)
			{
				array[i][j] = 0;
			}
			//If the bit is HIGH for more than 60us the bit is Logic 1/HIGH
			if (timer > 60)
			{
				array[i][j] = 1;
			}
		}
	}
}

int ConvertToDecimanl(int (*array)[8], int byte)
{
	int multiplier = 1, output = 0;
	
	for (int i = 7; i >= 0; i--)
	{
		output += (multiplier * array[byte - 1][i]);
		
		multiplier *= 2;
	}
	return output;
}