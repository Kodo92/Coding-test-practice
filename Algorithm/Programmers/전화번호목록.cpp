#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	for (int i = 0; i < phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book.size(); j++)
		{
			if (i == j) continue;
			if (phone_book[i].size() > phone_book[j].size()) continue;
			if (phone_book[i] == phone_book[j].substr(0, phone_book[i].size()))
				return false;
		}
	}
	return true;
}

void main()
{
	//cout << boolalpha<<solution({ "119", "97674223", "1195524421" });
	cout << boolalpha << solution({ "1","1111111111111111111","1" });
}