/*
 * Program to look for some text using the "strstr()" function from the
 * C Standar Library
 */

#include <stdio.h>
#include <string.h>

char TRACKS[][80] = {
        "I left my heart in Harvard Mead School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
};

void find_track(char search_for[])
{
        int i;
        for (i = 0; i < 5; i++)
        {
                if (strstr(TRACKS[i], search_for))
                        printf("Track %i: '%s'\n", i + 1, TRACKS[i]);
        }
}

int main(void)
{
        char search_for[80];

        printf("Search for: ");
        //fgets(search_for, 80, stdin); // fgets() adds a newline charcarter '\n'
                                        // at the end of the string
        scanf("%79s", search_for);
        find_track(search_for);

        return 0;
}
