#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict;
		for (auto w : wordDict)
			dict.insert(w);
		int n = s.size();
		vector<bool> f(n + 1, false);
		f[0] = true;
		for (int i = 1; i <= n; i++)
			for (int j = i - 1; j >= 0; j--) {
			string sub = s.substr(j, i-j);
			if (dict.find(sub) != dict.end() && f[j]) {
				f[i] = f[j];
				break;
			}	
		}
		return f[n];
	}
};

//int main() {
//	vector<string> d = { "aaaa","aaa" };
//	Solution s;
//	cout<<s.wordBreak("aaaaaaa", d);
//	cin.get();
//	return 0;
//}