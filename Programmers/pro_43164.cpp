/*
	[프로] 여행 경로
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/43164
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string from, vector<vector<string>>& tickets, vector<bool>& isVisited, vector<string>& temp, vector<string>& answer, int count)
{
	temp.push_back(from);

	if (count == tickets.size())
	{
		answer = temp;
		return true;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == from && isVisited[i] == false)
		{
			isVisited[i] = true;
			
			if (DFS(tickets[i][1], tickets, isVisited, temp, answer, count + 1))
				return true;
			isVisited[i] = false;
		}
	}

	temp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer, temp;
	vector<bool> isVisted(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	DFS("ICN", tickets, isVisted, temp, answer, 0);
	return answer;
}

int main()
{

	//auto retval = solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });
	//auto retval = solution({ {"ICN", "B"},{"B", "C"},{"C", "ICN"},{"ICN", "D"},{"ICN", "E"},{"E", "F" }});
	//auto retval = solution({ {"ICN","A"},{"A","B"},{"B","A"},{"A","ICN"},{"ICN","A"} });
	auto retval = solution({ { "ICN", "BOO" }, {"ICN", "COO" }, { "COO", "DOO" }, { "DOO", "COO" }, { "BOO","DOO" }, { "DOO", "BOO" },
{ "BOO", "ICN" }, { "COO", "BOO" } });
	return 0;
}
