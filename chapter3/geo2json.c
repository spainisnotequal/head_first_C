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
                if ((latitude < - 90.0) || (latitude > 90.0)) {
                        printf("\nInvalid latitude: %f\n", latitude);
                        return 2;
                }
                if ((longitude < - 180.0) || (longitude > 180.0)) {
                        printf("\nInvalid longitude: %f\n", longitude);
                        return 2;
                }
        }
        puts("\n]");
        
        return 0;
}
