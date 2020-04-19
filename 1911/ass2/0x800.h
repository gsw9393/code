#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Currently the program is setup to have the board automatically 
//  print out "over itself" (some magic) so that it feels more like
//  a game. If you set Debug to be "1" (i.e. true) then the program
//  will stop doing this, and print out all output sequentially.
//  It will look like printing out each board line after line.
//  This is VERY!!!!!!!! useful for debugging
#define DEBUG 0

// This only prints the game out as text
#define TEXT_ONLY 0

// Standard TRUE and FALSE definitions
//  to make code easier to read
#define TRUE 1
#define FALSE 0

// Size of the board. You CAN edit this if you want,
//  but at your own peril. It's kind of fun, though.
#define SIZE 4

// The following just abstracts the particular
//  ascii characters for keyboard left, right, up, and
//  down arrows.
#define KEYBOARD_LEFT 'a'
#define KEYBOARD_RIGHT 'd'
#define KEYBOARD_UP 'w'
#define KEYBOARD_DOWN 's'

// These are the typedefs for the type of an individual CELL
//  (which is just a string) and the BOARD which is a 2D array
//  that contains type cells
typedef char *cell;
typedef cell **Board;


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//            You can ignore everything below here

// These functions are used by your program and they are implemented else
//  where. You do not need to worry about these functions
void ignoreThisFunction1(Board board, int seed, int size, int debug, int textonly);
void ignoreThisFunction2(Board board);
void ignoreThisFunction3(Board board);
void drawBoard(Board board);
void addRandom(Board board);
int gameEnded(Board board);
void printfGame(char *str);
void setAntiCrashMode(int mode);
char getcharX(void);

// You can safely ignore this
#ifdef WIN32
#include <conio.h>
#define getchar _getch
#endif

// These are the function prototypes used in this program
//  for part 1.
Board newBoard();
int populateBoard(Board board, int argc, char* argv[]);
int getSeed(int argc, char* argv[]);
void freeBoard(Board board);

// These are the function prototypes used in this program
//  for part 2.
int moveUp(Board board);
int moveLeft(Board board);
int moveDown(Board board);
int moveRight(Board board);

void setAntiCrashMode(int mode);
char getcharX(void);
