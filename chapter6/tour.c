/*
 * Program to learn about linked lists
 */

#include <stdio.h>

struct island {
        const char *name;
        const char *opens;
        const char *closes;
        struct island *next;
};

void display (struct island *start)
{
        struct island *i = start;
        for (; i != NULL; i = i->next)
                printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
}

int main()
{
        // create the islands
        struct island amity = {
                .name = "Amity",
                .opens = "09:00",
                .closes = "17:00",
                .next = NULL
        };
        struct island craggy = {
                .name = "Craggy",
                .opens = "09:00",
                .closes = "17:00",
                .next = NULL
        };
        struct island isla_nublar = {
                .name = "Isla Nublar",
                .opens = "09:00",
                .closes = "17:00",
                .next = NULL
        };
        struct island shutter = {
                .name = "Shutter",
                .opens = "09:00",
                .closes = "17:00",
                .next = NULL
        };

        // link them together to create a tour
        amity.next = &craggy;
        craggy.next = &isla_nublar;
        isla_nublar.next = &shutter;

        // display the tour
        printf("Original tour:\n");
        display(&amity);

        // insert a new island between Isla Nubblar and Shutter islands
        struct island skull = {
                .name = "Skull",
                .opens = "09:00",
                .closes = "17:00",
                .next = NULL
        };

        isla_nublar.next = &skull;
        skull.next = &shutter;

        // display the tour
        printf("\nModified tour:\n");
        display(&amity);
        
        return 0;
}
