#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(0);//이 2줄 추가하면 맞음
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n;

	int number = 0;
	map<int, int> cards;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		cards[number]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> number;
		cout << cards.find(number)->second << ' ';
	}
}
