/*
	[백준] 14502 연구소
		문제 출처 : https://www.acmicpc.net/problem/14502

	[풀이 방법] - 완전 탐색
		1. 배열이 값이 0인 빈칸을 재귀를 이용해 바이러스를 퍼뜨린다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
int answer = 0;

class laboratory
{
	int N, M;
	std::vector<std::vector<int>> map;
	std::vector<std::pair<int, int>> virusPosition;
	std::vector<std::pair<int, int>> moveDirection{ {-1,0},{1,0},{0,-1},{0,1} };

public:
	laboratory(int N, int M) : N(N), M(M) {
		map.resize(N);
		for (int i = 0; i < N; i++)
			map[i].resize(M);
	}

	void setData(const int y, const int x, const int value);
	int getData(const int y, const int x) const { return map[y][x]; }
	int attack();

private:
	bool checkDirection(const int y, const int x) const;
	int		countSafeArea() const; 

};

bool laboratory::checkDirection(const int y, const int x) const
{
	if (y < 0 || y >= N || x < 0 || x >= M) return false;
	return true;
}

int laboratory::countSafeArea() const
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				count++;
	}

	return count;
}

void laboratory::setData(const int y, const int x, const int value)
{
	if (x < 0 || x >= M || y < 0 || y >= N) return;

	map[y][x] = value;
	if (value == 2)
		virusPosition.push_back({ y,x });
}

int laboratory::attack()
{
	std::queue<std::pair<int, int>> queue;
	for (const auto& i : virusPosition)
		queue.push(i);
	
	while (!queue.empty())
	{
		auto front = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			const int newY = moveDirection[i].first + front.first;
			const int newX = moveDirection[i].second + front.second;

			if (!checkDirection(newY,newX)) continue;
			if (map[newY][newX] != 0) continue;

			setData(newY,newX,2);
			queue.push({ newY,newX });
		}
	}

	return countSafeArea();
}

void dfs(laboratory lab, int count)
{
	if (count > 2)
	{
		answer = std::max(lab.attack(), answer);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (lab.getData(i, j) == 0)
			{
				lab.setData(i, j, 1);
				dfs(lab, count + 1);
				lab.setData(i, j, 0);
			}
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	laboratory lab(N, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			std::cin >> temp;
			lab.setData(i, j, temp);
		}
	}

	dfs(lab, 0);

	std::cout << answer;
	return 0;
}