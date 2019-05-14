/*
 * Program to learn about the qsort function in the C standard library
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct rectangle {
        int width;
        int height;
};

int compare_scores (const void *score_a, const void *score_b)
{
        int a = *(int *)score_a;
        int b = *(int *)score_b;
        return a - b;
}

int compare_scores_desc (const void *score_a, const void *score_b)
{
        int a = *(int *)score_a;
        int b = *(int *)score_b;
        return b - a;
}

int compare_areas (const void *a, const void *b)
{
        struct rectangle *ra = (struct rectangle *)a;
        struct rectangle *rb = (struct rectangle *)b;
        int area_a = ra->width * ra->height;
        int area_b = rb->width * rb->height;
        return area_a - area_b;
}

int compare_names (const void *a, const void *b)
{
        char **sa = (char **)a;
        char **sb = (char **)b;
        return strcmp(*sa, *sb);
}

int compare_areas_desc(const void *a, const void *b)
{
        return compare_areas(b, a);
}

int compare_names_desc (const void *a, const void *b)
{
        return compare_names(b, a);
}

int main (void)
{
        // Compare integers:
        int scores[] = {543,323,32,554,11,3,112};
        int i;

        qsort(scores, 7, sizeof(int), compare_scores_desc);

        puts("These are the scores in order:");
        for (i = 0; i < 7; i++) {
                printf("Score = %i\n", scores[i]);
        }

        // Compare strings:
        char *names[] = {"Karen", "Mark", "Brett", "Molly"};
        
        qsort(names, 4, sizeof(char *), compare_names);
        
        puts("These are the names in order:");
        for (i = 0; i < 4; i++) {
                printf("%s\n", names[i]);
        }

        // Compare structures:
        struct rectangle r1 = {
                r1.width = 1,
                r1.height  = 1
        };
        struct rectangle r2 = {
                r2.width = 1,
                r2.height  = 3
        };
        struct rectangle r3 = {
                r3.width = 2,
                r3.height  = 1
        };
        struct rectangle rectangles[] = {r1, r2, r3};

        qsort(rectangles, 3, sizeof(struct rectangle), compare_areas);

        puts("These are the rectangles in order:");
        for (i = 0; i < 3; i++) {
                printf("Area = %d (width = %d, height = %d)\n",
                       rectangles[i].width * rectangles[i].height,
                       rectangles[i].width,
                       rectangles[i].height);
        }
                       
        return 0;
}
