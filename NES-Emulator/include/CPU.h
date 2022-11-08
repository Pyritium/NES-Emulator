#pragma once

class CPU
{
	uint16_t PC; // Program counter
	uint16_t SP; // Stack pointer
	
	uint8_t A, X, Y; // Registers

	//Flags & Statuses
	uint8_t C : 1;
	uint8_t Z : 1;
	uint8_t I : 1;
	uint8_t D : 1;
	uint8_t B : 1;
	uint8_t O : 1;
	uint8_t N : 1;
};
