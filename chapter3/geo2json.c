/*
 * Program to convert geographical comma-separated data to JSON format
 */

#include <stdio.h>
#include <stdbool.h>

int main ()
{
        float latitude;
        float longitude;
        char info[80];
        int started = false;

        puts("data=[");
        while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
                if (started)
                        printf(",\n");
                else
                        started = true;
                printf("{latitude: %f, longitude: %f, info: '%s'}", latitude,
                       longitude, info);
        }
        puts("\n]");
        
        return 0;
}
