/*
 * Program to print the limits and size of different data types
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main ()
{
        //Integers
        printf("\nThe size of the interger 'char' data type is: %zu bytes\n", sizeof(char));
        printf("The minimum value of a 'char' is %i\n", CHAR_MIN);
        printf("The maximum value of a 'char' is %i\n", CHAR_MAX);
        
        printf("\nThe size of the interger 'short' data type is: %zu bytes\n", sizeof(short));
        printf("The minimum value of a 'short' is %hi\n", SHRT_MIN);
        printf("The maximum value of a 'short' is %hi\n", SHRT_MAX);
        
        printf("\nThe size of the interger 'int' data type is: %zu bytes\n", sizeof(int));
        printf("The minimum value of a 'int' is %i\n", INT_MIN);
        printf("The maximum value of a 'int' is %i\n", INT_MAX);
        
        printf("\nThe size of the interger 'long' data type is: %zu bytes\n", sizeof(long));
        printf("The minimum value of a 'long' is %li\n", LONG_MIN);
        printf("The maximum value of a 'long' is %li\n", LONG_MAX);
        
        //Floating points
        printf("\nThe size of the floating point 'float' data type is:  %zu bytes\n", sizeof(float));
        printf("The minimum value of a 'float' is %.50f\n", FLT_MIN);
        printf("The maximum value of a 'float' is %f\n", FLT_MAX);
        
        printf("\nThe size of the floating point 'double' data type is: %zu bytes\n", sizeof(double));
        printf("The minimum value of a 'double' is %.50f\n", DBL_MIN);
        printf("The maximum value of a 'double' is %f\n", DBL_MAX);
        
        return 0;
}
