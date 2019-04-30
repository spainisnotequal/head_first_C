/*
 * Program to learn about passing structures to functions and how pointers
 * to structures work
 */

#include <stdio.h>

struct complex {
        int re;
        int im;
};

void add1real_not_update (struct complex c) // by default, parameters are passed
                                            // by value
{
        c.re += 1;
        printf("%i + %ij\n", c.re, c.im);
}

void add1real_and_update (struct complex *c) // use pointers to pass parameters
                                             // by reference
{
        c->re += 1; //(*c).re += 1;
        printf("%i + %ij\n", c->re, c->im); //printf("%i + %ij\n", (*c).re, (*c).im);
}

int main()
{
        struct complex c1 = {2,1};
        
        add1real_not_update(c1);
        printf("%i + %ij\n", c1.re, c1.im);
        
        add1real_and_update(&c1);
        printf("%i + %ij\n", c1.re, c1.im);
        
        return 0;
}
