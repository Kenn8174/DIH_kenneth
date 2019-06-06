/*
 * MenuChosen.c
 *
 * Created: 29-05-2019 10:59:53
 *  Author: kenneth
 */ 

#define F_CPU 16E6
#include <util/delay.h>
#include "../Temperatur/Temp_menu.h"
#include "../Afstand/Afstand.h"

unsigned int chosen = 1;


///Decoder for menu
/** Menu_decoder henter Kolonne nummeret og Række nummeret som vi fik fra (ColumnScan) og (ReadRow). Derefter bliver de sat sammen og smidt ned i switch casen. */
void Menu_decoder(int column, int row){
	
	chosen = column + row;
	
	switch (chosen)
	{
		case 44:
			Afstand();
		break;
		
		case 34:
			Temp_menu();
		break;
		
		default:
		
		break;
	}
	
}