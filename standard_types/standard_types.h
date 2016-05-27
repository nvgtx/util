#ifndef	_STANDARD_TYPES_H_
#define _STANDARD_TYPES_H_

#ifndef _STANDALONE_
//fixpoint integer types
#include <stdint.h>
//unsigned 8-bit fixpoint type
typedef uint8_t            uint8;
//unsigned 16-bit fixpoint type
typedef uint16_t           uint16;
//unsigned 32-bit fixpoint type
typedef uint32_t           uint32;
//unsigned 64-bit fixpoint type
typedef uint64_t           uint64;
//signed 8-bit fixpoint type
typedef int8_t             sint8;
//signed 16-bit fixpoint type
typedef int16_t            sint16;
//signed 32-bit fixpoint type
typedef int32_t            sint32;
//signed 64-bit fixpoint type
typedef int64_t            sint64;

#else
//if C standard library is not available, use these:
//unsigned 8-bit fixpoint type
typedef unsigned char      uint8;
//unsigned 16-bit fixpoint type
typedef unsigned short     uint16;
//unsigned 32-bit fixpoint type
typedef unsigned int       uint32;
//unsigned 64-bit fixpoint type
typedef unsigned long long uint64;

//signed 8-bit fixpoint type
typedef signed char        sint8;
//signed 16-bit fixpoint type
typedef signed short       sint16;
//signed 32-bit fixpoint type
typedef signed int         sint32;
//signed 64-bit fixpoint type
typedef signed long long   sint64;
#endif

//standard precision floatingpoint type
typedef double             sfloat;
//extended precision floatingpoint type
typedef long double        efloat;

//character string type
typedef char*              string;
//boolean type
typedef bool               boolean;

#endif /* _STANDARD_TYPES_H_ */

