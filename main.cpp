#include "ColorPrint.h"

int main() {
    PRINT('I', "lalala, I am white" << 1 << "!");
    PRINT('N', "lalala, I am cyan" << 2 << "!");
    PRINT('W', "lalala, I am yellow" << 3 << "!");
    PRINT('S', "lalala, I am green" << 4 << "!");
    PRINT('E', "lalala, I am red" << 5 << "!");
    PRINT('I', "lalala, I am white again" << 6 << "!");

	PRINTF('I', "lalala, I am white%d!", 1);
	PRINTF('N', "lalala, I am cyan%d!", 2);
	PRINTF('W', "lalala, I am yellow%d!", 3);
	PRINTF('S', "lalala, I am green%d!", 4);
	PRINTF('E', "lalala, I am red%d!", 5);
	PRINTF('I', "lalala, I am white again%d!", 6);
}