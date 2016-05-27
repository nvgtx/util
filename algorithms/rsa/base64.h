#ifndef	_BASE64_H_
#define _BASE64_H_

// DESCRIPTION: base64 raplacement characters
static const std::string base64_chars="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// FUNCTION   : std::string base64Encode(const uint8*, uint32)
// DESCRIPTION: encode a string in base64
// PARAMETERS : unsigned character string to be encoded
//              unsigned length value of string
// RETURNS    : base64 encoded std::string of input data
// COMMENT    : cast from char* to uint8* if neccesary
std::string base64Encode(const uint8*, uint32);

// FUNCTION   : std::string base64Decode(std::string)
// DESCRIPTION: deencode a string from base64 to 8-bit
// PARAMETERS : std::string to be decoded
// RETURNS    : decoded std::string of input data
std::string base64Decode(std::string);

// FUNCTION   : bool is_base64(uint8)
// DESCRIPTION: check if character is a valid base64 value
// PARAMETERS : character to be checked
// RETURNS    : boolean value, true if valid
bool is_base64(uint8);

#endif /* _BASE64_H_ */
