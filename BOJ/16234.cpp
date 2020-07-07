/*
	[백준] 16234 인구 이동
		문제 출처 : https://www.acmicpc.net/problem/16234
		풀이 일자 : 2020.07.02.

	[풀이 방법] Disjoint set
		1. bfs를 이용해 인접한 칸(상하좌우)이 오픈 가능한지 체크한다.
		2. 체크 결과 오픈 가능하다면 큐에 넣는다. 이때 isUsed를 이용해 방문한 지역을 체크한다.
		2-1. bfs while문을 도는 동안 큐에 추가된 노드들은 같은 집합으로 분류한다.
		2-2. 모든 지역을 방문할 때 까지 bfs를 반복한다. 이때 집합을 이루는 요소가 없을 경우 반복을 종료한다.
		3. 같은 집합으로 분류된 지역들의 인구수 평균을 구하고 적용한다.
*/

#include <iostream>
#include <vector>
#include <queue>

int N, L, R;
std::vector<std::pair<int, int>> direction{ {-1,0},{1,0},{0,-1},{0,1} };

bool checkPosition(const std::vector<std::vector<int>>& population, const int sourceY, const int sourceX, const int destY, const int destX)
{
	if (sourceY < 0 || sourceY >= N || sourceX < 0 || sourceX >= N) return false;
	if (destY < 0 || destY >= N || destX < 0 || destX >= N) return false;

	int diff = abs(population[sourceY][sourceX] - population[destY][destX]);
	if (diff >= L && diff <= R)
		return true;
	return false;
}


int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N >> L >> R;

	std::vector<std::vector<int>> population(N, std::vector<int>(N));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> population[i][j];
	}

	int answer = 0;
	while (true)
	{
		std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(N, false));
		std::vector<std::vector<int*>> group;
		std::queue<std::pair<int, int>> queue;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isUsed[i][j]) continue;

				queue.push({ i,j });
				isUsed[i][j] = true;
				std::vector<int*> subGroup;
				while (!queue.empty())
				{
					auto front = queue.front();
					queue.pop();

					for (const auto& k : direction)
					{
						int newY = front.first + k.first;
						int newX = front.second + k.second;

						if (!checkPosition(population, front.first, front.second, newY, newX) || isUsed[newY][newX])	continue;	// 1번 : 국경 개방 가능여부 체크
						// 2번 : 집합에 추가
						isUsed[newY][newX] = true;
						queue.push({ newY,newX });
						subGroup.push_back(&population[newY][newX]);
					}
				}
				if (subGroup.empty()) continue;
				subGroup.push_back(&population[i][j]);
				group.push_back(subGroup);
			}
		}
		
		if (group.empty())
			break;

		for (auto& i : group)
		{
			if (i.empty()) continue;
			int sum = 0;
			int count = i.size();
			for (auto& j : i)
				sum += *j;
			sum /= count;

			for (auto& j : i)
				*j = sum;
		}
		answer++;
	}

	std::cout << answer;
	return 0;
}
