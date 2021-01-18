/*
	[백준] 2887 행성 터널
		문제 출처 : https://www.acmicpc.net/problem/2887

	[풀이 방법] 크루스칼
		1. 거리 좌표 x로 정렬 후 i와 i+1순으로 비용을 계산한다.
		2. x,y,z순으로 1번 작업을 진행한다.
		3. 2번 작업 완료 후 계산한 간선들을 정렬 해 크루스칼 알고리즘을 실행한다. 

	[실패 과정]
		1. 크루스칼 & union find - 메모리 초과

	[풀이 일자] 2020.08.10
*/

#include <iostream>
#include <vector>
#include <algorithm>

enum comparedType {X=0, Y, Z};

struct position {
	int index;
	int x = 0;
	int y = 0;
	int z = 0;
};

int getParentNumber(std::vector<int>& parents, const int searchIndex)
{
	if (searchIndex == parents[searchIndex])
		return searchIndex;
	return parents[searchIndex] = getParentNumber(parents, parents[searchIndex]);
}

bool compareByX(const position& left, const position& right)
{
	return left.x < right.x;
}

bool compareByY(const position& left, const position& right)
{
	return left.y < right.y;
}

bool compareByZ(const position& left, const position& right)
{
	return left.z < right.z;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<position> planets(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> planets[i].x >> planets[i].y >> planets[i].z;
		planets[i].index = i;
	}
	
	std::vector<std::pair<int, std::pair<int, int>>> costs;

	std::sort(planets.begin(), planets.end(), compareByX);
	for (int i = 0; i < N - 1; i++)
	{
		std::vector<int> tempCosts;
		tempCosts.push_back(abs(planets[i].x - planets[i+1].x));
		tempCosts.push_back(abs(planets[i].y - planets[i+1].y));
		tempCosts.push_back(abs(planets[i].z - planets[i+1].z));
		costs.push_back({ *std::min_element(tempCosts.begin(),tempCosts.end()),{ planets[i].index,planets[i+1].index } });
	}

	std::sort(planets.begin(), planets.end(), compareByY);
	for (int i = 0; i < N - 1; i++)
	{
		std::vector<int> tempCosts;
		tempCosts.push_back(abs(planets[i].x - planets[i + 1].x));
		tempCosts.push_back(abs(planets[i].y - planets[i + 1].y));
		tempCosts.push_back(abs(planets[i].z - planets[i + 1].z));
		costs.push_back({ *std::min_element(tempCosts.begin(),tempCosts.end()),{ planets[i].index,planets[i + 1].index } });
	}

	std::sort(planets.begin(), planets.end(), compareByZ);
	for (int i = 0; i < N - 1; i++)
	{
		std::vector<int> tempCosts;
		tempCosts.push_back(abs(planets[i].x - planets[i + 1].x));
		tempCosts.push_back(abs(planets[i].y - planets[i + 1].y));
		tempCosts.push_back(abs(planets[i].z - planets[i + 1].z));
		costs.push_back({ *std::min_element(tempCosts.begin(),tempCosts.end()),{ planets[i].index,planets[i + 1].index } });
	}

	std::sort(costs.begin(), costs.end());

	std::vector<int> parents(N);
	std::vector<int> levels(N,1);
	for (int i = 0; i < N; i++)
		parents[i] = i;
	int destCount = N - 1;
	long long answer = 0;
	for (const auto& i : costs)
	{
		if (destCount == 0)
			break;
		int aParent = getParentNumber(parents, i.second.first);
		int bParent = getParentNumber(parents, i.second.second);
		if (aParent == bParent)
			continue;
		if (levels[aParent] > levels[bParent])
		{
			parents[bParent] = parents[aParent];
			levels[aParent] += levels[bParent];
		}
		else
		{
			parents[aParent] = parents[bParent];
			levels[bParent] += levels[aParent];
		}
		answer += i.first;
		destCount--;
	}

	std::cout << answer;
	return 0;
}