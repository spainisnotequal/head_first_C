/*
 * Program to print the size of different data types
 */

#include <stdio.h>

int main ()
{
        /* Implicit casting between integers */
        short x = 15;
        int   y = x; // Nothing bad happens, as we are casting a small number
                     // into a larger one
        printf("The value of y is %i\n", y);

        y = 100000;
        short z = y; // Wrong!, because we are casting a large number into a
                     // smaller one
        printf("The value of z is %hi\n", z); // the result is -31072

        /* Explicit casting between integers and floating point numbers */
        int a = 7;
        int b = 2;
        float c = a / b;
        printf("a / b = %f\n", c); // Wrong!, we are performing an integer
                                   // division

        float d = (float)a / (float)b;
        printf("a / b = %f\n", d); // Correct!

        float e = (float)a / b;
        printf("a / b = %f\n", e); // Correct!, the compiler will automatically
                                   // cast b to a float point number
        
        return 0;
}
