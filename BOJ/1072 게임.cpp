#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0;
	cin >> x >> y;

	if (x == y)
	{
		cout << -1;
		return 0;
	}

	long long win = static_cast<long long>(y) * 100 / x;

	int min = 0, max = x, mid = 0;
	int answer = -1;
	while (min <= max)
	{
		mid = (min + max) / 2;
		long long temp = (static_cast<long long>(y + mid) * 100) / (x + mid);
		if (temp > win)
		{
			max = mid - 1;
			answer = mid;
		}
		else
			min = mid + 1;
	}

	cout << answer;
	return 0;
}