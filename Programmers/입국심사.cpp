#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long max = times.back() * n, min = times.front();
	long long mid = (max + min) / 2;
	
	while (min <= max)
	{
		int sum = 0;
		mid = (max + min) / 2;

		for (const auto value : times)
			sum += mid / value;

		if (sum > n)
			max = mid -1;
		else 
			min = mid+1;
	}
	return mid;
	/*
	vector<long long> processTimes;
	for (int i = 1; i <= (n / 2) + 1; i++)
	{
		for (const auto value : times)
			processTimes.push_back(static_cast<long long>(value) * i);
	}

	sort(processTimes.begin(), processTimes.end());
	long long answer = 0;

	return processTimes[n - 1];
	*/
}

void main()
{
	solution(6, { 7,10});
}