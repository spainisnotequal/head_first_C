/*
 * Program to encrypt a message applying an XOR encryption with the number 31
 */

#include <stdio.h>
#include "encrypt.h"

int main()
{
        char msg[80];
        while (fgets(msg, 80, stdin)) {
                encrypt(msg);
                printf("%s\n", msg);
        }
        
        return 0;
}
