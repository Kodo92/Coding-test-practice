#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	int r = 0;
	while (true)
	{
		r = a%b;
		a = b;
		b = r;
		if (r == 0)
			break;
	}
	return a;
}

long long solution(int w, int h)
{
	long long answer = static_cast<long long>(w)*static_cast<long long>(h);
	int gcd = (w>h) ? getGCD(w, h) : getGCD(h, w);
	answer -= ((w + h) - gcd);
	return answer;
}

void main()
{
	cout << solution(8, 12);
}