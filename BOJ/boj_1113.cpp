/*
	[����] 1113 ������ �����
		��ó : https://www.acmicpc.net/problem/1113
		Ǯ���� :	2020.08.10 (x)
				2022.03.28
*/

#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
int maxHeight;
std::pair<int, int> direction[]{ {-1,0},{1,0},{0,-1},{0,1} };

bool checkPosition(const int y, const int x)
{
	return y >= 0 && y < N + 2 && x >= 0 && x < M + 2;
}

void bfs(std::vector<std::vector<int>>& pool, const int height)
{
	std::queue<std::pair<int, int>> queue;
	queue.push({ 0,0 });
	pool[0][0] = height;

	while (!queue.empty())
	{
		auto top = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = top.first + direction[i].first;
			int newX = top.second + direction[i].second;
			if (!checkPosition(newY, newX)) continue;
			if (pool[newY][newX] >= height) continue;
			pool[newY][newX] = height;
			queue.push({ newY,newX });
		}
	}
	return;
}

int checkPool(const std::vector<std::vector<int>>& pool, const int height) {
	int count = 0;
	for (size_t i = 0; i < N + 2; i++)
		for (size_t j = 0; j < M + 2; j++)
			if (pool[i][j] < height)
				count++;

	return count;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	// ���� ���̴� 0������ ���� ���̴� 1���� �����ϰ� ���� ���̴� 2���� �����ϱ� ������ �迭�� �ʱ갪�� 1�� �������־���.
	std::vector<std::vector<int>> pool(N + 2, std::vector<int>(M + 2, 1));



	for (size_t i = 1; i <= N; i++) {
		std::string str;
		std::cin >> str;
		for (size_t j = 1; j <= M; j++)
		{
			pool[i][j] = str[j - 1] - '0';
			maxHeight = (maxHeight < pool[i][j]) ? pool[i][j] : maxHeight;
		}
	}

	int answer = 0;
	// ���� ���� ���� ���̺��� ������ ������ �ȵ�.
	for (int i = 2; i <= maxHeight; i++) {
		bfs(pool, i);
		answer += checkPool(pool, i);
	}

	std::cout << answer;
}