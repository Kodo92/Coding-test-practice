#include <iostream>
#include <map>
#include <queue>

std::map<int, std::vector<std::pair<int, int>>> graph;

const int maxCost = 100000 * 100000;

int main()
{
	int N, M, A, B;
	std::cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int start, dest, cost;
		std::cin >> start >> dest >> cost;
		graph[start].push_back(std::make_pair(dest, cost));
	}

	std::cin >> A >> B;

	std::vector<long long> costs(N+1, maxCost);
	costs[A] = 0;

	std::priority_queue<std::pair<int, int>> BFSQ;
	BFSQ.push(std::make_pair(0, A));

	while (!BFSQ.empty())
	{
		const auto front = BFSQ.top();
		BFSQ.pop();

		const int currentIndex = front.second;
		const long long currentCost = -front.first;

		if (currentCost > costs[currentIndex]) continue;

		for (const auto& i : graph[front.second])
		{
			int newCost = i.second + currentCost;
			if (costs[i.first] > newCost)
			{
				BFSQ.push(std::make_pair(-newCost, i.first));
				costs[i.first] = newCost;
			}
		}
	}

	std::cout << costs[B];
}