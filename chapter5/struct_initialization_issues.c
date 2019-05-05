/*
 * Program to see some issues when initializing structures (or unions)
 */

#include <stdio.h>

struct person {
        const char *name;
        int age;
};

int main()
{
        struct person jesus;

        /* If we try to initialize a structure after its declaration, we cannot
         * do it using the following expressions:
         *         jesus = {"Jesus Christ", 33};
         *         jesus = {.name = "Jesus Christ", .age = 33};
         * because the compiler will only know that those expressions represent
         * a structure if we write them in the same expression where we declared
         * them. When we do it in a separate expression, the compiler thinks that
         * those expressions are arrays.
         * So if we want to declare and initialize the structure in different
         * expressions we must use the dot notation style:
         */
        jesus.name = "Jesus Christ";
        jesus.age = 33;
        
        printf("%s's age is %i\n", jesus.name, jesus.age);
        
        return 0;
}
