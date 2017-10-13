#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int cur = 1;
		int pre = 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '0') cur = 0;
			if (s[i - 1] == '0' || !(s[i - 1] <= '2' && s[i] <= '6') )
				pre = 0;
			int temp = cur;
			cur += pre;
			pre = temp;
		}
		return cur;
	}
};

//int main() {
//	Solution s;
//	cout<<s.numDecodings("110");
//	cin.get();
//	return 0;
//}