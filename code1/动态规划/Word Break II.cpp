#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> result;
		if (s.empty()) return result;
		unordered_set<string> dict;
		for (auto w : wordDict)
			dict.insert(w);
		int n = s.size();
		vector<bool> f(n+1, false);
		vector<vector<bool>> p(n, vector<bool>(n, false));
		f[0] = true;
		for(int i = 0; i < n; i++)
			for (int j = i; j >= 0; j--) {
				if (f[j] && dict.find(s.substr(j, i - j + 1)) != dict.end()) {
					f[i+1] = true;
					p[j][i] = true;
				}
			}
		vector<string> path;
		getPath(s, p, 0, result, path);
		return result;
	}
	void getPath(string& s, vector<vector<bool>>& p, int start, vector<string>& result, vector<string>& path) {
		if (start == s.size()) {
			string str = "";
			for (int i = 0; i < path.size(); i++) {
				str += (i == 0 ? path[i] : " " + path[i]);
			}
			result.push_back(str);
			return;
		}
		for (int i = start; i < s.size(); i++) {
			if (p[start][i]) {
				path.push_back(s.substr(start, i - start + 1));
				getPath(s, p, i+1, result, path);
				path.pop_back();
			}

		}
	}
};

int main() {
	vector<string> a = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
	Solution s;
	s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", a);

}