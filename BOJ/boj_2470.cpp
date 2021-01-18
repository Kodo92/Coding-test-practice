#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	std::vector<int> solutions(N, 0);

	for (int i = 0; i < N; i++)
		std::cin >> solutions[i];

	std::sort(solutions.begin(), solutions.end());

	if (solutions.back() < 0)
		std::cout << solutions[solutions.size() - 2] << ' ' << solutions.back();
	else if (solutions.front() > 0)
		std::cout << solutions[0] << ' ' << solutions[1];
	else
	{
		int left = 0, right = solutions.size() - 1;
		long long sum;
		std::pair<int, std::pair<int, int>> answer{ abs(solutions[left]+solutions[right]), { left,right } };
		for (int i = 0; i < N - 1; i++)
		{
			sum = solutions[left] + solutions[right];
			if (answer.first > abs(sum))
			{
				answer.first = abs(sum);
				answer.second.first = left;
				answer.second.second = right;
			}
			(sum > 0) ? right-- : left++;
		}
		std::cout << solutions[answer.second.first] << ' ' << solutions[answer.second.second];
	}


	return 0;
}