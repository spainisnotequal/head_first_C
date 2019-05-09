/*
 * Program to learn about linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct island {
        char *name;
        char *opens;
        char *closes;
        struct island *next;
};

void display (struct island *start)
{
        struct island *i = start;
        for (; i != NULL; i = i->next)
                printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
}

struct island* create (const char *name)
{
        struct island *i = malloc(sizeof(struct island));

        i->name = strdup(name);
        i->opens = "09:00";
        i->closes = "17:00";
        i->next = NULL;

        return i;
}


int main()
{
        struct island *start = NULL;
        struct island *i = NULL;
        struct island *next = NULL;
        char name[80];

        for (; fgets(name, 80, stdin) != NULL; i = next) {
                next = create(name);
                if (start == NULL)
                        start = next;
                if (i != NULL)
                        i->next = next;
        }
        
        display(start);
                
        return 0;
}
