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

        printf("The size of the interger 'char' data type is:  %zu bytes\n", sizeof a);
        printf("The size of the interger 'short' data type is: %zu bytes\n", sizeof b);
        printf("The size of the interger 'int' data type is:   %zu bytes\n", sizeof c);
        printf("The size of the interger 'long' data type is:  %zu bytes\n", sizeof d);

        //Floating points
        float  e;
        double f;
        
        printf("The size of the floating point 'float' data type is:  %zu bytes\n", sizeof e);
        printf("The size of the floating point 'double' data type is: %zu bytes\n", sizeof f);
        
        return 0;
}
