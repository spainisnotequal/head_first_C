/*
 * Program to learn about arrays and pointer decay.
 *
 * When we pass an array to a function, it always happens a pointer decay, and we lost track of the size of the array. But in this program, at first sight, it seems that that pointer decay doesn't happen to char arrays, but the truth is that it happens as well; in our first example it only works by chance! because the "foo" function called keeps printing characters until it finds a '\0' character. We clearly see that that is the case in the second call to "foo", after we have introduced a '\0' inside the array.
 */

#include <stdio.h>

void foo (char *msg) {
        puts (msg + 1);
}

int main()
{
        char msg1[] = "Short message";
    
        /* The array decays to a pointer but the function prints the whole string because the funtion "puts" keeps printing characters until it finds the sentinel character '\0'*/
        foo(msg1);

        /* But if we change some intermediate value of the array to the sentinel character '\0', we can see how the function only prints the original string up to that character, not up to the end */
        msg1[3] = '\0';
        foo(msg1);

        return 0;
}
