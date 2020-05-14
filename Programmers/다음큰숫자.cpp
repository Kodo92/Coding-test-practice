#include <iostream>

using namespace std;

int calBinaryCount(int n)
{
	int count = 0;
	while (n>0)
	{
		if (n % 2 == 1)
			count++;
		n /= 2;
	}
	return count;
}

int solution(int n) {
	int answer = n + 1;

	int binaryCount = calBinaryCount(n);

	while (true)
	{
		if (binaryCount == calBinaryCount(answer))
			break;
		answer++;
	}
	return answer;
}

void main()
{
	cout << solution(78);
}