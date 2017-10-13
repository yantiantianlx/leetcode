#include "Header.h"
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		for (auto str : strs){
			string s = str;
			sort(s.begin(), s.end());
			if (m.find(s) == m.end()){
				vector<string> v;
				v.push_back(str);
				m.insert(make_pair(s,v));
			}	
			else
				m[s].push_back(str);
		}
		vector<vector<string>> result;
		for (auto i : m){
			result.push_back(i.second);
		}
		return result;
	}
};
