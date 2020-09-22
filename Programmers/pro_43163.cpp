/*
	[프로] 단어 변환
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/43163
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int answer;
string targetString;

void DFS(const string begin, map<string,bool> isUsed, const int count)
{
	if (count > answer)
		return;

	if (begin == targetString)
	{
		answer = (answer > count) ? count : answer;
		return;
	}

	for (int i = 0; i < begin.size(); i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			string newStr = begin;
			newStr[i] = j;
			auto retval = isUsed.find(newStr);
			if (retval == isUsed.end() || isUsed[newStr])
				continue;
			isUsed[newStr] = true;
			DFS(newStr, isUsed, count + 1);
			isUsed[newStr] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	answer = words.size();
	targetString = target;

	map<string, bool> isUsed;
	for (const auto& i : words)
		isUsed[i] = false;

	DFS(begin,isUsed, 0);

	return answer;
}

int main()
{

	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;

	return 0;
 }