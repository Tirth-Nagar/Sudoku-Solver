#include <stdio.h>
#include <stdlib.h>

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

int main() {

	int sudoku[9][9];
	char input[] = "..9..5.1.85.4....2432......1...69.83.9.....6.62.71...9......1945....4.37.4.3..6..";
	
	initializeBoard(sudoku, input);
	// printBoard(sudoku);

	return 0;
}
