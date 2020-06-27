/*
	[백준]	16637		괄호 추가하기
	문제 출처 : https://www.acmicpc.net/problem/16637

	[풀이 방법] - 브루드 포스
		1. 괄호가 없는 경우
		2. 괄호가 있는 경우
		로 나눠서 dfs실행
*/


#include <iostream>
#include <string>
#include <algorithm>

int answer = -2147483647;		// 최대 값이 음수인 경우가 있음.
int N;
std::string str;

int cal(const int left, const int right, const char op)
{
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left*right;
	default:
		break;
	}
}

void dfs(int value, int index)
{
	if (index >= N-1)
	{
		answer = std::max(answer, value);
		return;
	}
	// 괄호 없는 경우
	if(index+2 < N)
		dfs(cal(value, str[index + 2]-'0', str[index + 1]), index + 2);
	// 괄호 있는 경우
	if(index+4 < N)
		dfs(cal(value, cal(str[index + 2]-'0', str[index + 4] - '0', str[index + 3]), str[index + 1]), index + 4);
}

int main()
{

	std::cin >> N;
	std::cin >> str;

	dfs(str[0]-'0', 0);
	std::cout << answer;
}
