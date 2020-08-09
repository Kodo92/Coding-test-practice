/*
	[백준] 1167 트리의 지름
		문제 출처 : https://www.acmicpc.net/problem/1167

	[풀이 방법] 다익 (BFS)
		1. 임의의 점에서 출발해 가장 비용이 큰 곳의 좌표를 구한다.
			- 모든 좌표를 출발점으로 해보면 시간이 초과된다. 그래서 임의의 점부터 가장 비용이 큰 곳을 찾는데,
			그 이유는 거리 가중치가 높은 것들을 통한 것이 가장 비용이 큰 곳이 되기 때문이다.
		2. 그 좌표를 시작점으로 가장 비용이 큰 곳을 정답으로 한다.

	[실패 과정]
		1. 플로이드 와샬을 썼는데 배열의 크기가 최대 100000 * 100000인 것을 생각하지 않아서 메모리 초과가 났다... 바보 
		2. 다익스트라 (BFS) : 시간초과
			- 시작점을 0~N-1까지 모두 하면 N*N으로 시간초과 

	[풀이 일자] 2020.08.08

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, pathCount;

struct node {
	int dest;
	int cost;

	bool operator < (const node& comapred) const { return this->cost > comapred.cost; }
};

std::pair<int,int> bfs(const std::vector<std::vector<node>>& paths, const int startIndex)
{
	int answer = 0, index = startIndex;
	int count = pathCount;

	std::priority_queue<node> queue;
	std::vector<int> costs(N, 1000000001);
	queue.push({ startIndex,0 });
	costs[startIndex] = 0;
	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();
		if (count == 0)
			break;
		for (const auto& i : paths[top.dest])
		{
			int newCost = top.cost + i.cost;
			if (costs[i.dest] < newCost) continue;
			costs[i.dest] = newCost;
			queue.push({ i.dest,newCost });
			if (answer < newCost)
			{
				answer = newCost;
				index = i.dest;
			}
			count--;
		}
	}

	return{ answer,index };
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::vector<std::vector<node>> paths(N, std::vector<node>());
	for (int i = 0; i < N; i++)
	{
		int index;
		std::cin >> index;
		index  -= 1;

		while (true)
		{
			int dest, cost;
			std::cin >> dest;
			if (dest == -1)break;
			std::cin >> cost;
			pathCount++;
			paths[index].push_back({ dest - 1, cost });
		}
	}

	std::pair<int, int> retval = bfs(paths, 0);
	auto answer = bfs(paths, retval.second);
	

	std::cout << answer.first;
	return 0;
}