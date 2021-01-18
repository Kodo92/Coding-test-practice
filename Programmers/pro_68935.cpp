/*
	[프로] 3진법 뒤집기
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/68935?language=cpp
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
[개선 사항]
	1. 3진법 자리수 제곱을 반복문 -> pow 함수를 이용		: 최대 0.02ms / 3.95MB -> 최대 0.04ms / 3.96MB
*/