/*
 * https://adventofcode.com/2021/day/5
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


struct ycoordinate {
    int y;
    int count;
    struct ycoordinate *nxt;
};

struct xcoordinate {
    int x;
    struct ycoordinate *ys;
    struct xcoordinate *nxt;
};


static struct ycoordinate*
newyc(int y, struct ycoordinate *nxt)
{
    struct ycoordinate *new = malloc(sizeof(struct ycoordinate));
    new->y = y;
    new->nxt = nxt;
    new->count = 1;
    return new;
}

static struct xcoordinate*
newxc(int x, int y, struct xcoordinate *nxt)
{
    struct xcoordinate *new = malloc(sizeof(struct xcoordinate));
    new->x = x;
    new->nxt = nxt;
    new->ys = newyc(y, NULL);
    return new;
}

static struct xcoordinate*
addvent(struct xcoordinate *origin, int x, int y)
{
    struct xcoordinate *xptr;
    struct ycoordinate *yptr;

    if (origin == NULL || origin->x > x) {
    	origin = newxc(x, y, origin);
    	return origin;
    }

    xptr = origin;
    while (xptr->nxt != NULL && xptr->nxt->x <= x)
    	xptr = xptr->nxt;

    if (xptr->x < x) {
	xptr->nxt = newxc(x, y, xptr->nxt);
	return origin;
    }

    if (xptr->ys->y > y) {
	xptr->ys = newyc(y, xptr->ys);
	return origin;
    }

    yptr = xptr->ys;
    while (yptr->nxt != NULL && yptr->nxt->y <= y)
    	yptr = yptr->nxt;

    if (yptr->y < y)
    	yptr->nxt = newyc(y, yptr->nxt);
    else
    	yptr->count += 1;

    return origin;
}

static int
countmultivents(struct xcoordinate *xc)
{
    struct ycoordinate *yc;
    int n = 0;

    while (xc != NULL) {
    	yc = xc->ys;
    	while (yc != NULL) {
    	    if (yc->count > 1)
    	    	n++;
    	    yc = yc->nxt;
	}
	xc = xc->nxt;
    }
    return n;
}

static void
deletecoords(struct xcoordinate *xc)
{
    struct ycoordinate *yc;

    while (xc != NULL) {
    	struct xcoordinate *delx = xc;
    	yc = xc->ys;
    	while (yc != NULL) {
    	    struct ycoordinate *dely = yc;
    	    yc = yc->nxt;
    	    free(dely);
	}
	xc = xc->nxt;
	free(delx);
    }
}


int
main()
{
    struct xcoordinate *coord = NULL;
    int x1, x2, y1, y2, result;

    while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) == 4) {
	int xstep = 0, ystep = 0;
	
	assert(x1 == x2 || y1 == y2 || x1 - x2 == y1 - y2 || x1 - x2 + y1 - y2 == 0);

	// only consider horizontal and vertical lines
	if (x1 != x2 && y1 != y2)
	    continue;

	if (x1 < x2)
	    xstep = 1;
	else if (x1 > x2)
	    xstep = -1;
	if (y1 < y2)
	    ystep = 1;
	else if (y1 > y2)
	    ystep = -1;

	coord = addvent(coord, x1, y1);
	while (x1 != x2 || y1 != y2) {
	    x1 += xstep;
	    y1 += ystep;
	    coord = addvent(coord, x1, y1);
	}
    }
    
    result = countmultivents(coord);
    printf("The number of points where at least two lines overlap is %d.\n", result);

    deletecoords(coord);
}
    
