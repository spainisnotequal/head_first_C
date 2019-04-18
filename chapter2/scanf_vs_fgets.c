/*
 * Program to show one difference between scanf() and fgets() when reading
 * strings
 */

#include <stdio.h>
#include <string.h>

int main()
{
        char phrase[] = "The show must go on";
        char text[10];

        printf("Write the text you want to look for: ");
        fgets(text, 10, stdin);
        /* If we write "show" the result is "not found", because the function
           fgets() adds a newline character at the end of the string (because we
           hit the "Enter" key in our keyboard), so "text" will be "show\n", and
           we the function strstr() looks for that string in the "phrase", it
           does not find it. The reason is that the function strstr() uses the
           termination charcter "\0" to know when a string ends, so for that
           function, "show\n" is not "show" but "show\n", and that's the reason
           why is not found in the variable "phrase".
           But if we enter a string equal or longer than 10 characters, like
           "show must go on" the result is found, because it uses all the
           allocated chars of "text" to save the first 10 characters, but does
           not add a newline character "\n" (we hit "Enter" after those 10
           characters), so the "text" will be "show must ", which is found in
           the "phrase" variable.
        */
        if (strstr(phrase, text))
                printf("Found '%s' in '%s'\n", text, phrase);
        else
                printf("'%s' not found in '%s'\n", text, phrase);
        
        printf("Write the text you want to look for: ");
        scanf("%9s", text);
        /* We don't have that problem with the function scanf(), which doesn't
           add a newline character "\n" if we introduce 9 characters or less,
           but a termination character "\0", that is what the function strstr()
           uses to know when a string ends.
           So if we enter "show", the variable text will be "show\0", which that
           function will find in the variable "phrase".
        */
        if (strstr(phrase, text))
                printf("Found '%s' in '%s'\n", text, phrase);
        else
                printf("'%s' not found in '%s'\n", text, phrase);
        
        return 0;
}
