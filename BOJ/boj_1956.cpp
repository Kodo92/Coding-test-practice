/*
	[백준] 1956 운동
		문제 출처 : https://www.acmicpc.net/problem/1956

	[풀이 방법] : 플로이드-와샬 
		- 일반적인 플로이드-와샬 알고리즘은 자기자신을 0으로 놓는다. 하지만 이 문제에서 원하는 것은 사이클이므로 INF로 놓는다.
		  알고리즘을 실행한 후 costs[i][j]의 최솟값을 리턴한다.

	[실패 과정]
		오늘의 교훈 : 문제를 잘 읽자. 찾는것이 불가능할 경우 -1 리턴이다.
			1. INF를 5000000으로하면 100ms, 4000001로 하면 104ms가 나온다.. 
	
	[풀이 일자] 2020.07.21
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 5000000;

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int V, E;
	std::cin >> V >> E;

	std::vector<std::vector<int>> costs(V, std::vector<int>(V, INF));

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		costs[a - 1][b - 1] = c;
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (costs[i][j] > costs[i][k] + costs[k][j])
					costs[i][j] = costs[i][k] + costs[k][j];
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < V; i++)
		answer = std::min(answer, costs[i][i]);

	if (answer == INF)
		std::cout << -1;
	else
		std::cout << answer;
	return 0;
}