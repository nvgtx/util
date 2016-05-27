#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "rsaAlgorithm.h"

// FUNCTION   : uintInfinite rsaEncrypt(uintInfinite msg, uintInfinite exp, uintInfinite n)
// DESCRIPTION: use the RSA encryption algoritm on a input value
// PARAMETERS : uintInfinite msg - the value to be encrypted or decrypted
//              uintInfinite exp - the exponent value of the public or secret key
//              uintInfinite n   - the modulo value of the key
// RETURNS    : encrypted, decrypted or signed uintInfinite value
// COMMENT    : same function for encryption and decryption,
//              public key encrypts and validates, secret key decrypts and signs
uintInfinite rsaEncrypt(uintInfinite msg, uintInfinite exp, uintInfinite n)
{
	uintInfinite result=0;

	//reverse binary order
	result=0;
	while(exp > 0)
	{
		result=(result << 1) + (exp & 0x1); 
		exp>>=1;
	}
	exp=result;

	//square-and-multiply algorithm
	result=1;
	while(exp > 0)
	{
		//square
		result=(result * result) % n;

		//multiply
		if((exp & 0x1) == 1) //if exp is odd
		{
			result=(msg * result) % n;
		}
		exp>>=1;
	}
	return result;
}
