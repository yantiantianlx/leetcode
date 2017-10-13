#include "Header.h"
#include <algorithm>

class Solution {
public:
	bool isPalindrome(string s) {
		//×ª»»ÎªÐ¡Ð´×ÖÄ¸
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		auto left = s.begin();
		auto right = s.end() - 1;
		while (left <= right){
			while (left <= right && !::isalnum(*left))	left++;
			while (left <= right && !::isalnum(*right))	right--;
			if (left <= right){
				if( *left == *right){left++;right--;}
				else return false;
			}
		}
		return true;
	}
};

//void main(){
//	Solution s;
//	s.isPalindrome("......a.....");
//}