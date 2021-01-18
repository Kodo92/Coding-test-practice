#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;


	if (s[0] != '(' || s.back() != ')')
		return false;
	if (s.size() % 2 != 0)
		return false;

	int count = 0;
	for (auto& i : s)
	{
		if (i == '(')
			count++;
		else
			count--;

		if (count < 0)
			return false;
	}

	if (count != 0)
		return false;
	return answer;
}