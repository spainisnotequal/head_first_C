/*
 * Program to learn about arrays of pointers to functions
 */

#include <stdio.h>


enum response_type {DUMP, SECOND_CHANCE, MARRIAGE, LAW_SUIT};

struct response {
        char *name;
        enum response_type type;
};

void dump (struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Unfortunately your last date contacted us to");
        puts("say that they will not be seeing you again");
}

void second_chance (struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Good news: your last date has asked us to");
        puts("arrange another meeting. Please call ASAP.");
}

void marriage (struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("Congratulations! Your last date has contacted");
        puts("us with a proposal of marriage.");
}

void law_suit (struct response r)
{
        printf("Dear %s,\n", r.name);
        puts("I'm sorry, but you are going to court");
        puts("because someone didn't like your catcall.");
}

void (*replies[])(struct response) = {dump, second_chance, marriage, law_suit};

int main (void)
{
        struct response r[] = {
                {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
                {"Matt", SECOND_CHANCE}, {"William", MARRIAGE},
                {"George", LAW_SUIT}
        };
        size_t  num_elements = sizeof(r)/sizeof(r[0]);
        
        for (size_t i = 0; i < num_elements; i++) {
                // The three alternatives are perfectly valid:
                //replies[r[i].type](r[i]);
                (replies[r[i].type])(r[i]);
                //(*replies[r[i].type])(r[i]);
        }

        return 0;
}
