/*
 * Check is the contents of a string have been modified
 */

#include "checksum.h"


int checksum (char *message)
{
        int c = 0;
        while (*message) {
                c += c ^(int) (*message);
                message++;
        }
        return c;
}
