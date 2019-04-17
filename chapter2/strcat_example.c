/*
 * Program to learn how the strcat() function of the C string standard library
 * works
 */

#include <stdio.h>
#include <string.h>

int main()
{
        char s0[20] = "news"; // We must allocate space in advance for the
                              // composition of the two words
        char s1[] = "paper";

        printf("The length of '%s' is: %zu\n", s0, strlen(s0));
        printf("The length of '%s' is: %zu\n", s1, strlen(s1));

        /* We cannot do the following, because s0 (and s1) would point to the
           literal "news" (s1 to the literal "paper") in the constants memory
           (which is read-only), so when we try to copy s1 at the end of s0 we
           try to write in the constants memory, which is not allowed:
           char *s0 = "news";
           char *s1 = "paper";
           strcat(s0, s1); // WRONG!
        */

        /* We cannot do the following neither, because s0 would not have enough
           space (it only allocates 5 sizeof(char) bytes in the heap memory) to
           copy s1 at the end of s0, so we will be writing in an unknown part
           of the heap memory (buffer overflow). Because of that possible buffer
           overflow, the function says strccat() says that when the destination
           array is not long enough to append the other string, the result is an
           "undefined behaviour", and we should ALWAYS avoid that. Here it's the
           example:
           char s0[] = "news";
           char s1[] = "paper";
           strcat(s0, s1); // WRONG!
        */
        
        // Concatenate two strings
        strcat(s0, s1); // strcat() return a pointer to the destination string,
                        // so we can capture it doing char *s2 = strcat(s0, s1);
                        // altough it's not very useful (we already know that
                        // address: is s0)
        printf("The new compound word is: %s\n", s0);
        printf("The length of '%s' is: %zu\n", s0, strlen(s0));

        return 0;
}
