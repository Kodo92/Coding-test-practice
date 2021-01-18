/*
	[백준] 회전 초밥
		문제 출처 : https://www.acmicpc.net/problem/15961
		키워드 : Two-pointer
*/

#include <iostream>
#include <vector>
#include <map>
int n, d, k, c;

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> n >> d >> k >> c;

	std::vector<int> sushis(n);
	std::vector<int> food(d + 1, 0);

	int count = 0;
	int answer = 0;
	
	for (int i = 0; i < k; i++)
	{
		std::cin >> sushis[i];
		food[sushis[i]]++;
		if (food[sushis[i]] == 1)
			count++;
	}

	for (int i = 1; i < k; i++)
	{

	}
	answer = count;
		int prev_index = i + n - k;
		range[sushis[prev_index]]--;
		if (range[sushis[prev_index]] == 0)
			count--;

		int temp = count;
		if (!range[c])
			temp++;
		answer = (answer < temp) ? temp : answer;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> sushis[i];
		food[sushis[i]]++;
		if (food[sushis[i]] == 1)
			count++;
		if (i < k - 1)
			continue;
		else if (i >= k)
		{
			range[sushis[i - k]]--;
			if (range[sushis[i - k]] == 0)
				count--;
		}
		int temp = count;
		if (!range[c])
			temp++;
		answer = (answer < temp) ? temp : answer;
	}




	std::cout << answer;
}