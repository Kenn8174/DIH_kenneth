
#include "Menu/Menu.h"
#include "Init/Init.h"

///Main g�r ikke det store end at k�re Menu() i loop. Menuen kunne rent teoretisk ogs� ligge her i main.
int main(void)
{
	//UartInit();
	Init();

	//while(1) {
		Menu();
	//}
}