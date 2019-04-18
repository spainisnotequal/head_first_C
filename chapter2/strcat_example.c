/*
 * Program to learn how the strcat() function of the C string standard library
 * works
 */

#include <stdio.h>
#include <string.h>

int main()
{
        char dest[20] = "news"; // We must allocate space in advance for the
                                // composition of the two words
        char src[] = "paper";

        printf("The length of '%s' is: %zu\n", dest, strlen(dest));
        printf("The length of '%s' is: %zu\n", src, strlen(src));

        /* We cannot do the following, because "dest" (and "src") would point to
           the literal "news" ("src" to the literal "paper") in the constants
           memory (which is read-only), so when we try to add "src" at the end
           of "dest" we try to write in the constants memory, which is not
           allowed:
           char *dest = "news";
           char *src = "paper";
           strcat(dest, src); // WRONG!
        */

        /* We cannot do the following neither, because "dest" would not have
           enough space (it only allocates 5 sizeof(char) bytes in the heap
           memory) to add "src" at the end of dest, so we will be writing in an
           unknown part of the heap memory (buffer overflow). Because of that
           possible buffer overflow, the function says strccat() says that when
           the destination array is not long enough to append the other string,
           the result is an "undefined behaviour", and we should ALWAYS avoid
           that. Here it's the example:
           char dest[] = "news";
           char src[] = "paper";
           strcat(dest, src); // WRONG!
        */
        
        // Before concatenating two strings we should always check that the
        // string dest have sufficient space to hold the result
        size_t length1 = sizeof(dest)/sizeof(dest[0]);

        if (length1 > strlen(dest) + strlen(src)) {
                strcat(dest, src);
                printf("The new compound word is: %s\n", dest);
                printf("The length of '%s' is: %zu\n", dest, strlen(dest));

        }
        else{
                printf("Not enough space to concatenate those strings\n");
        }

        /* Another way of avoiding a buffer overflow if there is not sufficient
           space is using the strncat() function:
           
                   char *strncat(char *dest, const char *src, size_t n)
                   
           which appends not more than n characters (a null character and
           characters that follow it are not appended) from the array pointed to
           by "src" to the end of the string pointed to by "dest". The initial
           character of "src" overwrites the null character at the end of "dest"
        */
                    
        return 0;
}
