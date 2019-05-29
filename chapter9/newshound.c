/*
 * Program to learn about system calls
 */

/* We have to download the Python script from this address:
   https://github.com/dogriffiths/rssgossip/zipball/master
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main (int argc, char *argv[])
{
        const char *feeds[] = {"http://feeds.bbci.co.uk/news/rss.xml",
                               "https://www.economist.com/britain/rss.xml"};
        size_t times = 2;
        char *phrase = argv[1];
        
        for (size_t i = 0; i < times; i++) {
                char var[255];
                sprintf(var, "RSS_FEED=%s", feeds[i]);
                char *vars[] = {var, NULL};
                if (execle("/usr/bin/python", "/usr/bin/python",
                           "./rssgossip.py", phrase, NULL, vars) == -1) {
                        fprintf(stderr, "Can't run script: %s\n", strerror(errno));
                        return 1;
                }}

        return 0;
}
