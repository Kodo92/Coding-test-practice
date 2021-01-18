#include <iostream>
#include <string>
#include <vector>

#include <set>
#include <algorithm>

using namespace std;


set<vector<int>> bannedList;
bool	usedIndex[8];

bool checkString(string uid, string bid)
{
	if (uid.size() != bid.size()) return false;

	for (int i = 0; i < uid.size(); i++)
	{
		if (bid[i] != '*' && uid[i] != bid[i])
		{
			return false;
		}
	}
	return true;
}

void checkBanned(vector<string> uid, vector<string> bid, int bIndex, vector<int> banList)
{
	if (bIndex == bid.size())
	{
		sort(banList.begin(), banList.end());
		bannedList.insert(banList);
		return;
	}

	for (int i = 0; i < uid.size(); i++)
	{
		if (!usedIndex[i] && checkString(uid[i], bid[bIndex]))
		{
			banList.push_back(i);
			usedIndex[i] = true;

			checkBanned(uid, bid, bIndex + 1, banList);
			
			banList.pop_back();
			usedIndex[i] = false;			
		}
	}

	return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	
	vector<int> banList;

	checkBanned(user_id, banned_id, 0, banList);

	return bannedList.size();
}

void main()
{
	
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << endl;;
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" }) << endl;
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << endl;
}