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
				//���룬��ֵ��ͬ����һ�𣬼�ֵ��˳������
				sum.insert( make_pair((nums[i] + nums[j]), make_pair(i, j)) );//��¼���������
			}

		for (auto i = sum.begin(); i != sum.end(); i++){
			int x = target - i->first;
			//find�ҵ�key��λ�ü�ֹͣ
			//auto range = sum.find(x);
			auto range = sum.equal_range(x);//�ҵ���Χ����Χ֮�䲻���ڴ�С��ϵ����Ϊ����Ϊmultimap��˿��Ա����ֵ�ظ�������
			cout << typeid(range).name() << endl;
			for (auto j = range.first; j != range.second; j++){
				int a = i->second.first;
				int b = i->second.second;
				int c = j->second.first;
				int d = j->second.second;
				//a!=c&&b!=d��ֹ�ҵ�������0��0��
				//a!=d&&b!=c��ֹͬһ����ʹ�ö�Σ�Ĭ�����������ظ����ݣ���-3��-1����-1��5��ԭ����Ϊ��-3��-1��0��2��4��5��
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
