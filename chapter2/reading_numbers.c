/*
 * Program to learn about reading numbers with scanf() and fgets()
 */

#include <stdio.h>

int main()
{
        /* scanf() does a great job when reading "structured data" (data that we
           know for sure what format has), so as far as that it true, we can
           read numbers (and strings) very conviniently */
	char product[5];
        int id;
        float price;

        printf("Enter a product, its id, and its price (separated by commas): ");
        scanf("%4s,%i,%f", product, &id, &price);
        printf("product name: %s\n", product);
        printf("product id: %i\n", id);
        printf("product price: %.2f\n", price);

        /* But notice that the product's name has to be exactlyt 4 characters
           long (or at least there must be 4 characters before the first comma)
           to work properly. If we introduce, for example, four characters for
           the name, and later the other information, we get errors reading the
           data. That's a big problem with scanf() */

        /* Next two lines are just to clear the input buffer after the last
           scanf() before continuing with the other options to read data */ 
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }


        /* If we are not sure about the structure of the data, of want to add an
           extra of security that, probably, nothing bad is going to happen
           (bulletproof code), it better to read the data with fgets() and later
           parse the data with a tailored parsing scheme (using something solid
           like strtol() or strtod(), or something like the fuction sscanf()).
           But using sscanf() doesn't really solve the problem (because it have
           the same pitfalls than scanf()), but makes it a bit easier by
           decoupling what are really two separate tasks: reading input, and
           parsing input */
        char line[50];
        
        // Read the input
        printf("Enter a product, its id, and its price (separated by commas, spaces or newlines): ");
        fgets(line, sizeof(line), stdin);
        printf("product information: %s\n", line);

        /* Now,we should write some kind of function to parse the data here,
           using functions like getchar(), strtol(), strtod(), etc. */
        
        return 0;
}
