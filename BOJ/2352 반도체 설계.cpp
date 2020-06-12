#include <iostream>
#include <vector>
#include <algorithm>

// N log N
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> ports;
	ports.push_back(0);

	int secondPort;
	for (int i = 0; i < N; i++)
	{
		std::cin >> secondPort;
		if (ports.back() < secondPort) ports.push_back(secondPort);
		else
		{
			auto lower = std::lower_bound(ports.begin(), ports.end(), secondPort);
			*lower = secondPort;
		}
	}

	std::cout << ports.size()-1;
}

//N²
/*

int main()
{
	std::vector<int> test{ 4,5,6,1,2 };
	auto lower = std::lower_bound(test.begin(), test.end(), test[0]);
	auto upper = std::upper_bound(test.begin(), test.end(), test[0]);
	int N;
	std::cin >> N;
	std::map<int,int> ports;

	int secondPort;
	for (int i = 0; i < N; i++)
	{
		std::cin >> secondPort;
		ports[secondPort-1] = i;
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int count = 0, currentPos = 0;
		for (int j = i; j < N; j++)
		{
			if (currentPos > ports[j])
				continue;
			currentPos = ports[j];
			count++;
		}
		max = (max < count) ? count : max;
	}
	std::cout << max;
}
*/

/*
	LIS (Longest Increasing Subsequence) 문제
	링크 : 
*/