#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
	string answer;

	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] != s[i + 1])
		{
			if (s[i] != answer.back())
				answer += s[i];
			else
				answer.pop_back();
		}
		else
			i++;
	}

	return (answer.size() == 0) ? 1 : 0;
}

