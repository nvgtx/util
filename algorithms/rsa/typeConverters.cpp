#include <string>

#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "typeConverters.h"

// FUNCTION   : dataString uint16_to_dataString(uint16)
// DESCRIPTION: convert a 16-bit value to a dataString
// PARAMETERS : 16-bit unsigned integer value
// RETURNS    : dataString representation of input data
// COMMENT    : allocates new memory, ensure deallocation
dataString uint16_to_dataString(uint16 val)
{
	dataString res;
	res.length=sizeof(uint16);
	res.data=new char[sizeof(uint16)+1];

	uint8 i=0;
	for(i=sizeof(uint16); i>0; i--)
	{
		res.data[i-1]=(uint8)val;
		val>>=sizeof(uint8)*8;
	}

	//write \0 byte
	res.data[res.length]=0;

	return res;
}

// FUNCTION   : dataString uint32_to_dataString(uint32)
// DESCRIPTION: convert a 32-bit value to a dataString
// PARAMETERS : 32-bit unsigned integer value
// RETURNS    : dataString representation of input data
// COMMENT    : allocates new memory, ensure deallocation
dataString uint32_to_dataString(uint32 val)
{
	dataString res;
	res.length=sizeof(uint32);
	res.data=new char[sizeof(uint32)+1];

	uint8 i=0;
	for(i=sizeof(uint32); i>0; i--)
	{
		res.data[i-1]=(uint8)val;
		val>>=sizeof(uint8)*8;
	}

	//write \0 byte
	res.data[res.length]=0;

	return res;
}

// FUNCTION   : dataString uint64_to_dataString(uint64)
// DESCRIPTION: convert a 64-bit value to a dataString
// PARAMETERS : 64-bit unsigned integer value
// RETURNS    : dataString representation of input data
// COMMENT    : allocates new memory, ensure deallocation
dataString uint64_to_dataString(uint64 val)
{
	dataString res;
	res.length=sizeof(uint64);
	res.data=new char[sizeof(uint64)+1];

	uint8 i=0;
	for(i=sizeof(uint64); i>0; i--)
	{
		res.data[i-1]=(uint8)val;
		val>>=sizeof(uint8)*8;
	}

	//write \0 byte
	res.data[res.length]=0;

	return res;
}

// FUNCTION   : dataString string_to_dataString(std::string)
// DESCRIPTION: convert a std::string to a dataString
// PARAMETERS : std::string
// RETURNS    : dataString representation of input data
// COMMENT    : allocates new memory, ensure deallocation
dataString string_to_dataString(std::string val)
{
	dataString res;
	res.length=val.length();
	res.data=new char[res.length+1];

	uint32 i=0;
	for(i=0; i<res.length; i++)
	{
		res.data[i]=val[i];
	}

	//write \0 byte
	res.data[res.length]=0;

	return res;
}

// FUNCTION   : char* string_to_charString(std::string)
// DESCRIPTION: convert a std::string to a char* string
// PARAMETERS : std::string
// RETURNS    : char* representation of input data
// COMMENT    : allocates new memory, ensure deallocation
char* string_to_charString(std::string val)
{
	return string_to_dataString(val).data;
}

// FUNCTION   : std::string uint16_to_string(uint16)
// DESCRIPTION: convert a 16-bit value to a std::string
// PARAMETERS : 16-bit unsigned integer value
// RETURNS    : std::string representation of input data
std::string uint16_to_string(uint16 val)
{
	std::string str="";
	dataString tmp;

	tmp=uint16_to_dataString(val);
	str+=dataString_to_string(tmp);
	delete[] tmp.data;

	return str;
}

// FUNCTION   : std::string uint32_to_string(uint32)
// DESCRIPTION: convert a 32-bit value to a std::string
// PARAMETERS : 32-bit unsigned integer value
// RETURNS    : std::string representation of input data
std::string uint32_to_string(uint32 val)
{
	std::string str="";
	dataString tmp;

	tmp=uint32_to_dataString(val);
	str+=dataString_to_string(tmp);
	delete[] tmp.data;

	return str;
}

