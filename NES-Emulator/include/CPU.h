#pragma once
#include <cstdint>
#include <iostream>

class Memory
{
public:
	static constexpr unsigned int MAX_MEMORY = 1024 * 64;
	uint8_t Data[MAX_MEMORY];

	void Init()
	{
		for (unsigned int i = 0; i < MAX_MEMORY; i++)
		{
			Data[i] = 0;
		}
	}

	//Read 1 Byte
	uint8_t operator[](unsigned int Address) const
	{
		return Data[Address];
	}
	
	//Write 1 Byte
	uint8_t& operator[](unsigned int Address)
	{
		return Data[Address];
	}
};


class CPU
{
public:
	static constexpr uint8_t LDA_IM = 0xA9; //LDA - Load Accumulator /0xA9 - Immediate Addressing Mode

	void Reset(Memory& Memory)
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C, Z, I, D, B, V, N = 0;
		A, X, Y = 0;
		Memory.Init();
	}

	uint8_t FetchByte(unsigned int& Cycles, Memory& Memory)
	{
		uint8_t ByteData = Memory[PC];
		PC++;
		Cycles--;
		return ByteData;
	}


	void Execute(unsigned int Cycles, Memory& Memory)
	{
		while (Cycles > 0)
		{
			uint8_t Instruction = FetchByte(Cycles, Memory);
			
			switch (Instruction)
			{
				case LDA_IM:
				{
					uint8_t ByteData = FetchByte(Cycles, Memory);
					A = ByteData;
					Z = (A == 0);
					N = (A & 0b10000000) > 0;
					break;
				}
				default:
				{
					std::cout << "Unknown Instruction: " << Instruction << std::endl;
					break;
				}
			}
		}
	}

private:
	//OPCODES:
	uint16_t PC; // Program counter
	uint16_t SP; // Stack pointer

	uint8_t A, X, Y; // Registers

	//Flags & Statuses
	uint8_t C : 1;
	uint8_t Z : 1;
	uint8_t I : 1;
	uint8_t D : 1;
	uint8_t B : 1;
	uint8_t V : 1;
	uint8_t N : 1;
};
