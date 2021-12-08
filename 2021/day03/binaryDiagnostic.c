#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int
main()
{
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    int *counter;
    size_t i;
    int γ = 0, ε = 0;
    char c;

    if ((linelen = getline(&line, &linecap, stdin)) <= 0)
    	exit(1);
    if ((counter = malloc((linelen - 1) * sizeof(int))) == NULL)
    	exit(2);
    for (i = 0; i < linelen - 1; i++)
    	if (line[i] == 1)
    	    counter[i] = 1;
	else
	    counter[i] = -1;
    i = 0;
    while ((c = getchar()) != EOF)
    	switch(c) {
	    case '1':
	    	counter[i++] += 1;
	    	break;
	    case '0':
	    	counter[i++] -= 1;
	    	break;
	    default:
	    	i = 0;
	}
    for (i = 0; i < linelen - 1; i++) {
    	γ <<= 1;
    	ε <<= 1;
    	if (counter[i] == 0) {
	    γ += 1;
	    // ε += 1;
	}
	else if (counter[i] > 0)
    	    γ += 1;
	else
	    ε += 1;
    }
    printf("gamma rate x epsilon rate: %d x %d = %d\n", γ, ε, γ * ε);
}
