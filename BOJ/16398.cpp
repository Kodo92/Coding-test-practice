/*
	[백준] 16398 행성 연결
		문제 출처 : https://www.acmicpc.net/problem/16398
		풀이 일자 : 2020.07.02

	[풀이 방법] : 최소 신장 트리 (프림 알고리즘)
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	
	std::vector<std::vector<std::pair<int, int>>> graph (N,std::vector<std::pair<int,int>>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			std::cin >> temp;
			graph[i][j] = { temp,j };
		}
	}

	std::cout << "test";
	return 0;
}