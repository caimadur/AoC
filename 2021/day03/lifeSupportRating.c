/*
 * https://adventofcode.com/2021/day/3#part2
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct number {
    char *no;
    struct number *nxt;
};


static struct number*
addnumber(struct number *append, char *text)
{
    struct number *new;
    
    if ((new = malloc(sizeof(struct number))) == NULL)
    	exit(1);
    new->no = text;
    new->nxt = append;
    return new;
}

static int
countbits(struct number *n, int pos)
{
    int r = 0;
    while (n != NULL) {
   	if (n->no[pos] == '1')
    	    r++;
	else
	    r--;
	n = n->nxt;
    }
    return r;
}

static struct number*
deletenumbers(struct number *n, int pos, char c)
{
    struct number *head, *d;

    while (n != NULL && n->no[pos] == c) {
    	d = n;
    	n = n->nxt;
    	free(d->no);
    	free(d);
    }
    head = n;
    while (n->nxt != NULL)
    	if (n->nxt->no[pos] == c) {
    	    d = n->nxt;
    	    n->nxt = d->nxt;
    	    free(d->no);
    	    free(d);
	} else
	    n = n->nxt;
    return head;
}

static void
debug(struct number *n)
{
    puts("--debug--\n");
    while (n != NULL) {
    	printf("%s", n->no);
    	n = n->nxt;
    }
    puts("---------\n\n");
}


int
main()
{
    struct number *onelist = NULL, *zerolist = NULL, *ogr, *csr;
    int onecount = 0, zerocount = 0, i = 1;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    long int ogrn, csrn;

    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
    	if (line[0] == '1') {
    	    ++onecount;
    	    onelist = addnumber(onelist, line);
	} else {
	    ++zerocount;
	    zerolist = addnumber(zerolist, line);
	}
	line = NULL;
    }

    if (onecount >= zerocount) {
    	ogr = onelist;
    	csr = zerolist;
    } else {
    	ogr = zerolist;
    	csr = onelist;
    }

    while (ogr->nxt != NULL) {
    	if (i == linelen)
    	    exit(2);
	if (countbits(ogr, i) >= 0)
	    ogr = deletenumbers(ogr, i, '0');
	else
	    ogr = deletenumbers(ogr, i, '1');
	i++;
    }
    ogrn = strtol(ogr->no, NULL, 2);
    free(ogr->no);
    free(ogr);

    i = 1;
    while (csr->nxt != NULL) {
    	if (i == linelen)
    	    exit(2);
	if (countbits(csr, i) < 0)
	    csr = deletenumbers(csr, i, '0');
	else
	    csr = deletenumbers(csr, i, '1');
	i++;
    }
    csrn = strtol(csr->no, NULL, 2);
    free(csr->no);
    free(csr);

    puts("Oxigen generator rating x CO2 scrubber rating:");
    printf("%ld x %ld = %ld\n", ogrn, csrn, ogrn * csrn);
}
