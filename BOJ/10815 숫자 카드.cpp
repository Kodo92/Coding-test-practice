#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isExist(vector<int>& cards, int value)
{
	int min = 0, max = cards.size() - 1, mid = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (cards[mid] == value)
			return true;
		else if (cards[mid] > value)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n;

	int number = 0;
	vector<int> cards;
	for (int i = 0; i<n; i++)
	{
		cin >> number;
		cards.push_back(number);
	}

	sort(cards.begin(), cards.end());

	cin >> m;

	for (int i = 0; i<m; i++)
	{
		cin >> number;
		isExist(cards, number) ? cout << '1' : cout << '0';
		cout << ' ';
	}

	return 0;
}

// test case
/*
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
answer : 1 0 0 1 1 0 0 1

*/