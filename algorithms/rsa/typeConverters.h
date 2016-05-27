#ifndef	_TYPECONVERTERS_H_
#define _TYPECONVERTERS_H_

// DESCRIPTION: convert a unsigned integer value to a dataString
// PARAMETERS : unsigned integer value
// RETURNS    : dataString representation of input data
// COMMENT    : allocates new memory, ensure deallocation
dataString uint16_to_dataString(uint16);
dataString uint32_to_dataString(uint32);
dataString uint64_to_dataString(uint64);
dataString string_to_dataString(std::string);
char* string_to_charString(std::string);


// DESCRIPTION: convert a unsigned integer value to a std::string
// PARAMETERS : unsigned integer value
// RETURNS    : std::string representation of input data
std::string uint16_to_string(uint16);
std::string uint32_to_string(uint32);
std::string uint64_to_string(uint64);
std::string dataString_to_string(dataString);
std::string uintInfinite_to_string(uintInfinite);

// DESCRIPTION: convert a string to a uintInfinite value
// PARAMETERS : string to be converted
// RETURNS    : uintInfinite representation of input data
uintInfinite string_to_uintInfinite(std::string);
uintInfinite dataString_to_uintInfinite(dataString);

// DESCRIPTION: convert the newlines of a string between windows and unix-style
// PARAMETERS : std::string to be modified
// RETURNS    : std::string with modified newline
std::string convertNewline2Unix(std::string);
std::string convertNewline2Win(std::string);

#endif /* _TYPECONVERTERS_H_ */
