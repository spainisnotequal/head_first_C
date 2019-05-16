/*
 * Program to learn about arrays of pointers to functions
 */

#include <stdio.h>


enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

struct response {
        char *name;
        enum response_type type;
};

void dump(struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Unfortunately your last date contacted us to");
        puts("say that they will not be seeing you again");
}

void second_chance(struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Good news: your last date has asked us to");
        puts("arrange another meeting. Please call ASAP.");
}

void marriage(struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Congratulations! Your last date has contacted");
        puts("us with a proposal of marriage.");
}

void (*replies[])(struct response) = {dump, second_chance, marriage};

int main (void)
{
        struct response r[] = {
                {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
                {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
        };
        for (size_t i = 0; i < 4; i++) {
                (replies[r[i].type])(r[i]);
        }

        return 0;
}
