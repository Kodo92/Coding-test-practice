#include <iostream>
#include <queue>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	auto cmp = [](const std::pair<int, int>& left, const std::pair<int, int>& right)
	{
		if (left.first == right.first)
			return left.second > right.second;
		return left.first > right.first;
	};

	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(cmp)> queue(cmp);
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if(temp != 0)
			queue.push({ abs(temp),temp });
		else
		{
			if (queue.empty())
				std::cout << '0' << std::endl;
			else
			{
				std::cout << queue.top().second << std::endl;
				queue.pop();
			}
		}
	}


	return 0;
}