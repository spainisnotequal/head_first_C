/*
 * Program to learn about passing structures to functions and how pointers
 * to structures work
 */

#include <stdio.h>

struct turtle {
        const char *name;
        const char *species;
        int age;
};

void happy_birthday (struct turtle *t)
{
        t->age = t->age + 1; //(*t).age = (*t).age + 1;
        printf("Happy Birthday %s! You are now %i years old!\n",
               t->name, t->age); // (*t).name, (*t).age);
}

int main()
{
        struct turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
        happy_birthday(&myrtle);
        printf("%s's age is now %i\n", myrtle.name, myrtle.age);
        
        return 0;
}
