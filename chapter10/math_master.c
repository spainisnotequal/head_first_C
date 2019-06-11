/*
 * Program to learn about signals
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int SCORE = 0;

void end_game (int sig)
{
        printf("\nFinal score: %i\n", SCORE);
        exit(0);
}

int catch_signal (int sig, void (*handler)(int))
{
        struct sigaction action;
        action.sa_handler = handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;

        return sigaction (sig, &action, NULL);
}

void times_up (int sig)
{
        puts("\nTIME'S UP!");
        raise(SIGINT);
}

int main (void)
{
        catch_signal(SIGALRM, times_up);
        catch_signal(SIGINT, end_game);

        srandom (time(0));

        int a;
        int b;
        char txt[4];
        int answer;

        while(1) {
                a = random() % 11;
                b = random() % 11;
                alarm(5);
                printf("\nWhat is %i times %i? ", a, b);
                fgets(txt, 4, stdin);
                answer = atoi(txt);
                if (answer == a * b) {
                        SCORE++;
                } else {
                        printf("\nWrong! Score: %i\n", SCORE);
                }
        }

        return 0;
}
