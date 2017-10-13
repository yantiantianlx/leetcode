#include "Header.h"

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used[9];
		for (int i = 0; i < 9; i++){
			fill(used, used + 9, false);
			//检查9行
			for (int j = 0; j < 9; j++)
				if (!check(board[i][j], used))
					return false;
			//检查9列
			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++)
				if (!check(board[j][i], used))
					return false;
		}
			//检查3*3格
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++){
					fill(used, used + 9, false);

					for (int k = i * 3; k < i * 3 + 3; k++)
						for (int z = j * 3; z < j * 3 + 3; z++)
							if (!check(board[k][z], used))
								return false;
				}

			return true;
	}

private:
	bool check(char ch, bool* used){
		if (ch == '.') return true;
		if (used[ch - '1']) return false;
		return used[ch - '1'] = true;
	}
};