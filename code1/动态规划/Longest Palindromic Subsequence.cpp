#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		vector<vector<int>> f(n, vector<int>(n, 0));
		for(int i = n-1; i >= 0; i--)
			for (int j = i; j >=0; j--) {
				if (i == j) f[i][j] = 1;
				if(i == j-1) 
				else {
					if (s[i] == s[j])
						f[i][j] = f[i + 1][j - 1] + 2;
					else
						f[i][j] = max(f[i + 1][j], f[i][j - 1]);
				}
			}
	}
};