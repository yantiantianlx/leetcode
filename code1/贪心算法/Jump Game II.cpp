#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
	//动规,超时
	int jump(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		vector<int> f(n, n);//记录每点到终点的最短距离
		f[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			int jump = nums[i];
			if (jump + i >= n) {
				f[i] = 1;
				continue;
			}
			while (jump > 0) {
				f[i] = min(f[i], f[i+jump--]+1);
			}
		}
		return f[0];
	}
};

class Solution {
public:
	//笨死了
	int jump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return 0;
		int reach = 0, jump = 1;
		int reach_next = 0;
		for (int i = 0; i < nums.size(); i++) {
			reach_next = max(reach_next, i + nums[i]);
			if (reach_next >= nums.size()-1)
				break;
			if (i == 0 || i >= reach) {
				jump++;
				reach = reach_next;
			}
		}
		return jump;
	}
};

//int main() {
//	vector<int > a = { 1,2 };// = { 2,3,1,7,6,15,1,0,2,1,0,1,3 };
//	Solution s;
//	cout << s.jump(a) << endl;
//	cin.get();
//	return 0;
//}