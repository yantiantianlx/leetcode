#include "Header.h"

class Solution1 {
public:
	int strStr(string haystack, string needle) {
		int s = 0;//记录相等的位置，便于再返回来
		int ptr = 0;
		int str = 0;
		int flag = 0;
		while (haystack[str]){
			if (!needle[ptr])
				break;
			if (haystack[str] != needle[ptr]){
				ptr = 0;
				if (flag){
					str = s;	flag = 0;
				}
				str++;
			}
			else{
				if (!flag){
					s = str;	flag = 1;
				}
				str++;	ptr++;
			}
		}
		if (needle[ptr])
			return -1;
		else
			return str - ptr;
	}
};

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int N = haystack.size() - needle.size() + 1;

		for (int i = 0; i < N; i++){
			int j = i;
			int k = 0;
			while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]){
				j++;
				k++;
			}
			if (k == needle.size()) return i;
		}
		return -1;
	}
};
//void main(){
//	Solution s;
//	cout << s.strStr("hello word!o w o", "o w o") << endl;
//	system("pause");
//
//}