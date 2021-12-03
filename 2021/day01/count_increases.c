#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int
main()
{
    long int num, last = -1;
    int counter = -1; // no special case for first line
    char *line = 0;
    size_t linecap = 0;
    ssize_t linelen;

    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
    	num = strtol(line, NULL, 10);
    	if (num > last)
    	    counter++;
	last = num;
    }

    printf("%d measurements were bigger than the previous one.\n", counter);
}

