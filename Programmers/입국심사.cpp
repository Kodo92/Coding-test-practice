#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long max = times.back() * n, min = times.front();
	long long mid = (max + min) / 2;
	long long answer = 0;
	while (min <= max)
	{
		int sum = 0;
		mid = (max + min) / 2;

		for (const auto value : times)
			sum += mid / value;

		if (sum >= n)
		{
			max = mid - 1;
			answer = mid;
		}
		else 
			min = mid+1;
	}
	return mid;
}

void main()
{
	solution(6, { 7,10});
}