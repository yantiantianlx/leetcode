#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		
		if (beginWord == endWord) return 1;
		//定义变量
		//unordered_map<string, vector<string>> graph;//构建图
		unordered_map<string, int> is_visited;//有无被访问过, 不存在就是没有访问过
		queue<string> que;//广度搜索队列
		unordered_map<string, int> level;//节点深度
		for (auto s : wordList)
			is_visited.insert(make_pair(s, 0));
		//初始化
		que.push(beginWord);
		is_visited.insert(make_pair(beginWord, 1));
		level.insert(make_pair(beginWord, 1));

		//广度搜索
		while (!que.empty()) {
			string s = que.front();
			que.pop();
			//变换字母
			for (auto c = s.begin(); c < s.end(); c++) {
				int ytt = 1;
				for (auto c_swap = 'a'; c_swap <= 'z'; c_swap++) {
					string s_swap = s;
					if (c_swap != *c) {
						s_swap[c-s.begin()]= c_swap;
						if (is_visited.find(s_swap)!= is_visited.end() && is_visited[s_swap]==0) {
							if (s_swap == endWord)
								return level[s] + 1;
							//变换字母后的单次存在列表
							que.push(s_swap);
							is_visited[s_swap] = 1;
							level.insert(make_pair(s_swap, level[s] + 1));
						}	
					}
				}
			}
		}
		return 0;
	}
};

//int main() {
//	vector<string> listword = { "hot","dot","dog","lot","log" };
//	Solution s;
//	cout<< s.ladderLength("hit", "cog", listword);
//	cin.get();
//	return 0;
//}