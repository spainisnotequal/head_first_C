/*
 * Program to learn about memory padding when using structures
 */

#include <stdio.h>

struct ASCII {
        const char caracter;
        int code;
};

int main()
{
        printf("sizeof(struct ASCII) = %zu\n", sizeof(struct ASCII));
        printf("sizeof(const char) + sizeof(int) = %zu\n",
               sizeof(const char) + sizeof(int));
        
        return 0;
}
