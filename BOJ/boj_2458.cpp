/*
	[백준] 키 순서
		문제 출처 : https://www.acmicpc.net/problem/2458
		풀이 분류 : 플로이드-와샬
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N,M;
	std::cin >> N>>M;

	std::vector<std::vector<bool>> connections(N,std::vector<bool>(N,false));

	for (int i = 0; i < M; i++)
	{
		int left, right;
		std::cin >> left >> right;
		left -= 1;
		right -= 1;
		connections[left][right] = true;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (connections[j][i] && connections[i][k])
					connections[j][k] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		bool is_find = false;
		for (int j = 0; j < N; j++)
		{
			if (i!=j && !connections[i][j] && !connections[j][i])
			{
				is_find = true;
				break;
			}
		}
		if (!is_find)
			answer++;
	}

	std::cout << answer;
	return 0;
}