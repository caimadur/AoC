/*
 * https://adventofcode.com/2021/day/4
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

struct board {
    int nums[5][5];
    int marks[5][5];
    struct board *nxt;
};


static int
iswinner(struct board *b, size_t r, size_t c)
{
    int i = 0;
    while (b->marks[r][i] != -1)
    	i++;
    if (i == 5)
    	return 1;
    for (i = 0; i < 5; i++)
	if (b->marks[i][c] == -1)
	    return 0;
    return 2;
}

static int
score(struct board *b)
{
    int sum = 0;
    for (size_t r = 0; r < 5; r++)
    	for (size_t c = 0; c < 5; c++)
    	    if (b->marks[r][c] == -1)
    	    	sum += b->nums[r][c];
    return sum;
}

static void
printboard(struct board *b)
{
    for (size_t r = 0; r < 5; r++) {
    	for (size_t c = 0; c < 5; c++)
    	    if (b->marks[r][c] == -1)
    	    	printf(" %2d", b->nums[r][c]);
	    else
	    	printf(" %c[7m%2d%c[27m", 27, b->marks[r][c], 27);
	printf("\n");
    }
}


int
main()
{
    char *firstline = NULL, *line = NULL, *start;
    size_t linecap = 0;
    ssize_t linelen;
    struct board *boards = NULL, *b, *winner = NULL;
    int factor = 0;

    if ((linelen = getline(&firstline, &linecap, stdin)) <= 0)
    	exit(1);

    while (getline(&line, &linecap, stdin) > 0) {
	b = boards;
	if ((boards = malloc(sizeof(struct board))) == NULL)
	    exit(2);
	boards->nxt = b;
	for (size_t row = 0; row < 5; row++)
	    for (size_t col = 0; col < 5; col++)
	    	boards->marks[row][col] = -1;
	for (size_t row = 0; row < 5; row++) {
	    int B, I, N, G, O;
	    getline(&line, &linecap, stdin);
	    if (sscanf(line, "%d %d %d %d %d ", &B, &I, &N, &G, &O) < 5)
	    	exit(3);
	    boards->nums[row][0] = B;
	    boards->nums[row][1] = I;
	    boards->nums[row][2] = N;
	    boards->nums[row][3] = G;
	    boards->nums[row][4] = O;
	}
    }
    free(line);

    start = firstline;
    while (winner == NULL) {
    	char *end;
    	long int n;

    	errno = 0;
    	n = strtol(start, &end, 10);
    	if (errno)
    	    exit(4);
    	if (start == end)
    	    exit(5);
    	if (*end == ',')
    	    start = end + 1;
	else
	    start = end;
    	b = boards;
    	while (b != NULL) {
    	    for (size_t row = 0; row < 5; row++)
    	    	for (size_t col = 0; col < 5; col++)
    	    	    if (n == b->nums[row][col]) {
    	    	    	b->marks[row][col] = (int)n;
    	    	    	if (iswinner(b, row, col)) {
			    winner = b;
			    factor = (int)n;
			}
		    }
	    b = b->nxt;
	}
    }

    printboard(winner);
    printf("Lösung: %d\n", score(winner) * factor);

    free(firstline);

    while (boards != NULL) {
    	b = boards->nxt;
    	free(boards);
    	boards = b;
    }
}
