/*
 * Program to filter data that is inside the Bermuda Rectangle
 */

#include <stdio.h>
#include <stdbool.h>

int main ()
{
        float latitude;
        float longitude;
        char info[80];

        while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
                if ((latitude > 26.0) && (latitude < 34.0))
                        if ((longitude > -76.0) && (longitude < -64.0))
                                printf("%f,%f,%s\n", latitude, longitude, info);
        }

        return 0;
}
