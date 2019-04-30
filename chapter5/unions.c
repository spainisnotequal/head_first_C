/*
 * Program to learn about unions
 */

#include <stdio.h>

union quantity {
        short count;
        float weight;
        float volume;
};

int main()
{
        union quantity q = {4.4};
        printf("Count = %f\n", (float)q.count); //Count = 4.000000, because 4.4 was stored as an int
        printf("Weight = %f\n", q.weight);
        printf("Volume = %f\n", q.volume);
        
        return 0;
}
