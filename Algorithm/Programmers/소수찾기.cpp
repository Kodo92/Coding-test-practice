#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkPrimeNumber(int _Number)
{
	for (int i = 2; i*i <= _Number; i++)
		if (_Number % i == 0)
			return false;

	return true;
}

bool checkPermutation(int _primeNumber, string _Numbers)
{
	bool findFlag = false;
	string newString = to_string(_primeNumber);
	for (int i = 0; i < newString.size(); i++)
	{
		findFlag = false;
		for (int j = 0; j < _Numbers.size(); j++)
		{
			if (newString[i] == _Numbers[j])
			{
				findFlag = true;
				_Numbers.erase(_Numbers.begin() + j);
				break;
			}
		}
		if (!findFlag) return false;
	}

	return true;
}

int solution(string numbers) {
	
	int answer = 0;
	sort(numbers.begin(), numbers.end());
	string maxNumberString = "";
	for(auto i = numbers.rbegin(); i != numbers.rend(); i++)
		maxNumberString += *i;
	int maxNumber = stoi(maxNumberString);

	for (int i = 2; i <= maxNumber; i++)
	{
		if (checkPrimeNumber(i))
		{
			if (checkPermutation(i, numbers))
			{
				cout << i << ' ';
				answer++;
			}
		}
	}

	return answer;
}

void main()
{
	cout << endl<<solution("71") << endl;
}