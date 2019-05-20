/*
 * Encrypt a message applying an XOR encryption with the number 31
 */

#include "encrypt.h"


void encrypt (char *message)
{
        while (*message) {
                *message = *message ^ 31;
                message++;
        }
}
