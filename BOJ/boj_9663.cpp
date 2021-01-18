/*
	N-Queen
		문제 출처 : https://www.acmicpc.net/problem/9663
		분류 : 백트래킹
*/

#include <iostream>
#include <vector>

int answer = 0;

bool isCheck(std::vector<std::pair<int, int>>& position)
{
	auto& back = position.back();
	for (int i = 0; i < position.size() - 1; i++)
	{
		if (position[i].first == back.first || position[i].second == back.second)
			return false;

		if (abs(position[i].first - back.first) == abs(position[i].second - back.second))
			return false;
	}
	return true;
}

void DFS(const int N, std::vector<std::pair<int,int>> positions, std::pair<int,int> startPosition)
{
	if (positions.size() == N)
	{
		answer++;
		return;
	}

	int newX = startPosition.second + 1;
	for (int i = 0; i < N; i++)
	{
		if (i == startPosition.first)
			continue;
		positions.push_back({ i,newX });
		if (isCheck(positions))
			DFS(N, positions, { i,newX });
		positions.pop_back();
	}
}

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> positions;

	for(int i=0;i<N;i++)
		DFS(N, positions, {i,0 });

	std::cout << answer;
}
