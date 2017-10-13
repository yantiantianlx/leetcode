#include "Header.h"

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int r = matrix.size();
		if (r < 0) return;
		int c = matrix[0].size();
		//第一行第一列是否有0
		bool row_has_zero = false;
		bool col_has_zero = false; 
		for (int j = 0; j < c; j++)
			if (matrix[0][j] == 0){
				row_has_zero = true;
				break;
			}

		for (int i = 0; i < r; i++)
			if (matrix[i][0] == 0){
				col_has_zero = true;
				break;
			}

		//每行每列是否有0用第一行第一列记录
		for (int i = 1; i < r; i++)
			for (int j = 1; j < c; j++)
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
			}
		//根据第一行第一列记录的信息设置元素为0
		for (int i = 1; i < r; i++)
			for (int j = 1; j < c; j++)
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;

		//根据bool变量的记录，判断第一行第一列是否设为0
		if (row_has_zero)
			for (int j = 0; j < c; j++)
				matrix[0][j] = 0;
		if (col_has_zero)
			for (int i = 0; i < r; i++)
				matrix[i][0] = 0;

	}
};