/*
 * Program to learn how the strcat() function of the C string standard library
 * works
 */

#include <stdio.h>
#include <string.h>

int main()
{
        char s1[20] = "news"; // We must allocate space in advance for the
                              // composition of the two words
        char s2[] = "paper";

        printf("The length of '%s' is: %zu\n", s1, strlen(s1));
        printf("The length of '%s' is: %zu\n", s2, strlen(s2));

        /* We cannot do the following, because s1 (and s2) would point to the
           literal "news" (s2 to the literal "paper") in the constants memory
           (which is read-only), so when we try to add s2 at the end of s1 we
           try to write in the constants memory, which is not allowed:
           char *s1 = "news";
           char *s2 = "paper";
           strcat(s1, s2); // WRONG!
        */

        /* We cannot do the following neither, because s1 would not have enough
           space (it only allocates 5 sizeof(char) bytes in the heap memory) to
           add s2 at the end of s1, so we will be writing in an unknown part of
           the heap memory (buffer overflow). Because of that possible buffer
           overflow, the function says strccat() says that when the destination
           array is not long enough to append the other string, the result is an
           "undefined behaviour", and we should ALWAYS avoid that. Here it's the
           example:
           char s1[] = "news";
           char s2[] = "paper";
           strcat(s1, s2); // WRONG!
        */
        
        // Before concatenating two strings we should always check that the
        // string s1 have sufficient space to hold the result
        size_t length1 = sizeof(s1)/sizeof(s1[0]);

        if (length1 > strlen(s1) + strlen(s2)) {
                strcat(s1, s2);
                printf("The new compound word is: %s\n", s1);
                printf("The length of '%s' is: %zu\n", s1, strlen(s1));

        }
        else{
                printf("Not enough space to concatenate those strings\n");
        }

        /* Another way of avoiding a buffer overflow if there is not sufficient
           space is using the strncat() function:
           
                   char *strncat(char *dest, const char *src, size_t n)
                   
           which appends not more than n characters (a null character and
           characters that follow it are not appended) from the array pointed to
           by s2 to the end of the string pointed to by s1. The initial character
           of s2 overwrites the null character at the end of s1
        */
        
                    
        return 0;
}
