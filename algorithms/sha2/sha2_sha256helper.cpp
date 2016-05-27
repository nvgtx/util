#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "sha2_sha256helper.h"

//SHA-224 and SHA-256 Functions
uint32 sha2_Ch(uint32 x, uint32 y, uint32 z)
{
	// (X AND Y) XOR (NOT X AND Z)
	return (x & y) ^ (~x & z);
}

uint32 sha2_Maj(uint32 x, uint32 y, uint32 z)
{
	// (X AND Y) XOR (X AND Z) XOR (Y AND Z)
	return (x & y) ^ (x & z) ^ (y & z);
}

uint32 sha2_rightShift(uint32 x, uint32 i)
{
	return x>>i;
}

uint32 sha2_rightRotate(uint32 x, uint32 i)
{
	return (x>>i) | (x<<(sizeof(uint32)*8-i));
}

uint32 sha2_upperSigma0(uint32 x)
{
	return sha2_rightRotate(x, 2) ^ sha2_rightRotate(x, 13) ^ sha2_rightRotate(x, 22);
}

uint32 sha2_upperSigma1(uint32 x)
{
	return sha2_rightRotate(x, 6) ^ sha2_rightRotate(x, 11) ^ sha2_rightRotate(x, 25);
}

uint32 sha2_lowerSigma0(uint32 x)
{
	return sha2_rightRotate(x, 7) ^ sha2_rightRotate(x, 18) ^ sha2_rightShift(x, 3);
}

uint32 sha2_lowerSigma1(uint32 x)
{
	return sha2_rightRotate(x, 17) ^ sha2_rightRotate(x, 19) ^ sha2_rightShift(x, 10);
}

