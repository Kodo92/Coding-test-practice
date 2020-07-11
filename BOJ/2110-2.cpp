/*
	[백준]	2110	공유기 설치
		문제 출처 : https://www.acmicpc.net/problem/2110

	[풀이 방법] - 이분 탐색
		1. 조합을 이용한 경우의 수 탐색은 N의 최대가 200,000 이라서 불가능하다.
		2. 이분탐색을 이용하는데, 탐색 기준 값은 최소 인접한 두 공유기 사이의 거리로 한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int checkDistance(const std::vector<int>& position, const int distance)
{
	int count = 1;
	int source = position.front();
	for (const auto& i : position)
	{
		if (i - source >= distance)
		{
			count++;
			source = i;
		}
	}
	return count;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, C;
	std::cin >> N >> C;

	std::vector<int> position(N);
	for (int i = 0; i < N; i++)
		std::cin >> position[i];

	std::sort(position.begin(), position.end());

	long long left = 1, right = position.back() - position.front(), mid = 0;
	long long answer = 0;
	while (left <= right)
	{
		mid = (left + right)/2;
		if (checkDistance(position, mid) < C)
			right = mid - 1;
		else
		{
			left = mid + 1;
			answer = mid;
		}
	}
	std::cout << answer;
}