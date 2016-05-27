#ifndef	_CUSTOM_TYPES_H_
#define _CUSTOM_TYPES_H_

//unsigned unlimited fixpoint variable
//Note: size of data type limits key length!

//use big integer library such as https://mattmccutchen.net/bigint/
//author: Matt McCutchen <matt@mattmccutchen.net>
//license: public domain,
//repository: https://mattmccutchen.net/bigint/bigint.git/
//mirror: http://repo.or.cz/w/bigint.git
#include "bigint/BigIntegerLibrary.h"
typedef BigUnsigned uintInfinite;

// data structure for binary data
#include "dataString.h"

#endif /* _CUSTOM_TYPES_H_ */
