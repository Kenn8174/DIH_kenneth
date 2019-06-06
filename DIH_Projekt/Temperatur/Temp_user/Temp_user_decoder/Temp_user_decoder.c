/*
 * Temp_user_beregner.c
 *
 * Created: 05-06-2019 14:15:24
 *  Author: kenne
 */ 

#include <avr/io.h>


///Decoder til Temp_user. Bestemmer hvor hurtig blæseren skal køre.
void Temp_user_decoder(int column, int row)
{
	
	unsigned int Temp_user_input = column + row;
	
	switch (Temp_user_input)
	{
		case 12:
			OCR1B = 0;			//Keyboard == 0
		break;
		
		case 41:
			OCR1B = 80;			//Keyboard == 1
		break;
		
		case 42:
			OCR1B = 90;			//Keyboard == 2
		break;
		
		case 43:
			OCR1B = 100;		//Keyboard == 3
		break;
		
		case 31:
			OCR1B = 120;		//Keyboard == 4
		break;
		
		case 32:
			OCR1B = 140;		//Keyboard == 5
		break;
		
		case 33:
			OCR1B = 160;		//Keyboard == 6
		break;
		
		case 21:
			OCR1B = 200;		//Keyboard == 7
		break;
		
		case 22:
			OCR1B = 230;		//Keyboard == 8
		break;
		
		case 23:
			OCR1B = 255;		//Keyboard == 9
		break;
		
		default:
								//Keyboard == Alt andet
		break;
	}
}