#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	struct pos {
		int x, y;
		pos(int x_, int y_) :x(x_), y(y_) {}
	};
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1) return;
		int row = board.size();
		if (board[0].size() <= 1) return;
		int col = board[0].size();
		queue<queue<pos>> boundary = get_boundary(board, row, col);

		if (!boundary.empty()) {
			while (!boundary.empty()) {
				queue<pos> bound = boundary.front();
				boundary.pop();
				while (!bound.empty()) {
					pos node = bound.front();
					bound.pop();
					//没有访问过则访问
					if (board[node.x][node.y] != '#') {
						board[node.x][node.y] = '#';
						//上下左右满足条件边界条件，且为o,即没有被访问过则加入队列
						if (node.x > 0 && board[node.x - 1][node.y] == 'O')
							bound.push(pos(node.x - 1, node.y));
						if (node.x < row - 1 && board[node.x + 1][node.y] == 'O')
							bound.push(pos(node.x + 1, node.y));
						if (node.y > 0 && board[node.x][node.y - 1] == 'O')
							bound.push(pos(node.x, node.y - 1));
						if (node.y < col - 1 && board[node.x][node.y + 1] == 'O')
							bound.push(pos(node.x, node.y + 1));
					}
				}
			}
		}

		//将o变为x,#变为o
		for (int i = 0; i < row ; i++)
			for (int j = 0; j < col ; j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '#')
					board[i][j] = 'O';
			}

	}
	queue<queue<pos>> get_boundary(vector<vector<char>>& board,	int row, int col ) {
		queue<queue<pos>> boundary;
		//遍历边界，找到不连续的边界o加入队列
		//上
		for (int j = 0; j < col; j++)
			if ((j == 0 && board[0][j] == 'O') || (j != 0 && board[0][j] == 'O'
					&& board[0][j - 1] != 'O')) {
				queue<pos> bd;
				bd.push(pos(0, j));
				boundary.push(bd);
			}
		//右
		for (int i =  1; i < row; i++)
			if (board[i][col - 1] == 'O' && board[i - 1][col - 1] != 'O') {
				queue<pos> bd;
				bd.push(pos(i, col - 1));
				boundary.push(bd);
			}
		//下
		for (int j = col - 2; j >= 0; j--)
			if (board[row - 1][j] == 'O' && board[row - 1][j + 1] != 'O') {
				queue<pos> bd;
				bd.push(pos(row - 1, j));
				boundary.push(bd);
			}
		//左
		for (int i = row - 2; i > 0; i--) {
			if (board[i][0] == 'O' && board[i + 1][0] != 'O') {
				queue<pos> bd;
				bd.push(pos(i, 0));
				boundary.push(bd);
			}
		}
		return boundary;
	}
};


int main() {
	/*vector<vector<char>> board = {  { 'O','O','O','O' ,'O','O' },
									{ 'O','X','X','X' ,'X','O' },
									{ 'O','X','O','O' ,'X','O' }, 
									{ 'O','X','X','O' ,'X','O' }, 
									{ 'O','X','O','X' ,'X','O' }, 
									{ 'O','O','O','O' ,'O','O' }, };*/
	vector<vector<char>> board = {  { 'O','O','O' },
									{ 'O','O','O' },
									{ 'O','O','O'} , };
	Solution s;
	s.solve(board);
	return 0;
}