#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		string left="({[";
		string right = ")}]";
		stack<char> buf;
		for (auto c : s) {
			if (left.find(c)!=string::npos)
				buf.push(c);
			else {
				if (!buf.empty() && c == right[left.find(buf.top())])
					buf.pop();
				else
					return false;
			}
		}
		if(buf.empty())
			return true;
		else return false;
	}
};
//
//void main() {
//	Solution s;
//	cout << s.isValid("(){}[]") << endl;
//	system("pause");
//}