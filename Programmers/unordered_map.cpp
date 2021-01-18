// unordered_map.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

string solution(vector<string> participants, vector<string> completion)
{
	string answer = "";

	unordered_map<string, int> par;

	for (auto& Data : completion)
	{
		if (par.find(Data) == par.end())
			par.insert(std::make_pair(Data, 1));
		else
			par[Data]++;
	}

	for (auto& Data : participants)
	{
		if (par.find(Data) == par.end())
			return Data;
		else
		{
			par[Data]--;
			if (par[Data] < 0)
			{
				answer = Data;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	vector<string> participants = { "marina","josipa","nikola","vinko","filipa" };
	vector<string> completion = { "josipa","filipa","marina","nikola" };

	cout << solution(participants, completion) << endl;
    return 0;
}

