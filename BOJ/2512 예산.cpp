#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getSum(vector<long long>& budgets, int value)
{
	long long sum = 0;
	for (const auto i : budgets)
		sum += ((i > value) ? value : i);
	return sum;
}

int main()
{
	cin.tie(0);//이 2줄 추가하면 맞음
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<long long> budgets;
	for (int i = 0; i < n; i++)
	{
		long long number = 0;
		cin >> number;
		budgets.push_back(number);
	}

	sort(budgets.begin(), budgets.end());

	long long m = 0;
	cin >> m;

	if (m >= getSum(budgets, budgets.back()))
		cout << budgets.back();
	else
	{
		int min = 1, max = budgets.back(), answer = 0;
		long long mid = 0;
		while (min <= max)
		{
			mid = (min + max) / 2;
			long long sum = getSum(budgets, mid);

			if (sum <= m)
			{
				answer = (answer < mid) ? mid : answer;
				min = mid + 1;
			}
			else
				max = mid - 1;
		}

		cout << answer;
	}
	return 0;
}

// test case
/*
4
120 110 140 150
485
answer : 127

3
1000000000 1000000000 1000000000
1000000000
answer : 333333333

3
100 125 485
1000
answer : 485
*/