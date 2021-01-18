/*
	[백준]	세 용액
		문제 출처 : https://www.acmicpc.net/problem/2473
		키워드 : Two-pointer, Brute-force
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	std::vector<long long> solutions(N);
	for (int i = 0; i < N; i++)
		std::cin >> solutions[i];

	sort(solutions.begin(), solutions.end());
	
	std::vector<int> ans = { 0,N - 1,1 };

	bool is_find = false;
	long long result = 3e9;
	for (int i = 0; i < N-2 ; i++)
	{
		int left = i+1, right = N - 1;

		while (left < right)
		{
			long long sum = solutions[left] + solutions[right] + solutions[i];

			if (std::abs(sum) < result)
			{
				result = std::abs(sum);
				ans = { left,i,right };
				if (!sum)
				{
					is_find = true;
					break;
				}
			}

			(sum < 0) ? left++ : right--;
		}

		if (is_find)
			break;
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		std::cout << solutions[i] << ' ';
	return 0;
}

/*
input :
5
-2 6 -97 -6 98
output : 
-97 -2 98
*/

/*
input :
3
-1 -2 1
output :
-2 -1 1
*/

/*
input :
5
-10 -7 3 2 9
output :
-10 2 9
*/

/*
input :
10
1 2 3 4 5 8 9 10 23 100 
output :
1 2 3
*/

/*
abs != std::abs
*/