// FUNCTION   : std::string uint64_to_string(uint16)
// DESCRIPTION: convert a 64-bit value to a std::string
// PARAMETERS : 64-bit unsigned integer value
// RETURNS    : std::string representation of input data
std::string uint64_to_string(uint64 val)
{
	std::string str="";
	dataString tmp;

	tmp=uint64_to_dataString(val);
	str+=dataString_to_string(tmp);
	delete[] tmp.data;

	return str;
}

// FUNCTION   : std::string dataString_to_string(dataString)
// DESCRIPTION: convert a dataString to a std::string
// PARAMETERS : dataString
// RETURNS    : std::string representation of input data
std::string dataString_to_string(dataString val)
{
	std::string res="";
	uint64 i=0;
	for(i=0; i<val.length; i++)
	{
		res+=val.data[i];
	}
	return res;
}

// FUNCTION   : std::string uintInfinite_to_string(uintInfinite)
// DESCRIPTION: convert a uintInfinite value to a std::string
// PARAMETERS : unsigned integer value with unlimited length
// RETURNS    : std::string representation of input data
std::string uintInfinite_to_string(uintInfinite val)
{
	std::string str="";

	uint8 byte=0;
	uint32 i, r;

	//read lowest byte
	while(val>0)
	{
		byte=0;
		for(i=0; i<8; i++)
		{
			byte<<=1;
			byte|=(uint8)val.getBit(i);
		}
		val>>=8;
		str+=byte;
	}

	//reverse binary order
	for(i=0; i<str.length(); i++)
	{
		byte=0;
		r=0;
		while(r<(sizeof(char)*8))
		{
			byte=(byte <<1) + (str[i] & 0x1); 
			str[i]>>=1;

			r++;
		}
		str[i]=byte;
	}

	//reverse bytes
	for(i=0, r=str.length()-1; i<r; i++, r--)
	{
		byte=str[i];
		str[i]=str[r];
		str[r]=byte;
	}

	return str;
}

// FUNCTION   : uintInfinite string_to_uintInfinite(std::string)
// DESCRIPTION: convert a std::string to a uintInfinite value
// PARAMETERS : std::string to be converted
// RETURNS    : uintInfinite representation of input data
uintInfinite string_to_uintInfinite(std::string str)
{
	uintInfinite result=0;
	uint32 i=0;

	for(i=0; i<str.length(); i++)
	{
		result<<=sizeof(uint8)*8;
		result|=(uint8)str[i];
	}
	return result;
}

// FUNCTION   : uintInfinite dataString_to_uintInfinite(dataString str)
// DESCRIPTION: convert a dataString to a uintInfinite value
// PARAMETERS : dataString to be converted
// RETURNS    : uintInfinite representation of input data
uintInfinite dataString_to_uintInfinite(dataString str)
{
	uintInfinite result=0;
	uint64 i=0;

	for(i=0; i<str.length; i++)
	{
		result<<=sizeof(uint8)*8;
		result|=(uint8)str.data[i];
	}
	return result;
}

// FUNCTION   : std::string convertNewline2Unix(std::string)
// DESCRIPTION: convert windows-style newlines to unix-style
// PARAMETERS : std::string to be modified
// RETURNS    : std::string with modified newline
std::string convertNewline2Unix(std::string str)
{
	std::string result="";
	uint32 i=0;
	for(i=0; i<str.length(); i++)
	{
		//drop \r
		if(str[i]!='\r')
		{
			result+=str[i];
		}
	}
	return result;
}

// FUNCTION   : std::string convertNewline2Win(std::string)
// DESCRIPTION: convert unix-style newlines to windows-style
// PARAMETERS : std::string to be modified
// RETURNS    : std::string with modified newline
std::string convertNewline2Win(std::string str)
{
	std::string result="";
	uint32 i=0;
	for(i=0; i<str.length(); i++)
	{
		//drop \r
		if(str[i]!='\r')
		{
			//if \n: write \r\n
			if(str[i]=='\n')
			{
				result+='\r';
				result+='\n';
			}
			else
			{
				result+=str[i];
			}
		}
	}
	return result;
}
