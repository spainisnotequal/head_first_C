/*
 * Program to learn how pointers work.
 */

#include <stdio.h>

int y = 1; // y is stored in the globals' memory because it is declared outside any function.

int main()
{
        int x = 33;
        int *p = &x;
        printf("The value of x is %i\n", x);
        // We can get the address of any variable store in memory.
        // x is stored in the stack memory because it is declared inside a function (the main function, in this case).
        printf("The memory direction of x is  %p\n", p);
        // The pointer p is also a variable stored in the stack memory and we can get its address as well.
        printf("The memory direction of *p is %p\n", &p);

        p = &y;
        printf("The value of y is %i\n", y);
        printf("The memory direction of y is  %p\n", p);
        
        return 0;
}
