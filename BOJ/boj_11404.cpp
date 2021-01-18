/*
	[백준] 플로이드
		문제 출처 : https://www.acmicpc.net/problem/11404
		키워드 :  floyd warshall
*/

#include <iostream>
#include <vector>

const int INF = 1e8;
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	int N, M;
	std::cin >> N >> M;
	
	std::vector<std::vector<int>>dist(N, std::vector<int>(N, INF));
	for (int i = 0; i < M; i++)
	{
		int src, dest, cost;
		std::cin >> src >> dest >> cost;
		dist[src-1][dest-1] = std::min(cost,dist[src-1][dest-1]);
	}

	for (int i = 0; i < N; i++)
		dist[i][i] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dist[i][j] == INF)
				dist[i][j] = 0;
			std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}