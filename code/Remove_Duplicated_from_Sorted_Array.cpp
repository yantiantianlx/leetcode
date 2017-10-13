#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//26题

class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		//nums=[1,1,2,2,3,4]变为[1,2,3,4,1,2]
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};

class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) { 
		//nums=[1,1,2,2,3,4]变为[1,2,3,4]
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return distance(nums.begin(), nums.end());
	}
};

class Solution3 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int index = 0;
		for (int i = 1; i < nums.size();i++){
			if (nums[index] != nums[i]){
				nums[++index] = nums[i];
			}
		}				
		return index + 1;
	}
};



