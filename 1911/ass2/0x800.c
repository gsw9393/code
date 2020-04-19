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

void powtohexstr(int c, cell str);
void dubhex(cell str);

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
		} else if (c == 'r') {
			printfGame(">> RESET? (y/n)");
			c = getcharX();
			if (c == 'y') {
				freeBoard(board);
				board = newBoard();
				boardWasPopulated = populateBoard(board, argc, argv);
				if (!boardWasPopulated) {
					
					addRandom(board);
					addRandom(board);
				}
				drawBoard(board);
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

	Board myboard=(Board)malloc(sizeof(cell*)*SIZE);
	if (myboard == NULL) {
		printf("malloc error");
        exit(0);
	}
	int i,j;
	for (i=0 ; i<SIZE ; i+=1){
		myboard[i]=(cell*)malloc(sizeof(cell)*SIZE);
		if (myboard[i] == NULL) {
			printf("malloc error");
    		exit(0);
		}
		for (j=0 ; j<SIZE ; j+=1){
			myboard[i][j]=NULL;
		}
	}
	return myboard;
}
// The pointer to your board needs to be free'd. Before you free "board"
//  you also need to make sure you free any other memory you've malloced
//  that are contained within board
void freeBoard(Board board) {
	int i,j;
	for (i=0 ; i<SIZE ; i+=1){
		for (j=0 ; j<SIZE ; j+=1){
			if(board[i][j]!=NULL){
				free(board[i][j]);
			}
		}
		if (board[i]!=NULL){
			free(board[i]);
		}
	}
	free(board);
}
// The second argument passed into the program is the "input string". For
//  more information on this please see the assignment specification.

int populateBoard(Board board, int argc, char* argv[]) {
	
	int ret = FALSE;
	
	if (argc==3&&strlen(argv[2])==SIZE*SIZE){//checks for valid input
		int i,j,k;
		k=0;
		for (i=0 ; i<SIZE ; i+=1){
			for (j=0 ; j<SIZE ; j+=1){	
				if(argv[2][k]!='0'){//ignores zeros
					//mallocs cells
					board[i][j]=(cell)malloc(sizeof(char)*(SIZE+2));
					if (board[i][j]==NULL){
					printf ("malloc error");
					exit(1);
					}					
					powtohexstr(argv[2][k],board[i][j]);//puts string in cell 
				}
				k++;
			}
		}
		ret = TRUE;
	//print error message if input invalid
	}else if(argc==3&&strlen(argv[2])!=SIZE*SIZE){
		printf("Please enter a valid populate string\n");
		exit(1);
	}
	return ret;
}
//Ahmed function.
void powtohexstr(int c, cell str){
	int x,y;
	if(c>='0'&&c<='9'){// convert char 0-9 to integer
		y=c-'0';
	}else{
		y=c-'A'+10;// convert char A,B to integer
	}
	x=pow(2.0,y);//raises 2 to power of the integer
	sprintf(str,"0x%x",x);// turns to hex string and stores in pointed string
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

// Function moves all of the cells to the very top
//  of the board. During the process any two cells that are
//  adjacent in the vertical direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveUp(Board board) {
	
	int strt=0;
	int end=SIZE-1;
	int row,col,pos;
	int check = FALSE;
	//Slide cells up
	//starting from top to bottom
	//move first non-empty cell to 1st position
	//move second non-empty cell to 2nd position etc
	//Hence slides all non-empty cell up
	for(col=strt ; col<=end ; col++){//column left to right
		for(row=strt,pos=strt ; row<=end ; row++){//row top to bottom
			if (board[row][col]!=NULL){//checks if cell has data
				if(row!=pos){//checks if already in desired position
					board[pos][col]=board[row][col];//moves cell to position
					board[row][col]=NULL;//sets moved cell to empty
					check = TRUE;
				}
				pos++;//position increments if cell moved 
				
			}
		}
	}
	//Merge up
	//Compares cell with cell below, if equal, doubles the data in cell below
	//then moves all cells below up one, including the modified cell.
	int i;
	for(col=strt ; col<=end ; col++){//column left to right
		for(row=strt ; row<=end-1 ; row++){//row top to 1 before bottom
			if (board[row+1][col]!=NULL//check if cell below is empty
			    &&strcmp(board[row][col],board[row+1][col])==0){//compare value with cell below

				dubhex(board[row+1][col]);//doubles data in cell below 
				i=row;//saves current position
				//move cells up one
				for (row=i ; row<=end-1 ; row++){//row current to 1 before bottom
					board[row][col]=board[row+1][col];//move cell below to current cell
					board[row+1][col]=NULL;//empty moved cell
				}
				row=i;//returns current position
				check = TRUE;
			}
		}
	}
	return check;
}
int moveDown (Board board) {
	
	int strt=0;
	int end=SIZE-1;
	int row,col,pos;
	int check = FALSE;
	//Slide cells down
	//starting from bottom to top
	//move first non-empty cell to 1st position
	//move second non-empty cell to 2nd position etc
	//Hence slides all non-empty cell down
	for(col=strt ; col<=end ; col++){//column left to right
		for(row=end,pos=end ; row>=strt ; row--){//row bottom to top
			if (board[row][col]!=NULL){//checks if cell has data
				if(row!=pos){//checks if already in desired position
					board[pos][col]=board[row][col];//moves cell to position
					board[row][col]=NULL;//sets moved cell to empty
					check = TRUE;
				}
				pos--;//position increments if cell moved 
			}
		}
	}
	//Merge down
	//Compares cell with cell above, if equal, doubles the data in cell above
	//then moves all cells above down one, including the modified cell.
	int i;
	for(col=strt ; col<=end ; col++){//column left to right
		for(row=end ; row>=strt+1 ; row--){//row bottom to 1 before top
			//printf ("(%d,%d)",row,col);
			if (board[row][col]!=NULL&&board[row-1][col]!=NULL//check if cell above is empty
			    &&strcmp(board[row][col],board[row-1][col])==0){//compare value with cell above
				//printf ("(%d,%d) - %d",row,col,strcmp(board[row][col],board[row-1][col]));
				dubhex(board[row-1][col]);//doubles data in cell above 
				i=row;//saves current position
				//move cells down one
				for (row=i ; row>=strt+1 ; row--){//row current to 1 before top
					board[row][col]=board[row-1][col];//move cell above to current cell
					board[row-1][col]=NULL;//empty moved cell
				}
				row=i;//returns current position
				check = TRUE;
			}

		}
	}
		return check;
}
int moveLeft (Board board) {
	
	int strt=0;
	int end=SIZE-1;
	int row,col,pos;
	int check = FALSE;
	//Slide cells left
	//Starting left to right
	//move first non-empty cell to 1st position
	//move second non-empty cell to 2nd position etc
	//Hence slides all non-empty cell left
		
	for(row=strt ; row<=end ; row++){//row top to bottom
		for(col=strt,pos=strt ; col<=end ; col++){//column left to right
			if (board[row][col]!=NULL){//checks if cell has data
				if(col!=pos){//checks if col already in desired position
					board[row][pos]=board[row][col];//moves cell to position
					board[row][col]=NULL;//sets moved cell to empty
					check = TRUE;
				}
				pos++;//position increments if cell moved 
			}
		}
	}
	//Merge left
	//Compares cell with cell to right, if equal, doubles the data in cell to right
	//then moves all cells to right to left one, including the modified cell.
	int i;
	for(row=strt ; row<=end ; row++){//row top to bottom
		for(col=strt ; col<=end-1 ; col++){//column left to 1 before right end
			//printf ("(%d,%d)",row,col);
			if (board[row][col]!=NULL&&board[row][col+1]!=NULL//check if cell to right is empty
			    &&strcmp(board[row][col],board[row][col+1])==0){//compare value with cell to right
				//printf ("(%d,%d) - %d",row,col,strcmp(board[row][col],board[row-1][col]));
				dubhex(board[row][col+1]);//doubles data in cell to right
				i=col;//saves current position
				//move cells left one slot
				for (col=i ; col<=end-1 ; col++){//col current to 1 before right end
					board[row][col]=board[row][col+1];//move cell to right to current cell
					board[row][col+1]=NULL;//empty moved cell
				}
				col=i;//returns current position
				check = TRUE;
			}

		}
	}
		return check;
}
int moveRight (Board board) {
	
	int strt=0;
	int end=SIZE-1;
	int row,col,pos;
	int check = FALSE;
	//Slide cells right
	//Starting right to left
	//move first non-empty cell to 1st position
	//move second non-empty cell to 2nd position etc
	//Hence slides all non-empty cell right
		
	for(row=strt ; row<=end ; row++){//row top to bottom
		for(col=end,pos=end ; col>=strt ; col--){//column right to left 
			if (board[row][col]!=NULL){//checks if cell has data
				if(col!=pos){//checks if col already in desired position
					board[row][pos]=board[row][col];//moves cell to position
					board[row][col]=NULL;//sets moved cell to empty
					check = TRUE;
				}
				pos--;//position increments if cell moved 
			}
		}
	}
	//Merge right
	//Compares cell with cell to left, if equal, doubles the data in cell to left
	//then moves all cells to the left, right one slot, including the modified cell.
	int i;
	for(row=strt ; row<=end ; row++){//row top to bottom
		for(col=end ; col>=strt+1 ; col--){//column right to 1 before left end
			//printf ("(%d,%d)",row,col);
			if (board[row][col]!=NULL&&board[row][col-1]!=NULL//check if cell to left is empty
			    &&strcmp(board[row][col],board[row][col-1])==0){//compare value with cell to right
				//printf ("(%d,%d) - %d",row,col,strcmp(board[row][col],board[row-1][col]));
				dubhex(board[row][col-1]);//doubles data in cell to left
				i=col;//saves current position
				//move cells right one slot
				for (col=i ; col>=strt+1 ; col--){//col current to 1 before left end
					board[row][col]=board[row][col-1];//move cell to left of current cell
					board[row][col-1]=NULL;//empty moved cell
				}
				col=i;//returns current position
				check = TRUE;
			}

		}
	}
		return check;
}
//Ahmed function.
void dubhex(cell str){
	int i;
	if (str!=NULL){
		i=strtol(str, NULL, 16);
	i=i*2;
	sprintf(str,"0x%x",i);
	}
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
