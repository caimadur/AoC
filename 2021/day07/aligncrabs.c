/*
 * https://adventofcode.com/2021/day/7#part2
 */

#include <stdio.h>
#include <stdlib.h>    

struct position {
    int pos;
    struct position *nxt;
};

int
main()
{
    struct position *pos = NULL, *p;
    int n, sum = 0, num = 0, avg, fuel = 0;

    while (scanf("%d,", &n) == 1) {
	p = pos;
	pos = malloc(sizeof(struct position));
	pos->pos = n;
	pos->nxt = p;
    	sum += n;
	num++;
    }
    avg = sum / num; // + 1; // rounding differences

    p = pos;
    while (p != NULL) {
    	int dif = avg > p->pos ? avg - p->pos : p->pos - avg;
    	fuel += dif & 1 ? dif * (dif / 2 + 1) : dif * dif / 2 + dif / 2;
    	p = p->nxt;
    	free(pos);
    	pos = p;
    }

    printf("Fuel spent moving to %d: %d\n", avg, fuel);
}
