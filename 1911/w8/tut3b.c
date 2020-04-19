#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100 //Points to read
//struct
typedef struct points Point;
struct points{
	double x,y; 
};
//function prototypes
int readPoints(Point points[], int maxPoints);
void printPoints(Point points[], int maxPoints);
Point furthestFromOrigin(Point points[], int totalPoints);
double distO( Point p);

//main function
int main (void){
	freopen("c.txt", "r", stdin); //for stdin from txt file
	Point p1[MAX];
	int totalPoints=readPoints(p1,MAX);
	printf("Points read = %d\n",totalPoints);
	printPoints(p1,totalPoints);
	Point fPoint=furthestFromOrigin(p1,totalPoints);
	printf("Point farthest from origin= (%.1lf,%.1lf)\n",fPoint.x,fPoint.y);
	return 0;
}

//functions
int readPoints(Point points[], int maxPoints){
	double x,y;
	int i=0;
	while(scanf ("%lf %lf",&x,&y)==2&&i<maxPoints){
		points[i].x=x;
		points[i].y=y;
		i++;
	}
	return i;
}
void printPoints(Point points[], int maxPoints){
	int i;
	for (i=0 ; i<maxPoints ; i+=1){
		printf("(%.1lf,%.1lf)\n",points[i].x,points[i].y);
	}
}
Point furthestFromOrigin(Point points[],int totalPoints){
	int i,j=0;
	double len=0;
	for (i=0 ; i<totalPoints ; i+=1){
		if(distO(points[i])>len){
			len=distO(points[i]);
			j=i;
		}
	}
	return points[j];
}
double distO(Point p) {
  return(sqrt(p.x*p.x+p.y*p.y));
}