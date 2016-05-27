#include <iostream>
#include <string>
#include <stdio.h>

#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "rsaTestKey.h"
#include "rsaAlgorithm.h"
#include "typeConverters.h"
#include "base64.h"
#include "rsaTests.h"

void rsaTests()
{
	testRsaSmallKey();
	testRsaSampleKey();
}

//check algorithm with a small key
int testRsaSmallKey()
{
	//message
	uintInfinite message=		123;
	//modulo
	uintInfinite modulo=		3233;
	//public key
	uintInfinite encryptionexp=	17;
	//secret key
	uintInfinite decryptionexp=	2753;

	uintInfinite encmsg=		0;
	uintInfinite decmsg=		0;
	std::string str="";

	//clear-text
	std::cout<<"RSA: check with small key"<<std::endl;

	if(message>modulo)
	{
		printf("ERROR: Key too short\n");
		getchar();
		return(-1);
	}

	//cleartext
	str=uintInfinite_to_string(message);
	std::cout<<"Cleartext: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	//encrypted
	encmsg=rsaEncrypt(message, encryptionexp, modulo);
	str=uintInfinite_to_string(encmsg);
	std::cout<<"Encrypted: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	//decrypted
	decmsg=rsaEncrypt(encmsg, decryptionexp, modulo);
	str=uintInfinite_to_string(decmsg);
	std::cout<<"Decrypted: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	std::cout<<std::endl;
}

int testRsaSampleKey()
{
	//message
	uintInfinite message=		(uint32)0x01020304;
	//modulo
	uintInfinite modulo=		0;
	//public key
	uintInfinite encryptionexp=	0;
	//secret key
	uintInfinite decryptionexp=	0;

	uintInfinite encmsg=		0;
	uintInfinite decmsg=		0;
	std::string str="";

	uintInfinite tmp=0;
	for (int i=0; i<dLength; i++)
	{
		tmp<<=8;
		tmp|=dKey[i];
	}
	decryptionexp=tmp;

	tmp=0;
	for (int i=0; i<eLength; i++)
	{
		tmp<<=8;
		tmp|=eKey[i];
	}
	encryptionexp=tmp;


	tmp=0;
	for (int i=0; i<nLength; i++)
	{
		tmp<<=8;
		tmp|=nKey[i];
	}
	modulo=tmp;

	//clear-text
	std::cout<<"RSA: check with sample key"<<std::endl;

	if(message>modulo)
	{
		printf("ERROR: Key too short\n");
		getchar();
		return(-1);
	}

	//cleartext
	str=uintInfinite_to_string(message);
	std::cout<<"Cleartext: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	//encrypted
	encmsg=rsaEncrypt(message, encryptionexp, modulo);
	str=uintInfinite_to_string(encmsg);
	std::cout<<"Encrypted: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	//decrypted
	decmsg=rsaEncrypt(encmsg, decryptionexp, modulo);
	str=uintInfinite_to_string(decmsg);
	std::cout<<"Decrypted: "<<base64Encode((uint8*)str.c_str(), str.length())<<std::endl;

	std::cout<<std::endl;
}
