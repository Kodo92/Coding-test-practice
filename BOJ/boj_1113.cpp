/*
	[백준] 1113 수영장 만들기
		문제 출처 : https://www.acmicpc.net/problem/1113

	[풀이 방법] 구현
		1. bfs

	[풀이 일자] 2020.08.10
*/

#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
std::pair<int, int> direction[]{ {-1,0},{1,0},{0,-1},{0,1} };

bool checkPosition(const int y, const int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(const std::vector<std::vector<int>>& pool, std::vector<std::vector<bool>>& isVisted, const int y, const int x)
{
	if (isVisted[y][x]) return 0;

	std::queue<std::pair<int, int>> queue;
	queue.push({ y,x });
	isVisted[y][x] = true;

	int minHeight = 10;
	int areaCount = 0;
	int answer = 0;
	while (!queue.empty())
	{
		auto top = queue.front();
		queue.pop();

		for (int i = 0; i < 3; i++)
		{
			int newY = top.first + direction[i].first;
			int newX = top.second + direction[i].second;
			if (!checkPosition(newY, newX)) return 0;
			if (isVisted[newY][newX]) continue;
			if (pool[newY][newX] < pool[top.first][top.second]) continue;
			if (pool[newY][newX] != pool[top.first][top.second])
			{
				if (minHeight > pool[newY][newX])
				{
					answer -= ((minHeight - pool[newY][newX])*areaCount);
					minHeight = pool[newY][newX];
				}
			}
			areaCount++;
			answer += minHeight - pool[top.first][top.second];
			isVisted[newY][newX] = true;
		}
	}
	return answer;
}
int main()
{

	std::cin >> N >> M;

	std::vector<std::vector<int>> pool(N,std::vector<int>(M,0));
	std::vector<std::vector<bool>> isVisted(N, std::vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		std::string input;
		std::cin >> input;
		for (int j = 0; j < M; j++)
			pool[i][j] = input[j] - '0';
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			answer += bfs(pool, isVisted, i, j);
	}

	std::cout << answer;
}