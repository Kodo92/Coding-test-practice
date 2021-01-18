/*
	[백준] 16681 등산
		문제 출처 : https://www.acmicpc.net/problem/16681

	[풀이 방법] 다익스트라
		1. 시작점부터 각 노드별 최단거리를 구한다. 이때 다음 노드의 높이가 더 높아야한다.
			- 도착은 역으로 생각해 도착지점을 시작 노드로 계산하면 된다.

	[실패 과정]
		1. 61%에서 메모리초과 문제 발생
			-> queue를 prioirty_queue로 변경 
		2. 우선순위 큐로 변경 후 시간초과 문제 발생
			-> 큐에서 나온 비용이 기록된 비용보다 많은 경우 패스
		3. 76%에서 틀렸습니다.
			-> int 자료형을 long long으로 변경.
	
	[풀이 일자] 2020.07.19
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>

long long N, M, D, E;

std::vector<int> heights;
std::vector<std::vector<std::pair<long long, long long>>> distance;
std::vector<std::vector<long long>> costs;

void dijkstra()
{
	for (int i = 0; i < 2; i++)
	{
		int source;
		if (i == 0)
			source = 0;
		else
			source = heights.size() - 1;


		std::priority_queue<std::pair<long long,int>,std::vector<std::pair<long long,int>>,std::greater<std::pair<int,int>>> queue;
		queue.push({ 0,source });
		costs[i][source] = 0;

		while (!queue.empty())
		{
			long long nowCost = queue.top().first;
			int nowPos = queue.top().second;
			queue.pop();

			if (nowCost > costs[i][nowPos]) continue;

			for (const auto& val : distance[nowPos])
			{
				long long nextCost = val.first + nowCost;
				int nextPos = val.second;
				if (heights[nowPos] >= heights[nextPos] || nextCost >= costs[i][nextPos]) 
					continue;
				queue.push({ nextCost,nextPos });
				costs[i][nextPos] = nextCost;
			}
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M >> D >> E;
	//	 N : 지점의 갯수, M : 경로 갯수, D : 체력 소모량, E : 성취감 획득량
	
	heights.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> heights[i];

	distance.resize(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		a -= 1;
		b -= 1;
		distance[a].push_back( { c,b });
		distance[b].push_back({ c,a });
	}

	costs.resize(2);
	costs[0].resize(N,LLONG_MAX);
	costs[1].resize(N, LLONG_MAX);
	dijkstra();

	long long answer = LONG_MIN;
	for (int i = 1; i < N-1; i++)
	{
		if (costs[0][i] == LLONG_MAX || costs[1][i] == LLONG_MAX) continue;
		answer = std::max(answer, (long long)(heights[i] * E) - ((costs[0][i] + costs[1][i])*D));
	}

	if (answer == LONG_MIN)
		std::cout << "Impossible";
	else
		std::cout << answer;

	return 0;
}