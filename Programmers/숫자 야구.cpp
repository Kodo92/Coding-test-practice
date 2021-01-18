#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

void setArray(int _Number, array<int, 3>& _Array)
{
	_Array[0] = _Number / 100;
	_Array[1] = (_Number / 10) % 10;
	_Array[2] = _Number % 10;
}

bool checkNumber(int _checkNum, int _refNum, int _strike, int _ball)
{
	array<int, 3> checkNumbers, refNumbers;
	setArray(_checkNum, checkNumbers);
	setArray(_refNum, refNumbers);

	if (checkNumbers[0] == checkNumbers[1] || checkNumbers[0] == checkNumbers[2] || checkNumbers[1] == checkNumbers[2]) return false;
	if (checkNumbers[0] == 0 || checkNumbers[1] == 0 || checkNumbers[2] == 0) return false;

	int strike = 0, ball = 0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (checkNumbers[i] == refNumbers[j])
			{
				if (i == j)
					strike++;
				else
					ball++;
			}
		}
	}
	if (strike == _strike && ball == _ball)
		return true;
	else
		return false;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	bool checkFlag = false;
	for (int i = 123; i<=987; i++)
	{
		checkFlag = true;
		for (auto j : baseball)
		{
			if (!checkNumber(i, j[0], j[1], j[2]))
			{
				checkFlag = false;
				break;
			}
		}
		if (checkFlag)
			answer++;
	}
	return answer;
}

void main()
{
//	cout << solution({ {123,1,1},{356,1,0},{327,2,0},{489,0,1} });
	cout << solution({ { 123,0,0 }});
}

/*
Point!
- 각 자리 수는 중복되지 않으며, 0이 아니다.
*/