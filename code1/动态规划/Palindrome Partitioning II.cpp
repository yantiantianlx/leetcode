#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		if (n <= 1) return 0;
		vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
		vector<int> f(n, INT_MAX);
		for(int i = n-1; i >=0; i--)
			for (int j = i; j < n; j++) {
				if (i == j)
					is_palindrome[i][j] = true;
				else if (i + 1 == j)
					is_palindrome[i][j] = s[i] == s[j];
				else 
					is_palindrome[i][j] = s[i] == s[j] && is_palindrome[i + 1][j - 1];
				
				if (is_palindrome[i][j]) {
					if (j == n - 1)
						f[i] = 0;
					else
						f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		return f[0];
	}
};
//int main() {
//	string str = "aabcb";
//	Solution s;
//	cout<<s.minCut(str);
//	cin.get();
//	return 0;
//}