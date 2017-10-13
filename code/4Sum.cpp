#include "Header.h"
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		//sort(nums.begin(), nums.end());

		unordered_multimap<int, pair<int, int>> sum;
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++){
				//插入，键值相同的在一起，键值非顺序排列
				sum.insert( make_pair((nums[i] + nums[j]), make_pair(i, j)) );//记录和与坐标对
			}

		for (auto i = sum.begin(); i != sum.end(); i++){
			int x = target - i->first;
			//find找到key的位置即停止
			//auto range = sum.find(x);
			auto range = sum.equal_range(x);//找到范围，范围之间不存在大小关系，因为定义为multimap因此可以保存键值重复的数据
			cout << typeid(range).name() << endl;
			for (auto j = range.first; j != range.second; j++){
				int a = i->second.first;
				int b = i->second.second;
				int c = j->second.first;
				int d = j->second.second;
				//a!=c&&b!=d防止找到自身，（0，0）
				//a!=d&&b!=c防止同一数据使用多次，默认数组中无重复数据？（-3，-1）（-1，5）原数组为【-3，-1，0，2，4，5】
				if (a != c && a != d && b != c && b != d){
					vector<int> r = { nums[a], nums[b], nums[c], nums[d] };
					sort(r.begin(), r.end());
					result.push_back(r);
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};
