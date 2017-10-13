#include "Header.h"

class Solution {
public:
	string longestPalindrome(string s) {
		string s1 = s;
		preprocess(s);
		vector<int> P(s.size());
		int RtMax = 0;
		int Center = 0;
		for (int i = 1; i < s.size() - 1; i++){
			if (i < RtMax){
				int i_mirror = 2 * Center - i;
				int gap = RtMax - i;
				if (P[i_mirror] < gap)
					P[i] = P[i_mirror];
				else{
					P[i] = gap;
					while (i + P[i] + 1 >= 0 && i - P[i] - 1 < s.size() &&
						s[i + P[i] + 1] == s[i - P[i] - 1]) P[i]++;
					Center = i;
					RtMax = i + P[i];
				}
			}
			//i在RtMax的右边
			else{
				P[i] = 0;
				while (i + P[i] + 1 >= 0 && i - P[i] - 1 < s.size() &&
					s[i + P[i] + 1] == s[i - P[i] - 1]) P[i]++;
				Center = i;
				RtMax = Center + P[i];
			}
		}

		//找到最大的P[i]
		int max = 0;
		for (int i = 0; i < s.size(); i++){
			if (P[i] > max){
				Center = i;
				max = P[i];
			}
		}

		return s1.substr((Center - max)/2, max);//substr(起始位置，长度)
	}

private:
	//插入#
	string preprocess(string& s){
		for (int i = 0; i < s.size(); i = i + 2){
			s.insert(s.begin() + i,'#');
		}
		s = s + '#';
		return s;
	}
};

//void main(){
//	Solution s;
//	string as = s.longestPalindrome("ccc");
//}