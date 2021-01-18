/*
	[백준] 16398 행성 연결
		문제 출처 : https://www.acmicpc.net/problem/16398
		풀이 일자 : 2020.07.02

	[풀이 방법] : 최소 신장 트리 (프림 알고리즘)
		1. 프림 알고리즘을 이용해 현재 노드의 인접 노드 중 가중치가 작은 간선을 선택한다.
		2. isUsed를 사용해 이미 방문한 노드는 재방문 하지 않는다.
*/

#include <iostream>
#include <vector>
#include <queue>

struct node {
	int cost;
	int index;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.cost > b.cost;
	}
};

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<std::pair<int, int>>> graph(N, std::vector<std::pair<int, int>>(N));
	std::vector<bool> isUsed(N, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			std::cin >> temp;
			graph[i][j] = { temp,j };
		}
	}

	std::priority_queue<node, std::vector<node>, cmp> queue;
	queue.push({ 0,0});
	int answer = 0;
	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();
		const int cost = top.cost;
		const int index = top.index;

		if (isUsed[index]) continue;
		isUsed[index] = true;
		answer +=cost;
		for (const auto& i : graph[index])
		{
			if (isUsed[i.second]) continue;
			if (i.first == 0) continue;
			queue.push({ i.first,i.second });

		}
	}
	std::cout << answer;
	return 0;
}