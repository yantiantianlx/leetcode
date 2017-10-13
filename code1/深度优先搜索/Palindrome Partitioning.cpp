#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;
		string substr = "";
		dfs(s,0, path, result);
		return result;
	}
	void dfs(string s, int start, vector<string>& path, vector<vector<string>>& result) {
			
		if (start == s.size()) {
			result.push_back(path);
			return;
		}
			
		for (int i = start; i < s.size(); i++) {
			if (is_palindrome(s, start, i )) {
				string sub = s.substr(start, i + 1-start);
				path.push_back(sub);
				dfs(s, i + 1, path, result);
				path.pop_back();
			}
		}
	}
	bool is_palindrome(string s, int start, int i) {
		auto begin = s.begin() + start, end = s.begin() + i;
		while (begin <= end && end > s.begin() && begin < s.end()) {
			if (*begin != *end)
				return false;
			begin++;
			end--;
		}
		return true;
	}
};

//int main() {
//	string st = "aab";
//	cout << st.substr(1, 1);
//	Solution s;
//	vector<vector<string>> b = s.partition("aab");
//	cin.get();
//	return 0;
//}