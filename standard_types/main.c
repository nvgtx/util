#include <stdbool.h>
#include <stdio.h>

#include "standard_types.h"

bool typeassert(unsigned int detectedsize, unsigned int expectedsize)
{
	if(detectedsize==expectedsize)
	{
		printf("true\n");
		return true;
	}
	else
	{
		printf("false\texpected size %i, detected size: %i\n", expectedsize, detectedsize);
		return false;
	}	
}

int main()
{
	printf("Checking size of fixpoint data types\n");
	printf("uint8:\t");
	typeassert(sizeof(uint8), 1);
	printf("uint16:\t");
	typeassert(sizeof(uint16), 2);
	printf("uint32:\t");
	typeassert(sizeof(uint32), 4);
	printf("uint64:\t");
	typeassert(sizeof(uint64), 8);
	printf("sint8:\t");
	typeassert(sizeof(uint8), 1);
	printf("sint16:\t");
	typeassert(sizeof(uint16), 2);
	printf("sint32:\t");
	typeassert(sizeof(uint32), 4);
	printf("sint64:\t");
	typeassert(sizeof(uint64), 8);
	
	return 0;
}

