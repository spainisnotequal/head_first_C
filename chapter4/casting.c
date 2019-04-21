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

        /* Implicit casting integers to floating point numbers */
        int a = 7;
        int b = 2;
        float c = a / b;
        printf("a / b = %f\n", c); // Wrong!, we are performing an integer
                                   // division

        /* Explicit casting integers to floating point numbers */
        float d = (float)a / (float)b;
        printf("a / b = %f\n", d); // Correct!

        float e = (float)a / b;
        printf("a / b = %f\n", e); // Correct!, the compiler will automatically
                                   // cast b to a float point number

        /* Implicit casting floating point numbers to integers */
        float f = 83.6598;
        int g = f;
        printf("The value of g is %i\n", g); // Wrong!, we are loosing the
                                             // decimal part of the floating
                                             // point number
        
        /* Explicit casting floating point numbers to integers */
        int h = (int)f;
        printf("The value of h is %i\n", h); // Wrong!, we are loosing the
                                             // decimal part of the floating
                                             // point number
        
        return 0;
}
