/*
 * https://adventofcode.com/2021/day/8#part2
 */

#include <stdio.h>
#include <string.h>


static int
is_subset(char *sub, char *big)
{
    for (size_t i = 0; sub[i] != '\0'; i++) {
    	int missing = 1;
    	for (size_t j = 0; big[j] != '\0'; j++)
    	    if (big[j] == sub[i]) {
    	    	missing = 0;
    	    	break;
	    }
	if (missing)
	    return 0;
    }
    return 1;
}


int
main()
{
    char signal[10][8], *pattern[10], output[4][8];
    int sum = 0;

    while (scanf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s", 
    		signal[0], signal[1], signal[2], signal[3], signal[4], signal[5],
    		signal[6], signal[7], signal[8], signal[9], output[0], output[1],
    		output[2], output[3]) == 14) {
    	size_t digit = 0;

    	for (size_t i = 0; i < 10; i++) {
    	    if (strlen(signal[i]) == 2)
    	    	pattern[1] = signal[i];
	    else if (strlen(signal[i]) == 3)
	    	pattern[7] = signal[i];
	    else if (strlen(signal[i]) == 4)
	    	pattern[4] = signal[i];
	    else if (strlen(signal[i]) == 7)
	    	pattern[8] = signal[i];
	}

	for (size_t i = 0; i < 10; i++) {
	    if (strlen(signal[i]) == 6) {
	    	if (is_subset(pattern[4], signal[i]))
		    pattern[9] = signal[i];
		else if (is_subset(pattern[1], signal[i]))
		    pattern[0] = signal[i];
		else
		    pattern[6] = signal[i];
	    }
	}

	for (size_t i = 0; i < 10; i++) {
	    if (strlen(signal[i]) == 5) {
	    	if (is_subset(pattern[1], signal[i]))
		    pattern[3] = signal[i];
		else if (is_subset(signal[i], pattern[9]))
		    pattern[5] = signal[i];
		else
		    pattern[2] = signal[i];
	    }
	}

	for (size_t i = 0; i < 4; i++)
	    for (size_t j = 0; j < 10; j++)
	    	if (strlen(output[i]) == strlen(pattern[j]) && is_subset(output[i], pattern[j]))
	    	    digit = digit * 10 + j;

	sum += digit;
    }

    printf ("All output adds up to: %d\n", sum);
}
