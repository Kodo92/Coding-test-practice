#include <iostream>
#include <vector>

std::vector<bool> isUseable(10, true);

bool isIn(int value)
{
	if (value < 0)
		return true;

	if (value == 0)
		return !isUseable[value];

	for (int i = 1; value/i != 0; i *= 10)
	{
		if (!isUseable[(value/i) % 10])
			return true;
	}
	return false;
}

int getDigits(int value)
{
	int count = 1;
	for (int i = 10; value / i != 0; i *= 10, count++);
	return count;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int answer = 0;
	if (n == 100)
		answer = 0;
	else if (m == 10)
		answer = abs(100 - n);
	else
	{
		int temp;
		for (int i = 0; i < m; i++)
		{
			std::cin >> temp;
			isUseable[temp] = false;
		}

		int count = 0;
		while (true)
		{
			if (!isIn(n - count))
			{
				count += getDigits(n - count);
				break;
			}
			if (!isIn(n + count))
			{
				count += getDigits(n + count);
				break;
			}
			count++;
		}
		answer = count;
	}

	std::cout << ((answer < abs(n-100))?answer:abs(n-100));

	return 0;
}
/*
int lowerBound(const int value)
{
	for (int i = value-1; i >= 0; i--)
		if (isUseable[i])
			return i;

	return -1;
}

int upperBound(const int value)
{
	for (int i = value; i < 10; i++)
		if (isUseable[i])
			return i;

	return -1;
}

bool isIn(int sourceNumber)
{
	if (sourceNumber < 0)
		return true;
	for (int i = 0; i <= 5; i++)
	{
		if (!isUseable[sourceNumber % 10])
			return true;
		sourceNumber /= 10;
	}
	return false;
}

int getDigits(int value)
{
	int count = 0;

	if (value == 0)
		return 1;

	while (value != 0)
	{
		value /= 10;
		count++;
	}
	return count;
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	// 사용 불가능한 버튼 
	int disableNumber;
	for (int i = 0; i < m; i++)
	{
		std::cin >> disableNumber;
		isUseable[disableNumber] = false;
	}

	//1번 (N이 100인 경우)
	if (n == 100)
		std::cout << 0;
	// 2번 ( 버튼이 모두 망가진 경우)
	else if (m == 10)
		std::cout << abs(n - 100);
	else
	{
		// 3가지 경우 count들을 보관 -> 후에 정렬 후 최소값 리턴
		std::vector<int> answers;

		// 숫자 + +- : 10 * 6 = 60
		int temp = n, remainder = 0;
		int dest = 0, count = 0;
		for (int i = 0; i <= 5; i++)
		{
			remainder = temp % 10;
			count++;
			if (isUseable[remainder])
				dest += remainder * pow(10, i);
			else
			{
				const int lower = lowerBound(remainder);
				const int upper = upperBound(remainder);

				const int lowerDistance = abs(lower - remainder);
				const int upperDistance = abs(upper - remainder);
				if (lower != -1 && lowerDistance <= upperDistance)
					dest += lower * pow(10, i);
				else if (upper != -1)
					dest += upper  * pow(10, i);
			}
			temp /= 10;
			if (temp == 0)
				break;
		}
		if (dest == 0)
			count = 1;
		answers.push_back(count + abs(dest - n));

		// 숫자 + +- ver 2. loop
		// ver1번보다 느리면 더이상 계산을 하지 않음.
		int verCount = 0;
		while (verCount <= count)
		{
			if (!isIn(n + verCount))
			{
				answers.push_back(verCount + getDigits(n+verCount));
				break;
			}
			if (!isIn(n - verCount))
			{
				answers.push_back(verCount + getDigits(n - verCount));
				break;
			}
			verCount++;
		}

		answers.push_back(abs(n - 100));

		std::sort(answers.begin(), answers.end());

		std::cout << answers.front();
	}
	return 0;
}
*/
/*
1. N = 100 인 경우
2. 버튼이 모두 망가진 경우
3. 숫자 +-가 빠른 경우
4. +-가 빠른 경우
*/

/*
test case
0 
9
0 1 2 3 4 5 6 7 9
output : 9

9999
1
9
output : 6

162
9
0 1 3 4 5 6 7 8 9
output : 62

5
2
4 6
output : 1

10
9
1 2 3 4 5 6 7 8 9
output : 11
*/