#include<stdio.h>

/*
*Sudoku Solver using Backtracking.
*/
bool unassigned(int sudoku_grid[4][4]){
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(sudoku_grid[i][j] == 0)
				return true;
	return false;
}


/*
* Checks if the corresponsing row has the number
*/

bool check_if_number_in_row(int sudoku_grid[4][4],int row,int column,int num){
	int i,j;
	for(i=row;;)
		for(j=0;j<4;j++)
			if(sudoku_grid[i][j] == num)
				return true;
	return false;
}

/*
* Checks if the corresponsing column has the number
*/
bool check_if_number_in_column(int sudoku_grid[4][4],int row,int column,int num){
	int i,j;
	for(i=0;i<4;i++)
		for(j=column;;)
			if(sudoku_grid[i][j] == num)
				return true;
	return false;
}


/*
* Checks if the corresponsing box has the number
*/





// Main Function to solve sudoku, using backtracking technique.
bool solve_sudoku(int sudoku_grid[4][4]){
	int row, column;
	if(!unassigned(sudoku_grid))
		return true;
}

int main(){

	int sudoku_grid[4][4]= {{0,0,3,4},{3,4,0,0},{0,0,4,3},{0,3,2,0}};
	solve_sudoku(sudoku_grid);
	return 0;
}
