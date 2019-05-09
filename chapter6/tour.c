/*
 * Program to learn about linked lists
 */

#include <stdio.h>
#include <stdlib.h>

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

struct island* create (const char *name)
{
        struct island *i = malloc(sizeof(struct island));

        i->name = name;
        i->opens = "09:00";
        i->closes = "17:00";
        i->next = NULL;

        return i;
}

int main()
{
        char name[80];
        
        printf("Enter the name of an island: ");
        fgets(name, 80, stdin);
        struct island *p_island_0 = create(name);

        printf("Enter the name another island: ");
        fgets(name, 80, stdin);
        struct island *p_island_1 = create(name);

        p_island_0->next = p_island_1;

        display(p_island_0);
        
        return 0;
}
