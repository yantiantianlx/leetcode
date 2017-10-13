#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> f(num+1, 0);
		if (num == 0) return f;
		f[1] = 1;
		int next_boundary_index = 2;
		int next_boundary = pow(2,2);
		int now_boundary = pow(2, 1);
		for (int i = 2; i <= num; i++) {
			if (i == next_boundary) {
				now_boundary = next_boundary;
				next_boundary_index++;
				next_boundary = pow(2, next_boundary_index);
				
			}
			f[i] = f[i-now_boundary]+1;
		}
		return f;
	}
};