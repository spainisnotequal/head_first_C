/*
 * Program to learn about bitfields
 */

#include <stdio.h>
#include <stdbool.h>

struct survey1 {
        unsigned short first_visit;
        unsigned short come_again;
        unsigned short fingers_lost;
        unsigned short shark_attack;
        unsigned short days_a_week;
};

struct survey2 {
        unsigned int first_visit;
        unsigned int come_again;
        unsigned int fingers_lost;
        unsigned int shark_attack;
        unsigned int days_a_week;
};

struct survey3 {
        unsigned int first_visit: 1;
        unsigned int come_again: 1;
        unsigned int fingers_lost: 4;
        unsigned int shark_attack: 1;
        unsigned int days_a_week: 3;
};

int main()
{        
        printf("size using 'unsigned short' = %zu bytes\n", sizeof(struct survey1));
        printf("sizeof using 'unsigned int' = %zu bytes\n", sizeof(struct survey2));
        printf("size using bitfields = %zu bytes\n", sizeof(struct survey3));
        
        return 0;
}
