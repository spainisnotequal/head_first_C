/*
 * Program to learn how arrays work.
 */

#include <stdio.h>

int main ()
{
        int v[] = {1, 9, -3, 0, 8};
        int *p = v;
        
        // They both contain the same address        
        printf("v variable contains: %p\n", v);
        printf("p pointer contains : %p\n", p);

        // But let's check their size and see how they don't match...
        printf("v variable size: %3lu bytes\n", sizeof(v));
        printf("p pointer size : %3lu bytes\n", sizeof(p));

        // But also be aware that the equality operator (==) says they are equal (because we are comparing memory addresses)
        printf("Are the variable v and the pointer p equal (v == p)? %s\n", v == p ? "true" : "false");

        // On the other hand, we can change the value of a pointer
        int w[] = {3, -1, -8, 5, 0, 4};
        p = w;
        printf("now, p pointer contains : %p\n", p);

        //But no the value (a memory address) of an array!
        // v = w; // compilation error: "assignment to expression with array type"
        
        return 0;
}
