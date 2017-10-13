#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> buf;
		int max_length = 0;
		int last = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				buf.push(i);
			else {
				if (buf.empty())
					last = i;
				else {
					buf.pop();
					if (buf.empty())
						max_length = max(max_length, i - last);
					else
						max_length = max(max_length, i - buf.top());
				}
			}
		}
		return max_length;
	}
};