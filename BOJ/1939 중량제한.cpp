#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef std::vector <std::vector<std::pair<int, int>>> graph;

int start, end;
bool BFS(const graph& edges, std::vector<bool>& visited, const int cost)
{
	std::queue<int> nodes;
	int answer = 0;

	nodes.push(start);
	visited[start] = true;

	while (!nodes.empty())
	{
		auto value = nodes.front();
		nodes.pop();

		if (value == end)
			return true;

		for (const auto i : edges[value])
		{
			if (visited[i.first] || i.second < cost)
				continue;

			visited[i.first] = true;
			nodes.push(i.first);
		}
	}

	return false;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	graph edges (n + 1, std::vector<std::pair<int, int>>());
	std::vector<bool> visited(n + 1, false);
	int maxCost = 0;
	// 모든 경로는 양방향이다.
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		edges[a].push_back(std::make_pair(b, c));
		edges[b].push_back(std::make_pair(a, c));
		maxCost = std::max(maxCost, c);
	}

	std::cin >> start >> end;

	int left = 0, right = maxCost, mid = 0;
	int answer = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		visited.assign(visited.size(),false);
		if (BFS(edges, visited, mid))
		{
			left = mid + 1;
			answer = mid;
		}
		else
			right = mid - 1;
	}

	std::cout << answer;
	return 0;
}
