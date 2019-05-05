/*
 * Program to learn about unions
 */

#include <stdio.h>

union quantity {
        short count;
        float weight;
        float volume;
        
        unsigned char bytes[sizeof(float)]; // for printing purposes
};

/*
 * show_bytes prints bytes using big-endian notation. On a little-endian system,
 * the bytes are going to be stored backwards from what you are used to seeing
 */
void show_bytes(union quantity q) 
{
        for(size_t i = 0; i < sizeof(float); i++)
                printf(" %x", q.bytes[i]);
        printf("\n");
}

int main()
{        
        union quantity q1 = {9}; // Not the best way to initialize a union
                                 // (or a structure)
        show_bytes(q1);

        union quantity q2 = { // Much better way to initialize a union or a
                              // structure
                .weight = 3.3
        };
        show_bytes(q2);
        
        union quantity q3;
        q3.weight = 3.3; // Also a great way to initialize a union or a structure
        show_bytes(q3);

        // Be aware that by using the C89 style, we can only initialize the first
        // field, and by not explicitely writing the field name, it's easier to
        // forget about its type (it's a short int, not a float)
        union quantity q4 = {4.4};
        printf("Count = %f\n", (float)q4.count); // Count = 4.000000, because 4.4
                                                 // was stored as a short int
                
        return 0;
}
