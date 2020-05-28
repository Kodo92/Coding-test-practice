#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getN(vector<long long>& lines, long long length)
{
	int n = 0;
	for (const auto value : lines)
	{
		n += value / length;
	}
	return n;
}

int main()
{
	cin.tie(0);//이 2줄 추가하면 맞음
	ios_base::sync_with_stdio(false);

	int k = 0, n = 0;
	cin >> k >> n;

	vector<long long> lines;
	long long length = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> length;
		lines.push_back(length);
	}

	sort(lines.begin(), lines.end());

	long long min = 1, max = lines.back(), mid = 0;
	int answer = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		length = getN(lines, mid);

		if (length >= n)
		{
			min = mid + 1;
			answer = answer < mid ? mid : answer;
			// 만들 수 있는 최대 랜선의 길이 && N개보다 많이 만드는 것도 n개를 만드는 것에 포함.
		}
		else
			max = mid - 1;
	}

	cout << answer;
}