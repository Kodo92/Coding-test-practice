#include <iostream>

using namespace std;

int getNumber(int a)
{
	if (a % 2 == 1)
		return (a + 1) / 2;
	else
		return a / 2;
}

int solution(int n, int a, int b)
{
	int answer = 1;

	while (n>1)
	{
		if (abs(a - b) == 1 && (a + 1) / 2 == (b + 1) / 2)
			break;
		n /= 2;
		answer++;
		a = getNumber(a);
		b = getNumber(b);
	}

	return answer;
}

/*
8, 2, 3 ÀÏ¶§ return 2;
*/