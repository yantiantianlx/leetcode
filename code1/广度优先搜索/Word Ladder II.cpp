#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord == endWord)
			return vector<vector<string>> { {beginWord} };
		//构建变量
		queue<vector<string>> result;
		result.push(vector<string> {beginWord});
		unordered_map<string,int> is_have;
		queue<string> buf;//同一层操作的节点，访问完后同时设下一层为1
		queue<int> level;
		unordered_map<string, vector<string>> map;//图
		int now_level = -1;
		int cur_level = -1;
		//初始化
		for (auto s : wordList)
			if(is_have.find(s)==is_have.end())
				is_have.insert(make_pair(s,0));
		if(is_have.find(beginWord) == is_have.end())
			is_have.insert(make_pair(beginWord, 1));
		level.push(0);

		while (!result.empty()) {
			vector<string> r = result.front();
			result.pop();
			cur_level = level.front();
			//构建图
			if(map.find(r[level.front()]) == map.end())
				map.insert(make_pair(r[level.front()],next_word(r[level.front()], is_have)));
			vector<string> nxt = map[r[level.front()]];
			
			for (auto s : nxt) {
				if (s == endWord) {
					now_level = level.front();
				}
				r.push_back(s);
				result.push(r);
				r.pop_back();
				level.push(level.front() + 1);
				buf.push(s);
			}
			level.pop();
			if(now_level>=0 && level.front()!=now_level){
				vector<vector<string>> res;
				while (!result.empty()) {
					if (result.front()[level.front()] == endWord) {
						res.push_back(result.front());
						result.pop();
					}
					else result.pop();
						
				}
				return res;
			}
			//从图中删除不用的节点
			while (!level.empty() && level.front() != cur_level&& !buf.empty()) {
				is_have[buf.front()] = 1;
				map.erase(buf.front());
				buf.pop();
			}
		}
		return vector<vector<string>> {};
	}

private:
	vector<string> next_word(string s, unordered_map<string, int>& is_have) {
		vector<string> result;
		for (auto c = s.begin(); c < s.end(); c++) {
			string s_swap = s;
			for (auto c_swap = 'a'; c_swap <= 'z'; c_swap++) {
				if (*c != c_swap) {
					s_swap[c - s.begin()] = c_swap;
					if (is_have.find(s_swap) != is_have.end() && is_have[s_swap] == 0)
						result.push_back(s_swap);
				}
			}
		}
		return result;
	}
};
//
//int main() {
//	vector<string> a = { "hot","dot","dog","lot","log","cog" };
//	Solution s;
//	vector<vector<string>> b = s.findLadders("hit", "cog", a);
//
//	return 0;
//}