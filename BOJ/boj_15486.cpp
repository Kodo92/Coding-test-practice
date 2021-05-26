/*
*	[백준] 퇴사 2
*		출처 : https://www.acmicpc.net/problem/15486
*		비고 : 쩜스터디 2021.04.23.
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vals(N, { 0,0 });

	for (int i = 0; i < N; i++) {
		std::cin >> vals[i].first >> vals[i].second;
	}

	int answer = 0;
	std::vector<int> dp(N+1,0);

	for (int i = 0; i <= N; i++) {
		answer = std::max(answer, dp[i]);
		if (i + vals[i].first > N + 1) continue;
		dp[i + vals[i].first] = std::max(answer + vals[i].second, dp[i + vals[i].first]);
	}

	std::cout << answer;
	return 0;
}