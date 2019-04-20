/*
 * Program to learn the differences between two fscanf() modifiers:
 *     - "%79[^\n]"
 *     - "%79[^\n]\n"
 * We also use fgets(), to compare the results
 */

#include <stdio.h>
#include <string.h>

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

        FILE *input3 = fopen("some.text", "r");
        puts("");
        puts("fgets() results:");
        puts("----------------");
        while (fgets(line, sizeof(line), input3)) {
                line[strcspn(line, "\n")] = 0; // removes the trailing newline character
                printf("%s\n", line);
        }
        fclose(input3);

        return 0;
}
