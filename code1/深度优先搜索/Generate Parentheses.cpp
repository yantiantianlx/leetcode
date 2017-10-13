#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n < 1) return result;
		string path;
		get_par(n, 0, 0, result, path);
		return result;
	}
	void get_par(int n, int left, int right, vector<string>& result, string& path) {
		if (left == n) {
			string str(path);
			result.push_back(str.append(n-right, ')'));
			return;
		}
		path.push_back('(');
		get_par(n, left + 1, right, result, path);
		path.pop_back();

		if (right < left) {
			path.push_back(')');
			get_par(n, left, right+1, result, path);
			path.pop_back();
		}
	}
};

//int main() {
//	Solution s;
//	s.generateParenthesis(3);
//}