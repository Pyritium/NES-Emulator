#pragma once
#include <cstdint>

class Memory
{
public:
	static constexpr unsigned int MAX = 1024 * 64;
	uint8_t Data[MAX];

	void Init()
	{
		for (unsigned int i = 0; i < MAX; i++)
		{
			Data[i] = 0;
		}
	}
};


class CPU : Memory
{
public:
	void Reset()
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C, Z, I, D, B, V, N = 0;
		A, X, Y = 0;
		Init();
	}

	uint8_t FetchByte(unsigned int& Cycles)
	{
		uint8_t ByteData = Data[PC];
		PC++;
		Cycles--;
		return ByteData;
	}

	void Execute(unsigned int Cycles)
	{
		while (Cycles > 0)
		{
			uint8_t Ins = FetchByte(Cycles);
		}
	}

private:
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
