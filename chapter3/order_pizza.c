/*
 * Program to see how command-line options work
 */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
        char *delivery = ""; // we asign it to an empty string, so if we don't
                             // use the corresponding command-line option, the
                             // expression after the corresponding if is not
                             // evaluated
        int thick      = 0;
        int count = 0;
        signed char ch; // we declare it as signed because in the while
                        // expression we are comparing it with EOF (which
                        // happens to be -1).
                        // If we declare it as a simple char, it will be unsigned
                        // and the comparison with EOF will always be true

        while ((ch = getopt(argc, argv, "d:t")) != EOF)
                switch (ch) {
                case 'd':
                        delivery = optarg;
                        break;
                case 't':
                        thick = true;
                        break;
                default:
                        fprintf(stderr, "Unknown option: '%s'\n", optarg);
                        return 1;
                }

        argc -= optind;
        argv += optind;

        if (thick)
                puts("Thick crust.");

        if (delivery[0])
                printf("To be delivered %s.\n", delivery);

        puts("Ingredients:");

        for (count = 0; count < argc; count++)
                puts(argv[count]);

        return 0;
}
