#ifndef	_RSAALGORITHM_H_
#define _RSAALGORITHM_H_

// FUNCTION   : uintInfinite rsaEncrypt(uintInfinite msg, uintInfinite exp, uintInfinite n)
// DESCRIPTION: use the RSA encryption algoritm on a input value
// PARAMETERS : uintInfinite msg - the value to be encrypted, decrypted or signed
//              uintInfinite exp - the exponent value of the public or secret key
//              uintInfinite n   - the modulo value of the key
// RETURNS    : encrypted, decrypted or signed uintInfinite value
// COMMENT    : same function for encryption and decryption,
//              public key encrypts and validates, secret key decrypts and signs
uintInfinite rsaEncrypt(uintInfinite, uintInfinite, uintInfinite);

#endif /* _RSAALGORITHM_H_ */
