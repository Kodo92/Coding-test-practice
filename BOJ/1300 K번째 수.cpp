/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;

	int left = 1, right = k, mid = 0;
	long long answer = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int count = 0;
		for (int i = 1; i <= n; i++)
			count += std::min((mid / i), n);

		if (count < k)
			left = mid + 1;
		else
		{
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer;
}
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n = 0, k = 0;
	cin >> n >> k;

	long long left = 1, right = n*n, mid = 0;
	long long answer = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		long long count = 0;
		for (int i = 1; i <= n; i++)
			count += min(n, mid / i);

		if (count < k)
			left = mid + 1;
		else
		{
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer;
}