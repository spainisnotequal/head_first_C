/*
 * Program to compare arrays of pointers with arrays of arrays
 */

#include <stdio.h>

int main ()
{
        char *s1[] = {"Al", "Capone"};
        /* "Al\0" and "Capone\0" are two string literals created in the
           CONSTANTS section of the RAM memory.
           "s1" is an array of two pointers created in the STACK section of the
           RAM memory, whose pointers point to those two string literals.
        */

        char s2[][7] = {"Al", "Capone"};
        /* "Al\0" and "Capone\0" are two string literals created in the
           CONSTANTS section of the RAM memory.
           "s2" is an array of two array, that reserves 2 * sizeof(char) bytes
           in the STACK section of the RAM memory, and copies those two
           string literals to the corresponding bytes.
        */

        printf("Size of a char variable:           %zu bytes\n", sizeof(char));
        printf("Size of a pointer to a char:       %zu bytes\n", sizeof(char*));
        printf("Size of the array of pointers:     %zu bytes\n", sizeof(s1));
        printf("Size of the array of arrays:       %zu bytes\n", sizeof(s2));

        // Size of a char variable:           1 bytes
        // Size of a pointer to a char:       4 bytes
        // Size of the array of pointers:     8 bytes
        // Size of the array of arrays:       14 bytes
        
        /* As we can see, arrays of pointers and arrays of arrays are not
           equivalent variables, despite of that we can operate with them in a
           similar way.
        */

        printf("First value pointed by the pointer array:  %s\n", *(s1 + 0));
        printf("Second value pointed by the pointer array: %s\n", *(s1 + 1));

        printf("First value pointed by the pointer array:  %s\n", s1[0]);
        printf("Second value pointed by the pointer array: %s\n", s1[1]);
        
        printf("First value pointed by the array of arrays:  %s\n", *(s2 + 0));
        printf("Second value pointed by the array of arrays: %s\n", *(s2 + 1));

        printf("First value pointed by the array of arrays:  %s\n", s2[0]);
        printf("Second value pointed by the array of arrays: %s\n", s2[1]);
        
        return 0;
}
