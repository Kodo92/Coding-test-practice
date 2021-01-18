/*
	[����] 3���� ������
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/68935?language=cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {

	std::string ternary;
	while (n > 0)
	{
		ternary = to_string(n%3) + ternary;
		n /= 3;
	}

	int answer = 0;

	for (int i = 0; i < ternary.size(); i++)
		answer += ((ternary[i] - '0') * (int)std::pow(3,i));
		
	return answer;
}

int main()
{
	std::cout << solution(125);

	return 0;
}


/*
[���� ����]
	1. 3���� �ڸ��� ������ �ݺ��� -> pow �Լ��� �̿�		: �ִ� 0.02ms / 3.95MB -> �ִ� 0.04ms / 3.96MB
*/