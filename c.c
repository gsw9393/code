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
    int *p = &coords[0].x;
    int *q = &coords[9].z+1;
    int i = 0;
    while(i<10){
        coords[i].x=i+1;
        coords[i].y=i+1;
        coords[i].z=i+1;
        i++;
    }
    for(i=0; i<10; i++){
        printf ("%d,%d,%d\n",coords[i].x,coords[i].y,coords[i].z);
    }
    while(p!=q){
        *p=11;
        p++;
    }
    for(i=0; i<10; i++){
        printf ("%d,%d,%d\n",coords[i].x,coords[i].y,coords[i].z);
    }
    return 0;
}