#include <iostream>
#include <vector>
#include <map>
#include <queue>

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int V, E, K;
	std::cin >> V >> E >> K;

	std::map<int, std::vector<std::pair<int, int>>> nodes;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		std::cin >> u >> v >> w;
		nodes[u - 1].push_back(std::make_pair(v - 1, w));
	}

	std::priority_queue<std::pair<int,int>> BFSQ;
	BFSQ.push(std::make_pair(0,K - 1));

	std::vector<int> pathValues(V, 2147483647);
	pathValues[K - 1] = 0;	// ������ ��� �� 
	while (!BFSQ.empty())
	{
		const auto front = BFSQ.top();	// �Է� ���� 1���� ����, vector�� 0���� ����
		BFSQ.pop();

		const auto distacne = -front.first;
		const auto currentIndex = front.second;

		if (distacne > pathValues[currentIndex])
			continue;

		for (const auto i : nodes[currentIndex])
		{
			int pathValue = distacne + i.second;
			if (pathValues[i.first] > pathValue)
			{
				BFSQ.push(std::make_pair(-pathValue,i.first));
				pathValues[i.first] = pathValue;
			}
		}
	}

	for (const auto value : pathValues)
	{
		if (value == 2147483647)
			std::cout << "INF" << '\n';
		else
			std::cout << value << '\n';
	}

}

/*
priority_queue �� distance�� - �ؼ� �����ϴ� ����. : �ּ� ���� �̿��ϱ� ���ؼ��̴�.
3, 10�� ���� ť�� ������ 10�� �켱���� ���´�.
priority_queue�� less�� �ƴ϶� greater�� �ٲٸ� �ǰڳ�.
*/