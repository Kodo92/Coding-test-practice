#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isExist(vector<int>& numbers, int value)
{
	int min = 0, max = numbers.size() - 1, mid = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (numbers[mid] == value)
			return true;

		if (numbers[mid] > value)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return false;
}

// Bineary search 

int main()
{
	// cin ÃÖÀûÈ­?
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	vector<int> numbers;
	int number;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> number;
		if (isExist(numbers, number))
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}

	return 0;
}