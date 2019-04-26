/*
 * Program to see the difference between "const char *" and "char *" when
 * pointing to a string literal
 */


/* NOTE: "const" doesn't mean “constant”, but read-only. An example of that sutil
 * difference is: if we have a variable of type const volatile int the value may
 * change on successive reads! For example, in embedded systems reading such a
 * variable may give you the value of some sensor. It doesn't make sense to write
 * to it, but reading is useful.
 */

#include <stdio.h>

int main()
{
        /*
          const char *ptr1 = "Hello, World!";
          *ptr1 = 'j'; // it doesn't compile, because we are explicitely saying
                       // that *(ptr1 + 0), *(ptr1 + 1), ..., *(ptr1 + n) are
                       // constant characters
                       */
        
        char *ptr2 = "Hello, World!";
        *ptr2 = 'j'; // it does compile, but when running we get a "segmentation
                     // fault" error, because we are trying to write in a
                     // read-only section of memory (the CONSTANTS memory)
        
        /* Moral of the story: use "const" explicitely (defensive programming),
         * so we get an error during compilation and our program doesn't compile.
         * We'll catch certain bugs while compiling, instead of never or later
         * while running the program
         */
        
        return 0;
}
