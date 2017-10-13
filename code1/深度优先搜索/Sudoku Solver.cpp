#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		Sudoku(board);
	}
	bool Sudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] == '.') {
					for (int k = 0; k < 9; k++) {
						board[i][j] = k + '1';
						if (is_valid(board, i, j) && Sudoku(board))
							return true;
						else
							board[i][j] = '.';
					}
					if (board[i][j] == '.')
						return false;
				}

		return true;
	}
	bool is_valid(vector<vector<char>>& board, int row, int col) {
		for (int i = 0; i < 9; i++)
			if (i != row && board[i][col] == board[row][col])
				return false;
		for (int j = 0; j < 9; j++)
			if (j != col && board[row][j] == board[row][col])
				return false;
		int start_r = (row / 3) * 3;
		int start_c = (col / 3) * 3;
		for (int i = start_r; i < (start_r + 3); i++)
			for(int j = start_c; j < (start_c + 3); j++)
				if (i != row && j != col && board[i][j] == board[row][col])
					return false;
		return true;
	}
};

