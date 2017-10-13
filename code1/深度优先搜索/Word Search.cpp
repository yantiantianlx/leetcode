#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//错误

//class Solution {
//public:
//	struct pos {
//		int x;
//		int y;
//		pos(int x_, int y_) :x(x_), y(y_) {}
//	};
//	bool exist(vector<vector<char>>& board, string word) {
//		if (word.empty()) return true;
//		if (board.empty()) return false;
//		int row = board.size();
//		int col = board[0].size();
//		stack<pos> stack_char;
//		stack<int> level;
//		vector<vector<bool>> is_visited;
//		//栈头
//		for (int i = 0; i < row; i++)
//			for (int j = 0; j < col; j++) {
//				if (board[i][j] == word[0]) {
//					stack_char.push(pos(i, j));
//					level.push(0);
//				}
//			}	
//
//		while (!stack_char.empty()) {
//			int now_level = level.top(); level.pop();
//			pos now_pos = stack_char.top(); stack_char.pop();
//			if (now_level == word.size() - 1)
//				return true;
//			if (now_level == 0)
//				is_visited = vector<vector<bool>>(row, vector<bool>(col, false));
//			vector<pos> next_pos;
//			if (has_next(now_pos, now_level, next_pos, board, word, is_visited)) {
//				is_visited[now_pos.x][now_pos.y] = true;
//				for (auto next : next_pos) {
//					stack_char.push(next);
//					level.push(now_level + 1);
//				}
//				if (now_level + 1 == word.size() - 1)
//					return true;
//			}
//		}
//		
//		return false;
//	}
//
//	bool has_next(pos& now_pos, int& now_level, vector<pos>& next_pos, 
//		vector<vector<char>>& board, string& word, vector<vector<bool>>& is_visited) {
//		int row = board.size();
//		int col = board[0].size();
//		//上,没有被访问过，且相等
//		if (now_pos.x > 0 && !is_visited[now_pos.x - 1][now_pos.y]
//			&& board[now_pos.x - 1][now_pos.y] == word[now_level + 1])
//			next_pos.push_back(pos(now_pos.x - 1, now_pos.y));
//		//下
//		if(now_pos.x < row-1 && !is_visited[now_pos.x + 1][now_pos.y]
//			&& board[now_pos.x + 1][now_pos.y] == word[now_level + 1])
//			next_pos.push_back(pos(now_pos.x + 1, now_pos.y));
//		//左
//		if (now_pos.y > 0 && !is_visited[now_pos.x][now_pos.y-1]
//			&& board[now_pos.x][now_pos.y-1] == word[now_level + 1])
//			next_pos.push_back(pos(now_pos.x , now_pos.y-1));
//		//右
//		if (now_pos.y < col-1 && !is_visited[now_pos.x][now_pos.y + 1]
//			&& board[now_pos.x][now_pos.y + 1] == word[now_level + 1])
//			next_pos.push_back(pos(now_pos.x, now_pos.y + 1));
//		if (!next_pos.empty())
//			return true;
//		else
//			return false;
//	}
//};
//
//int main() {
//	vector<vector<char>> a = { {'A','B','C','E' },
//							   {'S','F','E','S' },
//							   {'A','D','E','E' } };
//	Solution s;
//	cout<<s.exist(a,"ABCESEEEFS");
//	cin.get();
//	return 0;
//}
//

class Solution {
public:

	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();
		vector<vector<bool>> is_visited(row, vector<bool>(col, false));
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (dfs(board, word, 0, i, j, is_visited))
					return true;
		return false;
	}

	bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y, vector<vector<bool>>& is_visited) {
		if (index == word.size())
			return true;
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
		if (is_visited[x][y] || board[x][y] != word[index]) return false;
		is_visited[x][y] = true;
		bool ret = dfs(board, word, index + 1, x + 1, y, is_visited) ||
				   dfs(board, word, index + 1, x - 1, y, is_visited) ||
				   dfs(board, word, index + 1, x, y+1, is_visited) ||
				   dfs(board, word, index + 1, x, y-1, is_visited);

		is_visited[x][y] = false;
		return ret;
	}
};