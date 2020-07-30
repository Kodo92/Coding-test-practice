/*
	[백준] 6593 상범 빌딩
		문제 출처 : https://www.acmicpc.net/problem/6593

	[풀이 방법] BFS + 다익스트라

	[실패 과정]
		1. 메모리 초과 : board에서 cost값만 관리해줬는데 visited방식으로 이미 간 경로는 다시 가지 않게 수정.

	[풀이 일자] 2020.07.29
*/

#include <iostream>
#include <vector>
#include <queue>

int dh[]{ -1,1,0,0,0,0 }, dy[]{ 0,0,-1,1,0,0 }, dx[]{ 0,0,0,0,-1,1 };
int L, R, C;
const int INF = 2147483647;

class node {
public:
	int cost;
	int height;
	int y;
	int x;
public:
	node() {}
	node(int cost, int height, int y, int x) : cost(cost), height(height), y(y), x(x) {}
	bool operator< (const node& compared) const { return this->cost > compared.cost; }
};

int bfs(std::vector<std::vector<std::vector<int>>>& board, const node& source, const node& dest)
{
	std::priority_queue<node> queue;
	queue.push(source);
	board[source.height][source.y][source.x] = 0;

	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();

		if (top.height == dest.height && top.y == dest.y && top.x == dest.x)
			return top.cost;

		for (int i = 0; i < 6; i++)
		{
			int newHeight = top.height + dh[i];
			int newY = top.y + dy[i];
			int newX = top.x + dx[i];
			int newCost = top.cost + 1;

			if (newHeight < 0 || newHeight >= L || newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
			if (board[newHeight][newY][newX] != INF) continue;
			
			queue.push(node(newCost, newHeight, newY, newX));
			board[newHeight][newY][newX] = newCost;
		}
	}
	return 0;
}

int main()
{
	while (true)
	{
		std::cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;

		std::vector<std::vector<std::vector<int>>> board(L, std::vector<std::vector<int>>(R, std::vector<int>(C,INF)));
		node source, dest;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					char data;
					std::cin >> data;
					if (data == '#')
						board[i][j][k] = -1;
					else if (data == 'S')
						source = node(0, i, j, k);
					else if (data == 'E')
						dest = node(0, i, j, k);
				}
			}
		}
		int answer =bfs(board,source,dest);
		if (answer == 0)
			std::cout << "Trapped!" << '\n';
		else
			std::cout << "Escaped in "<<answer<<" minute(s)." << '\n';
	}
	return 0;
}