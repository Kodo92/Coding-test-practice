/*
	[백준] 문자열 폭발
		문제 출처 : https://www.acmicpc.net/problem/9935

	[실패 과정]
		1. 문자열 순회하면서 폭발 문자열 존재하면 제거 후 폭발 문자열이 존재하지 않을 때 까지 루프. -> 시간초과
		2. 스택을 이용해 input에 삽입하고 스택의 끝과 폭발 문자열 비교, 임시 스택에 일치한 문자 삽입 문자열 체크 -> 시간 초과 

	[참고]
		https://jaimemin.tistory.com/823
*/

#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string input, boomString;
	std::cin >> input >> boomString;

	std::string st;
	for (int i = 0; i < input.size(); i++)
	{
		st.push_back(input[i]);
		if (st.size() >= boomString.size() && st.back() == boomString.back())
		{
			bool isDetection = true;
			int k = 0, stSize = st.size()-1;
			for (auto j = boomString.rbegin(); j != boomString.rend(); j++, k++)
			{
				if (st[stSize - k] != *j)
				{
					isDetection = false;
					break;
				}
			}
			if (isDetection)
			{
				for (int j = 0; j < boomString.size(); j++)
					st.pop_back();
			}
		}
	}

	if (st.size() == 0)
		std::cout << "FRULA";
	else
		std::cout << st;

	return 0;
}