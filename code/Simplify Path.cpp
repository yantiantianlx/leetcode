#include "Header.h"

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> r;
		auto first = find(path.begin(), path.end(), '/');
		while (first < path.end()-1){
			auto second = find(first+1, path.end(),'/');
			//ȡ����/�м�����ַ���
			string s = path.substr(first-path.begin(),second-first);
			if (s == "/.." && !r.empty())
				r.pop_back();
			else if (s == "/." || s == "/");
			else
				r.push_back(s);
			first = second;
		}
		string result;
		for (auto i : r)
			result += i;
		return result;
	}
};

//void main(){
//	Solution s;
//	s.simplifyPath("/home/c");
//	system("pause");
//}
