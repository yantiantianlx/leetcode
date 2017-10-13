#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string result;
		if (path.empty()) return result;
		int n = path.size();
		stack<string> res;
		for (int i = 0; i < n;) {
			while (i < n && path[i] == '/') i++;
			if (i >= n)break;
			int now = i;
			while (i < n && path[i] != '/') i++;
			string substr = path.substr(now, i - now);
			if (substr == ".." && !res.empty())
				res.pop();
			else if (substr != "." && substr != "..")
				res.push(substr);
		}
		if (res.empty())
			result = "/";
		else {
			while (!res.empty()) {
				result.insert(0, "/" + res.top());
				res.pop();
			}
		}
		return result;
	}
};