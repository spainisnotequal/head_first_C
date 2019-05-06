/*
 * Program to learn about enums
 */

#include <stdio.h>


enum colours {
        GREEN, RED, BLUE
};

int main()
{        
        enum colours favourite = BLUE;
        
        if (favourite == GREEN)
                printf("Green is your favourite colour.\n");
        else {
                if (favourite == RED)
                        printf("Red is your favourite colour.\n");
                else
                        printf("Blue is your favourite colour.\n");
        }
        
        return 0;
}
