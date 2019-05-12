/*
 * Program to learn about passing functions as parameters to other functions
 */

#include <stdio.h>
#include <string.h>

size_t NUM_ADS = 7;
const char *ADS[] = {
        "William: SBM GSOH likes sports, TV, dining",
        "Matt: SWM NS likes art, movies, theater",
        "Luis: SLM ND likes books, theater, art",
        "Mike: DWM DS likes trucks, sports and bieber",
        "Peter: SAM likes chess, working out and art",
        "Josh: SJM likes sports, movies and theater",
        "Jed: DBM likes theater, books and dining"
};

void find (void)
{
        puts("Search results:");
        puts("------------------------------------------");

        for (size_t i = 0; i < NUM_ADS; i++) {
                if ((strstr(ADS[i], "sports")) && (! strstr(ADS[i], "bieber")))
                        printf("%s\n", ADS[i]);
        }
        puts("------------------------------------------");
}

int main()
{
        find();
               
        return 0;
}
