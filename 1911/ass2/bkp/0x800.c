/*
 ============================================================================
 Name        : 0x800.c
 Author      : Hayden Smith; Maurits van der Schee
 Description : Hex based console version of the game "2048" for GNU/Linux
 ============================================================================
 */

// This is your standard includes for external modules
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This includes a special file used for this assignment 
//  that was made for COMP1911
#include "0x800.h"

int main(int argc, char *argv[]) {
	char c;
	int success;
	int seed = getSeed(argc, argv);
	int finishedGame = FALSE;

	Board board = newBoard();
	
	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	//setAntiCrashMode(1);
	ignoreThisFunction1(board, seed, SIZE, DEBUG, TEXT_ONLY);

	// The function to populate the board from the command line
	//  argument is called. If there is no argument in command line
	//  then two random 
	int boardWasPopulated = populateBoard(board, argc, argv);
	if (!boardWasPopulated) {
		addRandom(board);
		addRandom(board);
	}

	drawBoard(board);
	ignoreThisFunction2(board);
	
	// Continually executing the game loop until the game is finished
	while (!finishedGame) {
		c = getcharX();
		success = FALSE;

		// Check what kind of key press was made using getchar
		if (c == KEYBOARD_LEFT) {
			success = moveLeft(board);
		} else if (c == KEYBOARD_RIGHT) {
			success = moveRight(board); 
		} else if (c == KEYBOARD_UP) {
			success = moveUp(board);
		} else if (c == KEYBOARD_DOWN) {
			success = moveDown(board);
		} else if (c == 'q') {
			printfGame(">> QUIT? (y/n)");
			c = getcharX();
			if (c == 'y') {
				finishedGame = TRUE;
			} else {
				drawBoard(board);
			}
		}

		// If a move key was pressed and the board was actually moved,
		//  then draw the board again, add a new random ell, draw the
		//  board again, and check if the game is finished
		if (success) {
			drawBoard(board);
			addRandom(board);
			drawBoard(board);
			if (gameEnded(board)) {
				printfGame(">> GAME OVER");
				finishedGame = TRUE;
			}
		}

		// Do not move, replace, rename, or delete this function.
		// It carries out some necessary magic - be nice to it!
		ignoreThisFunction2(board);
	}

	// Because the game is finished, we need to call a function
	//  that frees the board pointer, then set that board pointer to NULL
	//  to ensure that no one can accidentally use free'd memory.
	freeBoard(board);
	board = NULL;

	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	ignoreThisFunction3(board);

	return 0;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 1 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.


// You need to malloc some memory (hint: most likely requiring multiple
//  malloc's), set all values in the board to be default to NULL, then
//  return a pointer to the board.
Board newBoard() {
	return NULL; // not ideal
}

// The pointer to your board needs to be free'd. Before you free "board"
//  you also need to make sure you free any other memory you've malloced
//  that are contained within board
void freeBoard(Board board) {

}

// The second argument passed into the program is the "input string". For
//  more information on this please see the assignment specification.
int populateBoard(Board board, int argc, char* argv[]) {
	return FALSE;
}

// THIS FUNCTION IS ALREADY COMPLETE, IT IS HERE PURELY FOR DEMONSTRATION
// The first argument passed into the program is the "seed" for the
//  random number generator (that you don't have to worry about)
int getSeed(int argc, char* argv[]) {
	int ret = FALSE;
	if (argc == 2) {
		ret = atoi(argv[1]);
	}
	return ret;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 2 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.
// You are welcome to write/define more functions of your own and include
//  them in this section. In fact - we encourage you to write more of your
//  own functions down here.

// Function moves all of the cells to the very bottom
//  of the board. During the process any two cells that are
//  adjacent in the vertical direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveUp(Board board) {
	return TRUE;
}

// Function moves all of the cells to the very bottom
//  of the board. During the process any two cells that are
//  adjacent in the vertical direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveDown(Board board) {
	return TRUE;
}

// Function moves all of the cells to the very left hand
//  side of the board. During the process any two cells that are
//  adjacent in the horizontal direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveLeft(Board board) {
	return TRUE;
}

// Function moves all of the cells to the very right hand
//  side of the board. During the process any two cells that are
//  adjacent in the horizontal direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveRight(Board board) {
	return TRUE;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 3 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You probably don't need to write any code down here, you can just
//  write it into the main function.

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 4 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You will need to write code down here AND inside the main function.
// We have not given you any starter code for this section. You will
//  have to start your own
