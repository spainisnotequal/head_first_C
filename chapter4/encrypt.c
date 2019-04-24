/*
 * Encrypt a message applying an XOR encryption with the number 31
 */

#include "encrypt.h" // Although it is not strictily necessary to include the
                     // header in the corresponding source file, it's a very
                     // good defensive programming technique, because in doing
                     // so, the compiler checks that the function's declarations
                     // in the header file and the function's definition in the
                     // source file are consistent; otherwise, the compiler will
                     // throw a warning or error

void encrypt (char *message)
{
        while (*message) {
                *message = *message ^ 31;
                message++;
        }
}
