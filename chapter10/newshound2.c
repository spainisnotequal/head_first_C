/*
 * Program to learn about system calls
 */

/* Depends of a Python script called "rssgossip.py", we can download it from:
   https://github.com/dogriffiths/rssgossip/zipball/master
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


void error(const char *msg)
{
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
}


int main (int argc, char *argv[])
{
        const char *phrase = argv[1];
        const char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml",
                              NULL};
        FILE *f = fopen("stories.txt", "w");

        if (!f) {
                error("Can't open stories.txt");
        }

        pid_t pid = fork();
        if (pid == -1) {
                error("Can't fork process");
        }
        if (!pid) {
                if (dup2(fileno(f),1) == -1) {
                        error("Can't redirect Standard Output");
                }
                if (execle("/usr/bin/python", "/usr/bin/python",
                           "./rssgossip.py", phrase, NULL, vars) == -1) {
                        error("Can't run script");
                }
        }

        return 0;
}
