#ifndef	_SHA2_H_
#define _SHA2_H_

typedef struct sha2_sha224Hash
{
	uint32 a;
	uint32 b;
	uint32 c;
	uint32 d;
	uint32 e;
	uint32 f;
	uint32 g;
} sha2_sha224Hash;

typedef struct sha2_sha256Hash
{
	uint32 a;
	uint32 b;
	uint32 c;
	uint32 d;
	uint32 e;
	uint32 f;
	uint32 g;
	uint32 h;
} sha2_sha256Hash;

typedef struct sha2_sha384Hash
{
	uint64 a;
	uint64 b;
	uint64 c;
	uint64 d;
	uint64 e;
	uint64 f;
} sha2_sha384Hash;

typedef struct sha2_sha512Hash
{
	uint64 a;
	uint64 b;
	uint64 c;
	uint64 d;
	uint64 e;
	uint64 f;
	uint64 g;
	uint64 h;
} sha2_sha512Hash;

sha2_sha224Hash sha2_sha224(uint8*, uint64);
sha2_sha256Hash sha2_sha256(uint8*, uint64);
sha2_sha384Hash sha2_sha384(uint8*, uint128);
sha2_sha512Hash sha2_sha512(uint8*, uint128);

#endif /* _SHA2_H_ */
