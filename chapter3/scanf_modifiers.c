/*
 * Program to learn the differences between two fscanf() modifiers:
 *     - "%79[^\n]"
 *     - "%79[^\n]\n"
 */

#include <stdio.h>

int main ()
{
        char line[80];

        FILE *input1 = fopen("some.text", "r");
        puts("");
        puts("%79[^\\n] modifier results:");
        puts("--------------------------");
        while (fscanf(input1, "%79[^\n]", line) == 1)
                printf("%s\n", line);
        fclose(input1);

        FILE *input2 = fopen("some.text", "r");
        puts("");
        puts("%79[^\\n]\\n modifier results:");
        puts("----------------------------");
        while (fscanf(input2, "%79[^\n]\n", line) == 1)
                printf("%s\n", line);
        fclose(input2);

        return 0;
}
