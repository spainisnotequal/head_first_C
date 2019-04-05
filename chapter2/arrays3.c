/*
 * Program to see different syntax to access arrays
 */

#include <stdio.h>

int main ()
{
        int v[] = {1, 9, -3, 0, 8};

        printf("v[2] = %i\n", v[2]);
        printf("v[2] = %i\n", *(v + 2));
        printf("v[2] = %i\n", *(2 + v));
        printf("v[2] = %i\n", 2[v]); // I don't like this way...
        
        return 0;
}
