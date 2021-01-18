#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getData(vector<pair<string, int>>& books, string name)
{
	int min = 0, max = books.size() - 1, mid = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (books[mid].first == name)
			return books[mid].second + 1;
		else if (books[mid].first > name)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return -1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;

	vector<pair<string, int>> books;
	vector<string> indexOfBooks;

	for (int i = 0; i < n; i++)
	{
		string name = "";
		cin >> name;
		books.push_back(make_pair(name, i));
		indexOfBooks.push_back(name);
	}

	sort(books.begin(), books.end());

	for (int i = 0; i < m; i++)
	{
		string input = "";
		cin >> input;
		if (isdigit(input[0]))
			cout << indexOfBooks[stoi(input)-1] << '\n';
		else
			cout << getData(books, input) << '\n';
	}
	return 0;
}