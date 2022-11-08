/*
	Title: NES Emulator
	Author(s): Joshua Tunberg, Nisan Shaulov
	Date: 11/6/2022-??/??/????
	Note(s):


*/

#include <iostream>
#include "include/CPU.h"

int main()
{
	CPU CPU;
	CPU.Reset();
	CPU.Execute(2);

	return 0;
}