/*
	[백준] 3980 선발 명단
		문제 출처 : https://www.acmicpc.net/problem/3980

	[풀이 방법] 브루드포스

	[실패 과정]
		1. 프로그래머스 땅따먹기처럼 풀어봄.. 실패

	[풀이 일자] 2020.07.23
*/

#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int>>& S, std::vector<bool> isUsed, int level, int sum, int& answer)
{
	if (level >= 11)
	{
		answer = std::max(answer, sum);
		return;
	}

	for (int i = 0; i < 11; i++)
	{
		if (S[level][i] != 0 && !isUsed[i])
		{
			isUsed[i] = true;
			dfs(S, isUsed, level + 1, sum + S[level][i], answer);
			isUsed[i] = false;
		}
	}
}

void loop()
{
	std::vector<std::vector<int>> S(11, (std::vector<int>(11)));
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			std::cin >> S[i][j];
	}

	std::vector<bool> isUsed(11,false);
	int answer = 0;
	for (int i = 0; i < 11; i++)
	{
		if (S[0][i] == 0) continue;
		isUsed[i] = true;
		dfs(S, isUsed, 1, S[0][i], answer);
		isUsed[i] = false;
	}

	std::cout << answer << '\n';
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--)
	{
		loop();
	}

	return 0;
}