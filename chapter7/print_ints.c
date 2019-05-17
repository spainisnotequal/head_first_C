/*
 * Program to learn about variadic functions
 */

#include <stdio.h>
#include <stdarg.h>


void print_ints (int num_args, ...)
{
        va_list extra_args;
        va_start(extra_args, num_args);

        for (int i = 0; i < num_args; i++) {
                printf("argument: %i\n", va_arg(extra_args, int));
        }

        va_end(extra_args);
}

int main (void)
{
        print_ints(3, -12, 33, 6);
        
        return 0;
}
