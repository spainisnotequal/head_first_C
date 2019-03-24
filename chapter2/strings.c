/*
 * Program to learn how strings are passed to a function,
 * and the differences between arrays and pointers.
 */

#include <stdio.h>

void fun1(char msg[]){
        printf("Message reads: %s\n", msg);
        printf("msg occupies %lu bytes\n", sizeof(msg));
}

// Array variables are passed to funtions as if they were pointers, so we can also write:
void fun2(char *msg){
        printf("Message reads: %s\n", msg);
        printf("msg occupies %lu bytes\n", sizeof(msg));
}
/* But that doesn't mean that array variables are pointers.
   We'll see the differences in the last block of the main function.
 */

int main()
{
        char quote[] = "Cookies make you fat";
        fun1(quote);
        fun2(quote);

        /* Diffences between arrays and pointers */
        char s1[] = "How big is it?";
        char *p = s1;

        // (1) sizeof of an array
        printf("\n");
        printf("The size of the array s1 is %lu\n", sizeof(s1));
        printf("The size of the pointer p is %lu\n", sizeof(p));

        // (2) The address of an array is the array itself: &s1 == s1
        printf("\n");
        printf("The value of s1 is  %p\n", s1);
        printf("The value of &s1 is %p\n", &s1);

        printf("The value of p is   %p\n", p);
        printf("The value of &p is  %p\n", &p);
        
        // (3) an array variable cannot point anywhere else
        char s2[] = "Just another string, different from s1";
        p = s2; // No problem, now t points to s2
        printf("\n");
        printf("This pharse should be s2: %s\n", p);
        /*
          The following assignments produce a compile error.
          The reason is because when we create an array, the computer allocates
          space to store the array, but it doesn't allocate any memory to store
          the array variable (the compiler simply plugs in the address of the start
          of the array.
          So because array variables don't have allocated storage, it means you
          cannot point them at anything else.
        */
        //s1 = s2; // compilation error
        //s1 = t;  // compilation error
        
        return 0;
}
