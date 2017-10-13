#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.size() < 4) return result;
		vector<string> path;
		get_ip(s, 0,0, result, path);
		return result;
	}
	void get_ip(string s, int start, int step, vector<string>& result, vector<string>& path) {
		if (start == s.size() && step == 4) {
			string str;
			for (auto p : path)
				str += (p + ".");
			str.erase(str.end() - 1);
			result.push_back(str);
		}
		for (int i = start; i < s.size(); i++) {
			if (is_valid(s.substr(start, i - start + 1)) && step < 4) {
				path.push_back(s.substr(start, i - start + 1));
				get_ip(s, i + 1, step + 1, result, path);
				path.pop_back();
			}
			else
				return;
				
		}
	}
	//判断子串是否为有效数字
	bool is_valid(string sub) {
		int num = atoi(sub.c_str());
		if (sub[0] == '0' && num != 0) return false;//010
		if (sub[0] == '0' && num == 0 && sub.size() > 1) return false; // 00
		if (num >= 0 && num <= 255)
			return true;
		return false;
	}
};

//int main() {
//	Solution s;
//	s.restoreIpAddresses("010010");
//	cin.get();
//}