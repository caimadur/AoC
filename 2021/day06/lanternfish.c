/*
 * https://adventofcode.com/2021/day/6
 */

#include <stdlib.h>
#include <stdio.h>

#define DAYS 80

int
main()
{
    int cycle[9] = {0};
    int d, new, sum = 0;

    while (scanf("%d,", &d) == 1)
    	    cycle[d]++;

    for (int day = 0; day < DAYS; day++) {
    	new = cycle[0];
    	for (int i = 0; i < 8; i++)
    	    cycle[i] = cycle[i + 1];
    	cycle[6] += new;
    	cycle[8] = new;
    }

    for (int i = 0; i < 9; i++)
    	sum += cycle[i];

    printf("There would be %d lanternfish after %d days.\n", sum, DAYS);
}
