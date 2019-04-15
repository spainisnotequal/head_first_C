/*
 * Program that shuffles three cards
 */

#include <stdio.h>

int main()
{
        const char *cards = "JQK";
        char a_card = cards[2];

        cards[2] = cards[1]; // Wrong! String literals cannot be modified
        cards[1] = cards[0]; // Wrong! String literals cannot be modified
        cards[0] = cards[2]; // Wrong! String literals cannot be modified
        cards[2] = cards[1]; // Wrong! String literals cannot be modified
        cards[1] = a_card;   // Wrong! String literals cannot be modified

        puts(cards);

        return 0;
}
