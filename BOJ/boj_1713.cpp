#include <iostream>
#include <map>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::map <int, std::pair<int, int>> maps;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		auto retval = maps.find(temp);
		if (retval != maps.end())
			retval->second.first++;

		else
		{
			if (maps.size() >= N)
			{
				auto compared = maps.begin()->second;
				int key = maps.begin()->first;
				for (auto j : maps)
				{
					if (compared > j.second)
					{
						compared = j.second;
						key = j.first;
					}
				}
				maps.erase(key);
			}
			maps[temp].first = 1;
			maps[temp].second = i;
		}
	}

	for (auto i : maps)
		std::cout << i.first << ' ';

	return 0;
}