#include <iostream>
#include <string>
#include <iomanip>

#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "sha2.h"
#include "sha2_tests.h"

void shaTests()
{
	sha2_sha224Tests();
	sha2_sha256Tests();
	sha2_sha384Tests();
	sha2_sha512Tests();
}

void sha2_sha224Tests()
{
	sha2_sha224Hash hash224;

	std::string msg1="abc";
	std::string msg2="abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
	std::string msg3="";
	for(unsigned long i=0; i<1000000; i++){msg3+="a";}

	hash224=sha2_sha224((uint8*)msg1.c_str(), msg1.length());
	std::cout<<"SHA-224 "<<msg1<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash224.a<<" "<<hash224.b<<" "<<hash224.c<<" "<<hash224.d<<" "<<hash224.e<<" "<<hash224.f<<" "<<hash224.g<<std::endl;
	std::cout<<"soll: 23097d22 3405d822 8642a477 bda255b3 2aadbce4 bda0b3f7 e36c9da7"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash224=sha2_sha224((uint8*)msg2.c_str(), msg2.length());
	std::cout<<"SHA-224 "<<msg2<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash224.a<<" "<<hash224.b<<" "<<hash224.c<<" "<<hash224.d<<" "<<hash224.e<<" "<<hash224.f<<" "<<hash224.g<<std::endl;
	std::cout<<"soll: 75388b16 512776cc 5dba5da1 fd890150 b0c6455c b4f58b19 52522525"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash224=sha2_sha224((uint8*)msg3.c_str(), msg3.length());
	std::cout<<"SHA-224 "<<std::dec<<msg3.length()<<" * a"<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash224.a<<" "<<hash224.b<<" "<<hash224.c<<" "<<hash224.d<<" "<<hash224.e<<" "<<hash224.f<<" "<<hash224.g<<std::endl;
	std::cout<<"soll: 20794655 980c91d8 bbb4c1ea 97618a4b f03f4258 1948b2ee 4ee7ad67"<<std::endl;

	std::cout<<std::endl<<std::endl;
}

void sha2_sha256Tests()
{
	sha2_sha256Hash hash256;

	std::string msg1="abc";
	std::string msg2="abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
	std::string msg3="";
	for(unsigned long i=0; i<1000000; i++){msg3+="a";}

	hash256=sha2_sha256((uint8*)msg1.c_str(), msg1.length());
	std::cout<<"SHA-256 "<<msg1<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash256.a<<" "<<hash256.b<<" "<<hash256.c<<" "<<hash256.d<<" "<<hash256.e<<" "<<hash256.f<<" "<<hash256.g<<" "<<hash256.h<<std::endl;
	std::cout<<"soll: ba7816bf 8f01cfea 414140de 5dae2223 b00361a3 96177a9c b410ff61 f20015ad"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash256=sha2_sha256((uint8*)msg2.c_str(), msg2.length());
	std::cout<<"SHA-256 "<<msg2<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash256.a<<" "<<hash256.b<<" "<<hash256.c<<" "<<std::setw(8)<<std::setfill('0')<<hash256.d<<" "<<hash256.e<<" "<<hash256.f<<" "<<hash256.g<<" "<<hash256.h<<std::endl;
	std::cout<<"soll: 248d6a61 d20638b8 e5c02693 0c3e6039 a33ce459 64ff2167 f6ecedd4 19db06c1"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash256=sha2_sha256((uint8*)msg3.c_str(), msg3.length());
	std::cout<<"SHA-256 "<<std::dec<<msg3.length()<<" * a"<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash256.a<<" "<<hash256.b<<" "<<hash256.c<<" "<<hash256.d<<" "<<hash256.e<<" "<<std::setw(8)<<std::setfill('0')<<hash256.f<<" "<<std::setw(8)<<std::setfill('0')<<hash256.g<<" "<<hash256.h<<std::endl;
	std::cout<<"soll: cdc76e5c 9914fb92 81a1c7e2 84d73e67 f1809a48 a497200e 046d39cc c7112cd0"<<std::endl;

	std::cout<<std::endl<<std::endl;
}

