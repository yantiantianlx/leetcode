#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int ns = s.size();
		int nt = t.size();
		vector<vector<int>> f(ns+1, vector<int>(nt+1, 0));
		for (int i = 0; i <= ns; i++)
			f[i][0] = 1;
		for (int i = 1; i <= ns; i++)
			for (int j = 1; j <= nt; j++)
				if (s[i - 1] == t[j - 1])
					f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
				else
					f[i][j] = f[i - 1][j];
		return f[ns][nt];
	}
};

class Solution1 {
public:
	int numDistinct(string s, string t) {
		int ns = s.size();
		int nt = t.size();
		vector<int> f(nt + 1, 0);
		f[0] = 1;
		for (int i = 0; i < ns; i++)
			for (int j = nt-1; j >= 0; j--)
				f[j+1] += s[i] == t[j] ? f[j]:0;
		return f[nt];
	}
};