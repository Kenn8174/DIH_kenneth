/*
 * TemperatureDecode.c
 *
 * Created: 29-05-2019 12:27:15
 *  Author: kenne
 */ 

#define F_CPU 16E6
#include <util/delay.h>

#include "../Temperatur/Temp_auto/Temp_auto.h"
#include "../Temperatur/Temp_user/Temp_user.h"

unsigned int chosenTemp = 1;

/// lige som alle de andre decoder, kører den det igennem som brugeren har valgt.
void Temp_decoder(int column, int row){
	chosenTemp = column + row;
	
	switch (chosenTemp)
	{
		case 44:
			Temp_auto();
		break;
		
		case 34:
			Temp_user();
		break;
				
		default:
		/* Your code here */
		break;
	}
}