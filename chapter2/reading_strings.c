/*
 * Program to learn about reading strings with scanf() and fgets()
 */

#include <stdio.h>

int main()
{
        /* When reading strings with scanf(), we can avoid buffer overflows by
           carefully putting a limit on the number of characters to read */
	char s1[5];

        printf("Enter a 4 letters word: ");
        scanf("%4s", s1);
        printf("Word = %s\n", s1);
        
        /* But if we forget to write the number of characters to read, we can
           cause a buffer overflow, causing a segmentation fault or an abort
           trap */
        char s2[5];

        printf("Enter a word with more than 4 letters: ");
        scanf("%s", s2);
        printf("Word = %s\n", s2);

        /* Next two lines are just to clear the input buffer after the last
           scanf() before continuing with the other options to read data */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

	/* fgets() is an alternative to scanf(), where you have to explicitely
           espicify the number of characters to read (so it's imposible to
           forget to do so). On top of that, fgets() never produces a buffer
           overflow */
	char name[20];
        
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        printf("Hello, %s\n", name);

        /* But we have to be careful with fgets() if we have a pointer to an
           array instead of an array of characters, because the operator sizeof
           with a pointer just returns the size of the pointer, no the size of
           the array it points */
        char *p = name;
        
        printf("size of the array: %lu\n", sizeof(name));
        printf("size of the pointer: %lu\n", sizeof(p));

        /* So when we use a pointer to an array of characters, we have to
           manually specify the size of the array */
        printf("Enter your name: ");
        fgets(p, 20, stdin);
        printf("Hello, %s\n", p);

        /* Another situation that scanf() does not handle well is when dealing
           with strings that contain spaces, but fgets() has no problem with
           spaces */
        
        return 0;
}
