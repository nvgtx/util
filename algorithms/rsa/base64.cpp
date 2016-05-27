#include <string>

#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "typeConverters.h"
#include "base64.h"

// FUNCTION   : bool is_base64(uint8)
// DESCRIPTION: check if character is a valid base64 value
// PARAMETERS : character to be checked
// RETURNS    : boolean value, true if valid
bool is_base64(uint8 c)
{
	uint8 i=0;
	for(i=0; i<base64_chars.length(); i++)
	{
		if(c==base64_chars[i])
		{
			return true;
		}
	}
	return false;
}

// FUNCTION   : std::string base64Encode(const uint8*, uint32)
// DESCRIPTION: encode a string in base64
// PARAMETERS : unsigned character string to be encoded
//              unsigned length value of string
// RETURNS    : base64 encoded std::string of input data
// COMMENT    : cast from char* to uint8* if neccesary
std::string base64Encode(const uint8* bytes_to_encode, uint32 in_len)
{
	std::string ret;
	uint32 i=0;
	uint32 j=0;
	uint8 char_array_3[3];
	uint8 char_array_4[4];

	//encode String
	while(in_len--)
	{
		char_array_3[i++]=*(bytes_to_encode++);
		if(i==3)
		{
			char_array_4[0]=(char_array_3[0] & 0xfc) >> 2;
			char_array_4[1]=((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2]=((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3]=char_array_3[2] & 0x3f;

			for(i=0; (i<4); i++)
			{
				ret+=base64_chars[char_array_4[i]];
			}
			i=0;
		}
	}

	//if Word not full, append padding
	if(i!=0)
	{
		for(j=i; j<3; j++)
		{
			char_array_3[j]='\0';
		}

		char_array_4[0]=(char_array_3[0] & 0xfc) >> 2;
		char_array_4[1]=((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2]=((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3]=char_array_3[2] & 0x3f;

		for(j=0; j<i+1; j++)
		{
			ret+=base64_chars[char_array_4[j]];
		}

		while(i++<3)
		{
			ret+='=';
		}
	}

	return ret;
}

// FUNCTION   : std::string base64Decode(std::string)
// DESCRIPTION: deencode a string from base64 to 8-bit
// PARAMETERS : std::string to be decoded
// RETURNS    : decoded std::string of input data
std::string base64Decode(std::string encoded_string)
{
	uint32 in_len=encoded_string.size();
	uint32 i=0;
	uint32 j=0;
	uint32 in_=0;
	uint8 char_array_4[4], char_array_3[3];
	std::string ret;

	//decode string
	while(in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
	{
		char_array_4[i++]=encoded_string[in_];
		in_++;

		if(i==4)
		{
			for(i=0; i<4; i++)
			{
				char_array_4[i]=base64_chars.find(char_array_4[i]);
			}
			char_array_3[0]=(char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1]=((char_array_4[1] & 0xf) << 4)+((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2]=((char_array_4[2] & 0x3) << 6)+char_array_4[3];

			for(i=0; i<3; i++)
			{
				ret+=char_array_3[i];
			}
			i=0;
		}
	}

	//handle padding if neccessary
	if(i!=0)
	{
		for(j=i; j<4; j++)
		{
			char_array_4[j]=0;
		}

		for(j=0; j<4; j++)
		{
			char_array_4[j]=base64_chars.find(char_array_4[j]);
		}

		char_array_3[0]=(char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1]=((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2]=((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for(j=0; j<i-1; j++)
		{
			ret+=char_array_3[j];
		}
	}

	return ret;
}
