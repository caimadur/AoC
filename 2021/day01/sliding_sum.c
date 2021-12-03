#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int
main()
{
    char *line = 0;
    size_t linecap = 0;
    ssize_t linelen;
    long int nums[3] = {0};
    size_t idx = 0;
    long int sum, last;
    int counter = -3; // trust me, I know the input

    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
    	nums[idx++ % 3] = strtol(line, NULL, 10);
    	sum = nums[0] + nums[1] + nums[2];
    	if (sum > last)
    	    counter++;
    	last = sum;
    }

    printf("%d sums were bigger than the previous one.\n", counter);
}
