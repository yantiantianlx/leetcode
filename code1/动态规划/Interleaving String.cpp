#include <iostream>
#include <string>
#include <vector>
using namespace std;

//´íÎó
class Solution1 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.empty()) return s1.empty() && s2.empty();
		int index_i = 0;
		int index_j = 0;
		for(int n = 0; n <  s3.size(); n++){
			if (!s1.empty() && index_i < s1.size() && s1[index_i] == s3[n])
			{
				index_i++;
			}
			else if (!s2.empty() && index_j < s2.size() && s2[index_j] == s3[n])
			{
				index_j++;
			}
			else
				return false;
		}
		return true;
	}
};

class Solution{
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.empty()) return s1.empty() && s2.empty();
		if (s3.size() != s1.size() + s2.size()) return false;
		int n1 = s1.size();
		int n2 = s2.size();
		vector<vector<bool>> f(n1+1, vector<bool>(n2+1, false));
		f[0][0] = true;
		for (int i = 1; i <= n2; i++)
			f[0][i] = (s2[i-1] == s3[i-1]) && f[0][i-1];
		for (int i = 1; i <= n1; i++)
			f[i][0] = (s1[i-1] == s3[i-1]) && f[i-1][0];
		for(int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++) {
				f[i][j] = ((s1[i - 1] == s3[i + j - 1]) && f[i - 1][j]) ||
					((s2[j - 1] == s3[i + j - 1]) && f[i][j - 1]);
			}
		return f[n1][n2];
	}
};
//
//int main() {
//	Solution s;
//	s.isInterleave("db","b","cbb");
//}
