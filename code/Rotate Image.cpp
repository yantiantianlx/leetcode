#include "Header.h"
#include <algorithm>
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		//�ضԽ��߷�ת
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - i; j++)
				swap( matrix[i][j], matrix[n - 1 - j][n - 1 - i] );
		//ˮƽ��ת
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n; j++)
				swap( matrix[i][j], matrix[n - 1 - i][j] );		
	}
};