#include <iostream>
#include <string>

int N;
std::string answer;

/*
풀이 방법 :
1. N 자릿수의 수열을 재귀를 이용해 만든다.
	- 이때 재귀를 N번 호출하지 않더라도 나쁜 수열이 되면 재귀를 호출하지 않는다.
*/

bool isGood(std::string str)
{
	for (int i = 0; i < str.size()-1; i++)
	{
		for (int j = 1; j <= (str.size() - i) / 2; j++)
		{
			if (str.substr(i, j) == str.substr(i + j, j))
				return false;
		}
	}
	return true;
}

bool makeSequence(int count = 0, std::string str = "")
{
	if (count == N)
	{
		if (isGood(str))
		{
			answer = str;
			return true;
		}
	}
	for (char c = '1'; c <= '3'; c++)
	{
		if (isGood(str + c))
			if (makeSequence(count + 1, str + c))
				return true;
	}
	return false;
}

int main()
{
	std::cin >> N;
	makeSequence();

	std::cout << answer;
}