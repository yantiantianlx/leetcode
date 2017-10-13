#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution1 {
public:
	bool isScramble(string s1, string s2) {
		return isScramble(s1.begin(), s1.end(), s2.begin());
	}
	template<typename iterator>
	bool isScramble(iterator first1, iterator last1, iterator first2) {
		int length = last1 - first1;
		if (length == 1) return *first1 == *first2;
		for (int i = 2; i <= length; i++)
			if ( (isScramble(first1, first1 + i, first2)
				&& isScramble(first1 + i, last1, first2 + i) )
				|| (isScramble(first1, first1 + i, first2 + length - i)
					&& isScramble(first1 + i, last1, first2)))
				return true;
		return false;
	}
};

class Solution {
public:
	bool isScramble(string s1, string s2) {
		int length = s1.end() - s1.begin();
		if (length < 1) return true;
		vector<vector<vector<bool>>> f(length, vector<vector<bool>>(length, vector<bool>(length, false)));
		
		for (int i = 0; i < length; i++)
			for (int j = 0; j < length; j++)
				f[0][i][j] = s1[i] == s2[j];

		for (int n = 1; n < length; n++)
			for (int i = 0; i < length-n; i++)
				for (int j = 0; j < length-n; j++)
					for (int k = 0; k < n; k++) {
						f[n][i][j] = f[k][i][j] && f[n - k - 1][i + k + 1][j + k + 1] ||
							f[k][i][j + n - k] && f[n - k - 1][i + k + 1][j];
						if (f[n][i][j] == true)
							break;//不break，后面会覆盖
					}
						

		return f[length-1][0][0];
	}
};
//
//int main() {
//	Solution s;
//	cout<<s.isScramble("great", "rgaet");
//	cin.get();
//	return 0;
//}