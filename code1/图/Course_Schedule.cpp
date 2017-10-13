#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//拓扑排序
		unordered_map<int, unordered_set<int>> in_node;
		vector<int> in_node_zeros;
		vector<int> in_node_not_zeros;
		//初始化，入度都为0
		for (int i = 0; i < numCourses; i++)
			in_node_zeros.push_back(i);
  		for (int i = 0; i < prerequisites.size(); i++) {
			in_node[prerequisites[i].first].insert(prerequisites[i].second);
			auto not_zeros_index = find(in_node_zeros.begin(), in_node_zeros.end(), prerequisites[i].first);
			//删除入度不为零的节点
			if (not_zeros_index != in_node_zeros.end())
				in_node_zeros.erase(not_zeros_index);
			if(find(in_node_not_zeros.begin(), in_node_not_zeros.end(), prerequisites[i].first) == in_node_not_zeros.end())
				in_node_not_zeros.push_back(prerequisites[i].first);
		}
		while (!in_node_zeros.empty()) {
			//找到入度为0的节点，删除，并在in_node中删除该边
			int in_node_zero = in_node_zeros[0];
			in_node_zeros.erase(in_node_zeros.begin());
			for (int i = 0; i < in_node_not_zeros.size(); i++) {
				if (in_node[in_node_not_zeros[i]].find(in_node_zero) != in_node[in_node_not_zeros[i]].end())
					in_node[in_node_not_zeros[i]].erase(in_node_zero);
				if (in_node[in_node_not_zeros[i]].empty()) {
					in_node_zeros.push_back(in_node_not_zeros[i]);
					in_node.erase(in_node_not_zeros[i]);
					in_node_not_zeros.erase(in_node_not_zeros.begin()+i);
					i--;
				}
			}
		}
		if (!in_node.empty())
			return false;
		else
			return true;			
	}
};

void main() {
	vector<pair<int, int>> a = { {2,1},{2,0} };
	Solution s;
	cout<<s.canFinish(3, a);
	cin.get() ;
}