#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getCount(vector<long long>& homes, int distance)
{
	int count = 1;
	long long pos = homes.front();

	for (const auto i : homes)
	{
		if (i - pos >= distance)
		{
			count++;
			pos = i;
		}
	}
	return count;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n = 0, c = 0;
	cin >> n >> c;

	vector<long long> homes;
	for (int i = 0; i < n; i++)
	{
		long long position;
		cin >> position;
		homes.push_back(position);
	}

	sort(homes.begin(), homes.end());

	long long min = 1, max = homes.back()-homes.front(), mid = 0;
	long long answer = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (getCount(homes, mid) < c)
			max = mid - 1;
		else
		{
			min = mid + 1;
			answer = mid;
		}
	}
	cout << answer;
	return 0;
}