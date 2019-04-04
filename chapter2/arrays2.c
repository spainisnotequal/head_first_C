/*
 * Program to learn how arrays work.
 */

#include <stdio.h>

int main ()
{
        int v[] = {1, 9, -3, 0, 8};

        // Print elements of the array
        printf("v[0] = %i\n", *(v + 0));
        printf("v[1] = %i\n", *(v + 1));
        printf("v[2] = %i\n", *(v + 2));
        printf("v[3] = %i\n", *(v + 3));
        printf("v[4] = %i\n", *(v + 4));

        int *p = v;
        // Print elements of the array
        printf("v[0] = %i\n", *(p + 0));
        printf("v[1] = %i\n", *(p + 1));
        printf("v[2] = %i\n", *(p + 2));
        printf("v[3] = %i\n", *(p + 3));
        printf("v[4] = %i\n", *(p + 4));

        // Print the addresses of the elements of the array
        printf("v[0] = %p\n", v); // the name of the array contains the address of the first element
        printf("v[1] = %p\n", v + 1);
        printf("v[2] = %p\n", v + 2);
        printf("v[3] = %p\n", v + 3);
        printf("v[4] = %p\n", v + 4);

        // Print elements of the array
        printf("v[0] = %p\n", p);
        printf("v[1] = %p\n", p + 1);
        printf("v[2] = %p\n", p + 2);
        printf("v[3] = %p\n", p + 3);
        printf("v[4] = %p\n", p + 4);

        // Different ways to access one element of the array
        printf("\n\n");
        printf("v[0] = %i\n", v[0]);
        printf("v[0] = %i\n", *v);
        printf("v[0] = %i\n", *p);        

        printf("v[1] = %i\n", v[1]);
        printf("v[1] = %i\n", *(v+1));
        printf("v[1] = %i\n", *(p+1));        
     

        return 0;
}