void sha2_sha384Tests()
{
	sha2_sha384Hash hash384;

	std::string msg1="abc";
	std::string msg2="abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
	std::string msg3="";
	for(unsigned long i=0; i<1000000; i++){msg3+="a";}

	hash384=sha2_sha384((uint8*)msg1.c_str(), msg1.length());
	std::cout<<"SHA-384 "<<msg1<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash384.a<<" "<<hash384.b<<" "<<hash384.c<<" "<<hash384.d<<std::endl;
	std::cout<<"soll: cb00753f45a35e8b b5a03d699ac65007 272c32ab0eded163 1a8b605a43ff5bed"<<std::endl;
	std::cout<<"ist:  "<<hash384.e<<" "<<hash384.f<<std::endl;
	std::cout<<"soll: 8086072ba1e7cc23 58baeca134c825a7"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash384=sha2_sha384((uint8*)msg2.c_str(), msg2.length());
	std::cout<<"SHA-384 "<<msg2<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<std::setw(16)<<std::setfill('0')<<hash384.a<<" "<<hash384.b<<" "<<hash384.c<<" "<<hash384.d<<std::endl;
	std::cout<<"soll: 09330c33f71147e8 3d192fc782cd1b47 53111b173b3b05d2 2fa08086e3b0f712"<<std::endl;
	std::cout<<"ist:  "<<hash384.e<<" "<<hash384.f<<std::endl;
	std::cout<<"soll: fcc7c71a557e2db9 66c3e9fa91746039"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash384=sha2_sha384((uint8*)msg3.c_str(), msg3.length());
	std::cout<<"SHA-384 "<<std::dec<<msg3.length()<<" * a"<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash384.a<<" "<<std::setw(16)<<std::setfill('0')<<hash384.b<<" "<<hash384.c<<" "<<hash384.d<<std::endl;
	std::cout<<"soll: 9d0e1809716474cb 086e834e310a4a1c ed149e9c00f24852 7972cec5704c2a5b"<<std::endl;
	std::cout<<"ist:  "<<std::setw(16)<<std::setfill('0')<<hash384.e<<" "<<hash384.f<<std::endl;
	std::cout<<"soll: 07b8b3dc38ecc4eb ae97ddd87f3d8985"<<std::endl;

	std::cout<<std::endl<<std::endl;
}

void sha2_sha512Tests()
{
	sha2_sha512Hash hash512;

	std::string msg1="abc";
	std::string msg2="abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
	std::string msg3="";
	for(unsigned long i=0; i<1000000; i++){msg3+="a";}

	hash512=sha2_sha512((uint8*)msg1.c_str(), msg1.length());
	std::cout<<"SHA-512 "<<msg1<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash512.a<<" "<<hash512.b<<" "<<hash512.c<<" "<<std::setw(16)<<std::setfill('0')<<hash512.d<<std::endl;
	std::cout<<"soll: ddaf35a193617aba cc417349ae204131 12e6fa4e89a97ea2 0a9eeee64b55d39a"<<std::endl;
	std::cout<<"ist:  "<<hash512.e<<" "<<hash512.f<<" "<<hash512.g<<" "<<hash512.h<<std::endl;
	std::cout<<"soll: 2192992a274fc1a8 36ba3c23a3feebbd 454d4423643ce80e 2a9ac94fa54ca49f"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash512=sha2_sha512((uint8*)msg2.c_str(), msg2.length());
	std::cout<<"SHA-512 "<<msg2<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash512.a<<" "<<hash512.b<<" "<<hash512.c<<" "<<hash512.d<<std::endl;
	std::cout<<"soll: 8e959b75dae313da 8cf4f72814fc143f 8f7779c6eb9f7fa1 7299aeadb6889018"<<std::endl;
	std::cout<<"ist:  "<<hash512.e<<" "<<hash512.f<<" "<<hash512.g<<" "<<hash512.h<<std::endl;
	std::cout<<"soll: 501d289e4900f7e4 331b99dec4b5433a c7d329eeb6dd2654 5e96e55b874be909"<<std::endl;

	std::cout<<std::endl<<std::endl;

	hash512=sha2_sha512((uint8*)msg3.c_str(), msg3.length());
	std::cout<<"SHA-512 "<<std::dec<<msg3.length()<<" * a"<<std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout<<"ist:  "<<hash512.a<<" "<<hash512.b<<" "<<hash512.c<<" "<<hash512.d<<std::endl;
	std::cout<<"soll: e718483d0ce76964 4e2e42c7bc15b463 8e1f98b13b204428 5632a803afa973eb"<<std::endl;
	std::cout<<"ist:  "<<hash512.e<<" "<<hash512.f<<" "<<hash512.g<<" "<<hash512.h<<std::endl;
	std::cout<<"soll: de0ff244877ea60a 4cb0432ce577c31b eb009c5c2c49aa2e 4eadb217ad8cc09b"<<std::endl;

	std::cout<<std::endl<<std::endl;
}
