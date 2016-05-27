#include "../../standard_types/standard_types.h"
#include "custom_types.h"
#include "sha2_tests.h"

int main()
{
	sha2_sha224Tests();
	sha2_sha256Tests();
	sha2_sha384Tests();
	sha2_sha512Tests();

	return 0;
}

