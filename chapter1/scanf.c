/*
 * Program to see what are some options of the scanf function.
 */

#include <stdio.h>

int main()
{
        char word[10];
        puts("Enter a word: ");
        scanf("%s", word);
        printf("the word is: %s\n", word);
        for (int i = 0; i < 10; i++) {
                printf("\tword[%i] = %c\n", i, word[i]);
        }

        char word2[3];
        puts("Enter a word: ");
        scanf("%2s", word2); // even if we write more than two characters, we only read the first two
        printf("the word is: %s\n", word2);
        for (int i = 0; i < 3; i++) {
                printf("\tword2[%i] = %c\n", i, word2[i]);
        }

        return 0;
}
