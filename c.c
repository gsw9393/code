#include <stdio.h>

typedef struct Coord {
    int x;
    int y;
    int z;
} Coord;

int main(void) {
	
    Coord coords[10];
    Coord a = { .x = 5, .y = 6, .z = 7 };
    Coord b = { .x = 3, .y = 3, .z = 3 };
    Coord *p = &a;

    /*** A ***/
    (*p).x = 6;
    p->y++;
    p->z++;
    b = *p;
    /*** B ***/


    return 0;
}