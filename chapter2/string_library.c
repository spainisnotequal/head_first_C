/*
 * Program to learn how the string.h library works
 */

#include <stdio.h>
#include <string.h>

int main()
{
        char dest[20] = "news"; // We must allocate space in advance for the
                              // composition of the two words
        char src[] = "paper";

        // calculate the length og a string
        printf("The length of '%s' is: %zu\n", dest, strlen(dest));
        printf("The length of '%s' is: %zu\n\n", src, strlen(src));
        
        // Concatenate two strings
        size_t length1 = sizeof(dest)/sizeof(dest[0]);

        if (length1 > strlen(dest) + strlen(src)) {
                strcat(dest, src);
                printf("The new compound word is: %s\n", dest);
                printf("The length of '%s' is: %zu\n\n", dest, strlen(dest));

        }
        else{
                printf("Not enough space to concatenate those strings\n\n");
        }
        
        // Find one string in another string
        if (strstr(dest,src))
                printf("I found '%s' in '%s'\n\n", src, dest);

        // Copy the string pointed by "src" to the string pointed by "dest"
        char dest2[] = "newspaper";
        char src2[] = "website";
        if (strlen(dest2) >= strlen(src2)) {
                printf("Destination string before copying: %s\n", dest2);
                printf("Source string: %s\n", src2);
                strcpy(dest2, src2);
                printf("Destination string after copying: %s\n\n", dest2);
        }
        else{
                printf("Not enough space to copy '%s' to '%s'\n\n", src2, dest2);
        }

        /* Compare two strings lexicographically

           Return value: =0 -> both strings are found to be identical. That is,
                               all of the characters in both strings are same.
                         >0 -> the first not matching character in the first
                               string have a greater ASCII value than the
                               corresponding character in the second string
                         <0 -> the first not matching character in the first
                               string have a lesser ASCII value than the
                               corresponding character in the second string
        */
        char s1[] = "alpha";
        char s2[] = "omega";

        printf("First string: %s\n", s1);
        printf("Second string: %s\n", s1);
        int res = strcmp(s1, s1); 
        if (res==0) 
                printf("Strings are equal\n"); 
        else 
                printf("Strings are unequal\n"); 
          
        printf("Value returned by strcmp() is:  %d\n\n" , res);

        printf("First string: %s\n", s1);
        printf("Second string: %s\n", s2);
        res = strcmp(s1, s2); 
        if (res==0) 
                printf("Strings are equal\n"); 
        else 
                printf("Strings are unequal\n"); 
          
        printf("Value returned by strcmp() is:  %d\n\n" , res);

        printf("First string: %s\n", s2);
        printf("Second string: %s\n", s1);
        res = strcmp(s2, s1); 
        if (res==0) 
                printf("Strings are equal\n"); 
        else 
                printf("Strings are unequal\n"); 
          
        printf("Value returned by strcmp() is:  %d\n\n" , res); 
        
        return 0;
}
