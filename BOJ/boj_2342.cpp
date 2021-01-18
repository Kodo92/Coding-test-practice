/*
	[백준] 2342 Dance Dance Revolution
		문제 출처 : https://www.acmicpc.net/problem/2342

	[풀이 방법] DFS + DP
		1. DFS로 모든 경우를 구하면 시간초과가 난다.
			- 모든 경우를 다 구해야한다. 앞부분이 최소값이라 해서 끝까지 최소값이라는 보장은 없다. ex) 1 2 3 2 1 0 -> 11
		2. dpTable을 생성한다. [count][left][right]이다. count번째일 때 left, right의 최솟값이다.
			끝에서부터 채워나가 [0][0][0]이 답이 된다.
	[풀이 일자] 2020.08.01
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int SIZE;
int costs[5][5] { {-1,2,2,2,2},{-1,1,3,4,3},{-1,3,1,3,4},{-1,4,3,1,3},{-1,3,4,3,1} };
int dpTable[100001][5][5];
const int INF = 2147483647;
std::vector<int> steps;

int dfs(const int left = 0, const int right = 0, const int count = 0)
{
	if (count == SIZE)
		return 0;

	auto& ref = dpTable[count][left][right];
	if (ref != 0)
		return ref;

	// {0,0}일 때는 왼, 오 둘다 간다.
	int nextStep = steps[count];
	ref = INF;
	// 왼쪽
	ref = std::min(dfs(nextStep, right, count + 1) + costs[left][nextStep],ref);
	ref = std::min(dfs(left, nextStep, count + 1) + costs[right][nextStep],ref);
	return ref;
}

int main()
{

	while (true)
	{
		int number;
		std::cin >> number;
		if (number == 0) break;
		steps.push_back(number);
	}
	SIZE = steps.size();

	std::cout<<dfs();
	return 0;
}