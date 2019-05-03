/*
 * Program to see how structures (structured data types) work
 */

#include <stdio.h>

struct exercise {
        const char *description;
        float duration;
};

struct meal {
        const char *ingredients;
        float weight;
};

struct preferences {
        struct meal food;
        struct exercise exercise;
};

struct fish {
        const char *name;
        const char *species;
        int teeth;
        int age;
        struct preferences care;
};

void catalog (struct fish f);
void label (struct fish f);

int main()
{
        struct fish snappy = {
                .name = "Snappy",
                .species = "Piranha",
                .teeth = 69,
                .age = 4,
                .care.food.ingredients = "food",
                .care.food.weight = 0.2,
                .care.exercise.description = "swim in the jacuzzi",
                .care.exercise.duration = 7.5
        };
        catalog(snappy);
        label(snappy);
                 
        return 0;
}

/* Print out the catalog entry */
void catalog (struct fish f)
{
        printf("%s is a %s with %i teeth. He is %i.\n",
               f.name, f.species, f.teeth, f.age);
}

/* Print the label for the tank */
void label (struct fish f)
{
        printf("Name: %s\n", f.name);
        printf("Species: %s\n", f.species);
        printf("%i years old, %i teeth\n", f.age, f.teeth);
        printf("Feed with %2.2f lbs fo %s, and allow to %s for %2.2f hours\n",
               f.care.food.weight, f.care.food.ingredients,
               f.care.exercise.description, f.care.exercise.duration);
}
