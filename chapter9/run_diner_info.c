/*
 * Program to learn about system calls
 */

#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
        const char *my_env[] = {"JUICE=peach and apple", NULL};
        execle("diner_info", "diner_info", "4", NULL, my_env);
        
        return 0;
}
