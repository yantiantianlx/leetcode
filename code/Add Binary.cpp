#include "Header.h"

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int c = 0;

		for (auto i = a.rbegin(), j = b.rbegin();
			i < a.rend() || j < b.rend();
			i = (i < a.rend() ? ++i : a.rend()),
			j = (j < b.rend() ? ++j : b.rend())
			){
			int v1 = i == a.rend() ? '0' : *i;
			int v2 = j == b.rend() ? '0' : *j;
			int v = (v1 + v2 + c - 2 * '0') % 2;
			c = (v1 + v2 + c - 2 * '0') / 2;
			result.insert(result.begin(),v + '0' );
		}
		if (c > 0) result.insert(result.begin(), c + '0');
		return result;
	}
};

//void main(){
//	Solution s;
//	s.addBinary("11", "1");
//}