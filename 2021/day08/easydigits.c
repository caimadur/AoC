/*
 * https://adventofcode.com/2021/day/8
 */

#include <stdio.h>


int
main()
{
    int c, outval = 0, len = 0, num = 0;

    while ((c = getchar()) != EOF) {
    	if (outval) {
    	    switch (c) {
		case '\n':
		    outval = 0;
		    // fallthrough
		case ' ':
		    if (len == 2 || len == 4 || len == 3 || len == 7)
		    	num++;
		    len = 0;
		    break;
		default:
		    len++;
	    }
	} else {
	    if (c == '|')
	    	outval = 1;
	}
    }

    printf("Found 1, 4, 7 or 8 %d times\n", num);
}
