/*
 * Program to print the size of different data types
 */

#include <stdio.h>

int main ()
{
        //Integers
        char  a;
        short b;
        int   c;
        long  d;

        printf("\nThe size of the interger 'char' data type is:  %zu bytes\n", sizeof a);
        printf("The size of the interger 'short' data type is: %zu bytes\n", sizeof b);
        printf("The size of the interger 'int' data type is:   %zu bytes\n", sizeof c);
        printf("The size of the interger 'long' data type is:  %zu bytes\n", sizeof d);

        //Floating points
        float  e;
        double f;
        
        printf("\nThe size of the floating point 'float' data type is:  %zu bytes\n", sizeof e);
        printf("The size of the floating point 'double' data type is: %zu bytes\n", sizeof f);

        // Other numbers: unsigned, long
        unsigned int g;
        long int h;
        long long i;
        long double j;

        printf("\nThe size of the interger 'unsigned int' data type is:      %zu bytes\n", sizeof g);
        printf("The size of the interger 'long int' data type is:          %zu bytes\n", sizeof h);
        printf("The size of the interger 'long long' data type is:         %zu bytes\n", sizeof i);
        printf("The size of the floating point 'long double' data type is: %zu bytes\n", sizeof j);
        
        return 0;
}
