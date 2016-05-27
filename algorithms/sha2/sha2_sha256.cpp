#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "sha2_sha256helper.h"
#include "sha2.h"

//see FIPS 180-3

//SHA-256
sha2_sha256Hash sha2_sha256(uint8* data, uint64 len)
{
	//initial hash values
	sha2_sha256Hash H;
	H.a=sha2_sha256Values[0];
	H.b=sha2_sha256Values[1];
	H.c=sha2_sha256Values[2];
	H.d=sha2_sha256Values[3];
	H.e=sha2_sha256Values[4];
	H.f=sha2_sha256Values[5];
	H.g=sha2_sha256Values[6];
	H.h=sha2_sha256Values[7];

	//working variables
	uint32 a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;

	//temporary words
	uint32 T1=0, T2=0;

	//words of the message schedule
	const uint8 Wlength=64;
	uint32 W[Wlength];
	uint32 M[16];

	//message length
	uint32 highlength=(uint32)((len*8)>>sizeof(uint32)*8);
	uint32 lowlength=(uint32)(len*8);

	//number of message blocks
	//length in byte + padding byte + length field
	uint64 N=len + 1 + sizeof(uint64);

	//loop counters
	uint64 i=0;
	uint8 t=0, byte=0; 

	while(i<=N)
	{
		//step 0: padding
		for(t=0; t<16; t++)
		{
			//clear M
			M[t]=0;

			//write length words in last block
			if(t==15 && i>=N)
			{
				//write high word
				M[14]=highlength;
				//write low word
				M[15]=lowlength;
			}
			//write message chars	
			for(byte=0; byte<sizeof(uint32); byte++)
			{		
				//write char
				if(i<len)
				{
					M[t]<<=8;
					M[t]+=data[i];
				}

				//write padding bit
				if(i==len)
				{
					M[t]<<=8;
					M[t]+=0x80;

					while(byte<sizeof(uint32)-1)
					{	
						M[t]<<=8;
						byte++;
					}
				}
				//next char
				i++;
			}
		}

		//step 1: Prepare the message schedule
		for(t=0; t<Wlength; t++)
		{
			if(t<16)
			{
				W[t]=M[t];
			}
			else
			{
				W[t]=sha2_lowerSigma1(W[t-2]) + W[t-7] + sha2_lowerSigma0(W[t-15]) + W[t-16];
			}
		}

		//step 2: Initialize the eight working variables
		a=H.a;
		b=H.b;
		c=H.c;
		d=H.d;
		e=H.e;
		f=H.f;
		g=H.g;
		h=H.h;

		//step 3:
		for(t=0; t<Wlength; t++)
		{
			T1=h + sha2_upperSigma1(e) + sha2_Ch(e, f, g) + sha2_sha256Constants[t] + W[t];
			T2=sha2_upperSigma0(a) + sha2_Maj(a, b, c);
			h=g;
			g=f;
			f=e;
			e=d+T1;
			d=c;
			c=b;
			b=a;
			a=T1+T2;
		}

		//step 4: Compute the i. intermediate hash value H(i)
		H.a+=a;
		H.b+=b;
		H.c+=c;
		H.d+=d;
		H.e+=e;
		H.f+=f;
		H.g+=g;
		H.h+=h;
	}

	return H;
}

sha2_sha224Hash sha2_sha224(uint8* data, uint64 len)
{
	//initial hash values
	sha2_sha256Hash H;
	H.a=sha2_sha224Values[0];
	H.b=sha2_sha224Values[1];
	H.c=sha2_sha224Values[2];
	H.d=sha2_sha224Values[3];
	H.e=sha2_sha224Values[4];
	H.f=sha2_sha224Values[5];
	H.g=sha2_sha224Values[6];
	H.h=sha2_sha224Values[7];

	//working variables
	uint32 a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;

	//temporary words
	uint32 T1=0, T2=0;

	//words of the message schedule
	const uint8 Wlength=64;
	uint32 W[Wlength];
	uint32 M[16];

	//message length
	uint32 highlength=(uint32)((len*8)>>sizeof(uint32)*8);
	uint32 lowlength=(uint32)(len*8);

	//number of message blocks
	//length in byte + padding byte + length field
	uint64 N=len + 1 + sizeof(uint64);

	//loop counters
	uint64 i=0;
	uint8 t=0, byte=0; 

	while(i<=N)
	{
		//step 0: padding
		for(t=0; t<16; t++)
		{
			//clear M
			M[t]=0;

			//write length words in last block
			if(t==15 && i>=N)
			{
				//write high word
				M[14]=highlength;
				//write low word
				M[15]=lowlength;
			}
			//write message chars	
			for(byte=0; byte<sizeof(uint32); byte++)
			{		
				//write char
				if(i<len)
				{
					M[t]<<=8;
					M[t]+=data[i];
				}

				//write padding bit
				if(i==len)
				{
					M[t]<<=8;
					M[t]+=0x80;

					while(byte<sizeof(uint32)-1)
					{	
						M[t]<<=8;
						byte++;
					}
				}
				//next char
				i++;
			}
		}

		//step 1: Prepare the message schedule
		for(t=0; t<Wlength; t++)
		{
			if(t<16)
			{
				W[t]=M[t];
			}
			else
			{
				W[t]=sha2_lowerSigma1(W[t-2]) + W[t-7] + sha2_lowerSigma0(W[t-15]) + W[t-16];
			}
		}

		//step 2: Initialize the eight working variables
		a=H.a;
		b=H.b;
		c=H.c;
		d=H.d;
		e=H.e;
		f=H.f;
		g=H.g;
		h=H.h;

		//step 3:
		for(t=0; t<Wlength; t++)
		{
			T1=h + sha2_upperSigma1(e) + sha2_Ch(e, f, g) + sha2_sha256Constants[t] + W[t];
			T2=sha2_upperSigma0(a) + sha2_Maj(a, b, c);
			h=g;
			g=f;
			f=e;
			e=d+T1;
			d=c;
			c=b;
			b=a;
			a=T1+T2;
		}

		//step 4: Compute the i. intermediate hash value H(i)
		H.a+=a;
		H.b+=b;
		H.c+=c;
		H.d+=d;
		H.e+=e;
		H.f+=f;
		H.g+=g;
		H.h+=h;
	}

	sha2_sha224Hash result;
	result.a=H.a;
	result.b=H.b;
	result.c=H.c;
	result.d=H.d;
	result.e=H.e;
	result.f=H.f;
	result.g=H.g;

	return result;
}
