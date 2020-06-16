#include <iostream>
#include <vector>;
#include <algorithm>

int N;
std::vector<int> numbers;
int min = 2147483647, max = -2147483647;

void dfs(int value, int count, std::vector<int> operatorCount)
{
	if (count == N)
	{
		min = std::min(min, value);
		max = std::max(max, value);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operatorCount[i] != 0)
		{
			operatorCount[i] -= 1;
			if (i == 0)
				dfs(value + numbers[count], count + 1, operatorCount);
			else if(i==1)
				dfs(value - numbers[count], count + 1, operatorCount);
			else if (i == 2)
				dfs(value * numbers[count], count + 1, operatorCount);
			else
				dfs(value / numbers[count], count + 1, operatorCount);
			operatorCount[i] += 1;
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	numbers.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> numbers[i];

	std::vector<int> operatorCount(4);
	for (int i = 0; i < 4; i++)
		std::cin >> operatorCount[i];

	dfs(numbers[0], 1, operatorCount);

	std::cout << max << '\n' << min;


	return 0;
}