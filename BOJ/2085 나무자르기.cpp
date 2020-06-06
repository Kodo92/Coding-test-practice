#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;

long long getTreeLength(vector<int>& trees, int n)
{
	long long length = 0;
	for (const auto value : trees)
	{
		if (value > n)
			length += static_cast<long long>(value) - n;
	}
	return length;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	int height;
	vector<int> trees;
	for (int i = 0; i < n; i++)
	{
		cin >> height;
		trees.push_back(height);
	}
	std::sort(trees.begin(), trees.end());

	long long min = 0, max = trees.back(), mid = 0;
	long long answer = max;
	while (min <= max)
	{
		mid = (min + max) / 2;
		long long length = getTreeLength(trees, mid);
		if (length == m)
		{
			answer = mid;
			break;
		}
		else if (length > m)
		{
			min = mid + 1;
			answer = mid;
		}
		else
			max = mid - 1;

	}

	cout << answer << '\n';
	return 0;
}


// testcase
/*
4 7
20 15 10 17

answer : 15

2 3
2 2
answer : 0

5 2000000000
900000000 900000000 900000000 900000000 900000000

answer : 500000000
*/