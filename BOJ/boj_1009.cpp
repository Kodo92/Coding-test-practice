#include <iostream>
#include <vector>

int main() {

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> map;
	for (size_t i = 1; i <= 10; i++)
	{
		std::vector<int> temp;
		int value = i;
		temp.push_back(value);
		while (true) {
			value = (value * i) % 10;
			if (value == 0)
				value = 10;
			if (value == i)
				break;
			temp.push_back(value);
		}
		map.push_back(temp);
	}

	for (size_t i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a >> b;

		if (a == 1 || a==5  || a == 10) {
			std::cout << a << '\n';
			continue;
		}
		a %= 10;
		if (a == 0)
			a = 9;
		else
			a -= 1;

		int idx = (b % map[a].size()) - 1;
		if (idx < 0)
			idx = map[a].size() - 1;
		std::cout << map[a][idx] << '\n';
	}

	return 0;
}