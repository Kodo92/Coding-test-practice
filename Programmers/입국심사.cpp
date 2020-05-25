#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long max = static_cast<long long>(times.back()) * n, min = 1;
	long long answer = max;
	while (min <= max)
	{
		long long sum = 0;
		long long mid = (max + min) / 2;

		for (const auto value : times)
			sum += mid / value;

		if (sum >= n)
		{
			max = mid - 1;
			if (answer > mid)
				answer = mid;
		}
		else
			min = mid + 1;
	}
	return answer;
}

/*
test case 7 : times sort
test case 8 : max 계산 범위 
*/