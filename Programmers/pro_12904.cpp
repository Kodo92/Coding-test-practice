/*
	[프로] 가장 긴 팰린드롬
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12904
*/

#include <iostream>
#include <string>

using namespace std;

int oddCount(const int startIndex, const string& s)
{
	int answer = 1;

	for (int j = 1; startIndex - j >= 0; j++)
	{
		if (s[startIndex - j] == s[startIndex + j])
			answer += 2;
		else
			break;
	}

	return answer;
}

int evenCount(const int startIndex, const string& s)
{
	if (s[startIndex] != s[startIndex + 1])
		return 0;
	int answer = 2;

	for (int j = 1; startIndex - j >= 0 && startIndex + j + 1 < s.size(); j++)
	{
		if (s[startIndex - j] == s[startIndex + j+1])
			answer += 2;
		else
			break;
	}

		return answer;
}

int getMax(const int a, const int b, const int c)
{
	int answer = (a < b) ? b : a;
	answer = (answer < c) ? c : answer;
	return answer;
}
int solution(string s)
{
	int answer = 1;

	for (int i = 1; i < s.size() - 1; i++)
	{
		int odd = oddCount(i, s);
		int even = evenCount(i, s);
		answer = getMax(answer, odd, even);
	}
	return answer;
}

int main()
{
	cout << solution("abcdcba") << endl;
	cout << solution("abacde") << endl;
	cout << solution("a") << endl;
	cout << solution("aaaa") << endl;

	return 0;
}