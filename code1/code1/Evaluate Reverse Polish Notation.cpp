#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> buf;
		for (auto str : tokens) {
			if (str.find_first_of("0123456789")!=string::npos)
				buf.push(stoi(str));
			else {
				int a = buf.top();//第二操作数
				buf.pop();
				int b = buf.top();//第一操作数
				buf.pop();
				switch (str[0]) {
					case '+': a = b + a; break;
					case '-': a = b - a; break;
					case '*': a = b * a; break;
					case '/': a = b / a; break;
				}
				buf.push(a);
			}
		}
		return buf.top();
	}
};

//void main() {
//	vector<string> a = { "-3","-4","+" };
//	Solution s;
//	s.evalRPN(a);
//}