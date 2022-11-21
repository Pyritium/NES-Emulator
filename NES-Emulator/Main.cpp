/*
	Title: NES Emulator
	Author(s): Joshua Tunberg, Nisan Shaulov
	Date: 11/6/2022-??/??/????
	Note(s):


*/

#include <iostream>
#include "include/CPU.h"

#define SizeOf(x) ((char*)(&x+1) - (char*)(&x))  

int main(int argc, char* argv[])
{
	Memory Memory;
	
	CPU CPU;
		CPU.Reset(Memory);

	Memory[0xFFFC] = CPU::LDA_IM; 
	
	CPU.Execute(2, Memory);

	return 0;
}