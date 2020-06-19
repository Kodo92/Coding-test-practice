#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

struct pathData
{
	int value = 0;
	std::vector<int> paths;
	int refCount = 0;
};

std::vector<std::pair<int, pathData>> list;
std::vector<int> answer;

void bfs()
{
	std::queue<int> queue;

	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].second.refCount == 0)
		{
			queue.push(i);
			answer[i] = list[i].second.value;
		}
	}

	while (!queue.empty())
	{
		auto front = queue.front();
		int value = answer[front];
		
		for (const auto i : list[front].second.paths)
		{
			int newValue = 
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	list.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int input;
		std::cin >> input;
		
		list[i].second.value = input;
		while (std::cin >> input)
		{
			if (input == -1)
				break;
			list[input].second.paths.push_back(i);
			list[i].second.refCount++;
		}
	}

	answer.resize(N + 1);
	bfs();

	for (const auto i : answer)
		std::cout << i << '\n';
	return 0;
}