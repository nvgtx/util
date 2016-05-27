#ifndef	_DATASTRING_H_
#define _DATASTRING_H_

// DESCRIPTION: string structure for binary data
// COMMENT    : binary data could contain \0 bytes
//              use the length value for termination
struct dataString
{
	unsigned long length;
	char* data; //do not rely on \0 termination !!!
};
typedef struct dataString dataString;

#endif /* _DATASTRING_H_ */
