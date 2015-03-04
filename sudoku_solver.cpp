#include<stdio.h>
/*
*Sudoku Solver using Backtracking.
*/
bool unassigned(int sudoku_grid[4][4],int &row,int &column){
	int i,j;
	for(row=0;row<4;row++)
		for(column=0;column<4;column++)
			if(sudoku_grid[row][column] == 0)
				return true;
	return false;
}
/*
* Checks if the corresponsing row has the number
*/
bool check_if_number_in_row(int sudoku_grid[4][4],int row,int column,int num){
	int i,j;
		for(j=0;j<4;j++)
			if(sudoku_grid[row][j] == num)
				return true;
	return false;
}
/*
* Checks if the corresponsing column has the number
*/
bool check_if_number_in_column(int sudoku_grid[4][4],int row,int column,int num){
	int i,j;
	for(i=0;i<4;i++)
			if(sudoku_grid[i][column] == num)
				return true;
	return false;
}
/*
* Checks if the corresponsing box has the number
*/
bool check_if_number_in_box(int sudoku_grid[4][4],int row,int column,int num){
 int i,j;
 for (i = 0; i < 2; i++)
  for (j = 0; j < 2; j++)
   if (sudoku_grid[i+row][j+column] == num)
    return true;
 return false; 
}
/*
* Checks if the number is valid to be allocated in a particular cell.
*/
bool check_if_valid(int sudoku_grid[4][4],int row,int column,int num){
 if(!(check_if_number_in_row(sudoku_grid,row,column,num)) && !(check_if_number_in_column(sudoku_grid,row,column,num)) && !(check_if_number_in_box(sudoku_grid,row - row%2 , column - column%2,num))){
  return true;
  }
 return false;
}
/*
* Main Function to solve sudoku, using backtracking technique.
*/
bool solve_sudoku(int sudoku_grid[4][4]){
	int row, column;
	if(!unassigned(sudoku_grid,row,column)){
		return true;
	}
	int num;
	for(num = 1; num <= 4 ; num ++){
	 if(check_if_valid(sudoku_grid,row,column,num)){
	  sudoku_grid[row][column] = num;
	  if(solve_sudoku(sudoku_grid))
	   return true;
	  sudoku_grid[row][column] = 0;
	 }
	}
	return false;
}
int main(){
	int sudoku_grid[4][4]= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if(solve_sudoku(sudoku_grid) == true){
	 printf("Solved SUDOKU grid");
	 int i,j;
	 for(i=0;i<4;i++){
	  for(j=0;j<4;j++){
	   printf("%d\t",sudoku_grid[i][j]);
	  }
	  printf("\n");
	 }
	}
	else
	 printf("No valid Solutions");
	return 0;
}
