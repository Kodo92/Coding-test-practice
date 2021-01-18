#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& rocks, int distance, int min, int n)
{
	int removeCount = 0;
	int last = 0;
	for (int i = 0; i <= rocks.size(); i++)
	{
		if (((i == rocks.size()) ? distance : rocks[i]) - last < min)
			removeCount++;
		else
			last = rocks[i];
	}

	return removeCount <= n;
}

int solution(int distance, vector<int> rocks, int n) {
	int min = 0, max = distance, mid = 0;
	int answer = 0;
	sort(rocks.begin(), rocks.end());

	while (min <= max)
	{
		mid = (min + max) / 2;
		if (isPossible(rocks, distance, mid, n))
		{
			answer = (answer < mid) ? mid : answer;
			min = mid + 1;
		}
		else
			max = mid - 1;
	}

	return answer;
}

void main()
{
	solution(25, { 2,14,11,21,17 },2);
}