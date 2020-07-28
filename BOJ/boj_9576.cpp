/*
	[백준] 9576 책 나눠주기
		문제 출처 : https://www.acmicpc.net/problem/9576

	[풀이 방법] 그리디
		1. B -> A 순으로 오름차순 정렬을 한다.
			정렬 결과 범위가 1인 경우 (1 1, 3 3)이 1 2, 3 4 보다 먼저나오게 된다. 즉 선택권이 작은 조건 먼저 충족을 시켜준다.

	[풀이 일자] 2020.07.27
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N, M;
		std::cin >> N >> M;

		std::vector<bool> books(N+1, false);
		std::vector<std::pair<int, int>> ranges(M);
		for (int i = 0; i < M; i++)
			std::cin >> ranges[i].first >> ranges[i].second;
		
		std::sort(ranges.begin(), ranges.end(), cmp);
		int answer = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = ranges[i].first; j <= ranges[i].second; j++)
			{
				if (!books[j])
				{
					answer++;
					books[j] = true;
					break;
				}
			}
		}
		std::cout << answer<<'\n';
	}

	return 0;
}