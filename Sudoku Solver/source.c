#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initializeBoard(int sudoku[9][9], char input[81]) {

	int iter = 0;

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (input[iter] == '.') {
				sudoku[row][col] = 0;
			}
			else {
				sudoku[row][col] = (int)(input[iter] - '0');
			}
			iter++;
		}
	}

}

void printBoard(int sudoku[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}
}

bool isValid(int sudoku[9][9], int row, int col, int choice) {
	
	// check if choice exists in col
	for (int r = 0; r < 9; r++) {
		if (choice == sudoku[r][col]) {
			return false;
		}
	}

	// check if choice exists in row
	for (int c = 0; c < 9; c++) {
		if (choice == sudoku[row][c]) {
			return false;
		}
	}

	// check if choice exists in 3x3 grid
	int start_row = (row / 3) * 3;
	int start_col = (col / 3) * 3;
	
	for (int r = start_row; r < start_row + 3; r++) {
		for (int c = start_col; c < start_col + 3; c++) {
			if (choice == sudoku[r][c]) {
				return false;
			}
		}
	}

	return true;
}

bool solve(int sudoku[9][9], int r, int c) {

	if (r == 9) {
		return true;
	}
	else if (c == 9) {
		return solve(sudoku, r + 1, 0);
	}
	else if (sudoku[r][c] != 0) {
		return solve(sudoku, r, c + 1);
	}
	else {
		for (int choice = 1; choice < 10; choice++) {
			if (isValid(sudoku, r, c, choice)) {
				sudoku[r][c] = choice;
				if (solve(sudoku, r, c + 1)) {
					return true;
				}
				sudoku[r][c] = 0;
			}
		}
		return false;
	}
}


int main() {

	int sudoku[9][9];
	char input[] = "..9..5.1.85.4....2432......1...69.83.9.....6.62.71...9......1945....4.37.4.3..6..";
	
	initializeBoard(sudoku, input);
	// printBoard(sudoku);

	solve(sudoku, 0, 0);

	printBoard(sudoku);

	return 0;
}
