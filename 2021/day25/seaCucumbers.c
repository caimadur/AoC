// https://adventofcode.com/2021/day/25

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct floor {
    char *row;
    struct floor *south;
};


static void
debug(struct floor *a, size_t n)
{
    struct floor *b = a->south;

    printf("%zu\n", n);
    printf("%s", a->row);
    while (b != a) {
    	printf("%s", b->row);
    	b = b->south;
    }
    putchar('\n');
}


int
main()
{
    char *line = NULL, *firstline = NULL, *flcp = NULL, *flscp = NULL;
    size_t linecap = 0, step = 0;
    ssize_t linelen, ll;
    struct floor *start, *fl;
    int move = 1;

    if ((linelen = getline(&line, &linecap, stdin)) <= 0)
    	exit(1);
    if ((start = malloc(sizeof(struct floor))) == NULL)
    	exit(2);
    start->row = line;
    line = NULL;
    fl = start;

    while ((ll = getline(&line, &linecap, stdin)) > 0) {
    	if ((fl->south = malloc(sizeof(struct floor))) == NULL)
    	    exit(2);
    	fl = fl->south;
    	fl->row = line;
    	line = NULL;
    }
    fl = fl->south = start;

    if ((firstline = malloc(sizeof(char) * linelen)) == NULL)
    	exit(2);
    if ((flcp = malloc(sizeof(char) * linelen)) == NULL)
    	exit(2);
    if ((flscp = malloc(sizeof(char) * linelen)) == NULL)
    	exit(2);

    while (move) {
    	move = 0;
	do {
	    char first = fl->row[0];

	    for (size_t i = 0; fl->row[i] != '\n'; i++)
		if (fl->row[i] == '>') {
		    if (fl->row[i + 1] == '.') {
			fl->row[i++] = '.';
			fl->row[i] = '>';
			move = 1;
		    } else if (fl->row[i + 1] == '\n' && first == '.') {
			fl->row[i] = '.';
			fl->row[0] = '>';
			move = 1;
		    }
		}
	    fl = fl->south;
	} while (fl != start);
	
	strcpy(firstline, fl->row);
	strcpy(flcp, fl->row);
	do {
	    if (fl->south == start)
	    	strcpy(flscp, firstline);
	    else 
	    	strcpy(flscp, fl->south->row);
	    for (size_t i = 0; fl->row[i] != '\n'; i++)
		if (flcp[i] == 'v' && flscp[i] == '.') {
		    fl->row[i] = '.';
		    fl->south->row[i] = 'v';
		    move = 1;
		}
	    fl = fl->south;
	    strcpy(flcp, flscp);
	} while (fl != start);

	step++;
    }

    printf("No sea cucumber moves on step %zu.\n", step);

    free(firstline);
    free(flcp);
    free(flscp);
    fl = start->south;
    start->south = NULL;
    while (fl != NULL) {
    	start = fl;
    	fl = fl->south;
    	free(start->row);
    	free(start);
    }
}
