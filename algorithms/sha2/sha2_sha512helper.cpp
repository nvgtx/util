#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "sha2_sha512helper.h"

//SHA-384 and SHA-512 Functions
uint64 sha2_Ch(uint64 x, uint64 y, uint64 z)
{
	// (X AND Y) XOR (NOT X AND Z)
	return (x & y) ^ (~x & z);
}

uint64 sha2_Maj(uint64 x, uint64 y, uint64 z)
{
	// (X AND Y) XOR (X AND Z) XOR (Y AND Z)
	return (x & y) ^ (x & z) ^ (y & z);
}

uint64 sha2_rightShift(uint64 x, uint64 i)
{
	return x>>i;
}

uint64 sha2_rightRotate(uint64 x, uint64 i)
{
	return (x>>i) | (x<<(sizeof(uint64)*8-i));
}

uint64 sha2_upperSigma0(uint64 x)
{
	return sha2_rightRotate(x, 28) ^ sha2_rightRotate(x, 34) ^ sha2_rightRotate(x, 39);
}

uint64 sha2_upperSigma1(uint64 x)
{
	return sha2_rightRotate(x, 14) ^ sha2_rightRotate(x, 18) ^ sha2_rightRotate(x, 41);
}

uint64 sha2_lowerSigma0(uint64 x)
{
	return sha2_rightRotate(x, 1) ^ sha2_rightRotate(x, 8) ^ sha2_rightShift(x, 7);
}

uint64 sha2_lowerSigma1(uint64 x)
{
	return sha2_rightRotate(x, 19) ^ sha2_rightRotate(x, 61) ^ sha2_rightShift(x, 6);
}

uint8* sha2_getAdr(uint8* str, uint128 val)
{
	uint128 i=0;
	if(val.high==0)
	{
		return &str[val.low];
	}

	for(i=0; i<val; i++)
	{
		str++;
	}
	return str;
}



