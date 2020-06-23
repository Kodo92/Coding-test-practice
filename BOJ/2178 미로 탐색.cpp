/*
	[백준] 2178. 미로 탐색
		문제 링크 : https://www.acmicpc.net/problem/2178
		풀이 : 2020.06.23

	[풀이 방법]	-	BFS를 이용한 그래프 알고리즘 (최단 거리 구하기)
	
	[주의]
		2번째줄의 입력값은 String로 받아야 한다.
		8바이트 부호없는 정수 자료형은 최대 20자리수까지만 표현할 수 있다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

int N, M;
std::vector<std::pair<int, int>> direction { {-1,0},{1,0},{0,-1},{0,1} };

class node
{
public:
	int cost = 0;
	int y = 0;
	int x = 0;

public:
	node(int cost, int y, int x) : cost(cost), y(y), x(x) {}
};

class cmp
{
public:
	bool operator() (const node& a, const node& b)
	{
		return a.cost > b.cost;
	}
};

bool checkPosition(const int y, const int x) 
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;
	return true;
}

int bfs(const std::vector<std::vector<int>>& labyrinth)
{
	std::priority_queue<node,std::vector<node>,cmp> queue;
	std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(M, false));

	queue.push({ labyrinth[0][0],0,0 });

	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();

		if (top.y == N - 1 && top.x == M - 1)
			return top.cost;

		for (const auto& i : direction)
		{
			const int destY = top.y + i.first;
			const int destX = top.x + i.second;

			if (checkPosition(destY,destX) && labyrinth[destY][destX] == 1 && isUsed[destY][destX] == false)
			{
				isUsed[destY][destX] = true;
				queue.push({ top.cost + 1,destY,destX });
			}
		}
	}
	// 항상 도착위치로 이동할 수 있는 경우만 케이스로 주어짐
}

int main()
{
	std::cin >> N >> M;

	std::vector<std::vector<int>> labyrinth(N,std::vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		std::string number;
		std::cin >> number;
		for (int j = 0; j < M; j++)
			labyrinth[i][j] = number[j]-'0';
	}

	std::cout << bfs(labyrinth);
	return 0;
}
