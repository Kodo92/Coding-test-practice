#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool checkCondition(string condition, string permutation)
{
	char firstChar = condition[0], secondChar = condition[2];
	int firstPos = permutation.find(firstChar), secondPos = permutation.find(secondChar);
	int distance = atoi(&condition[4]);
	switch (condition[3])
	{
	case '=':
	{
		if (abs(firstPos - secondPos )-1 == distance)
			return true;
		return false;
	}
	case '<':
	{
		if (abs(firstPos - secondPos)-1 < distance)
			return true;
		return false;
	}
	case '>':
	{
		if (abs(firstPos - secondPos)-1 > distance)
			return true;
		return false;
	}
	default:
		return false;
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string position = "ACFJMNRT";
	bool findFlag = true;
	do
	{
		findFlag = true;
		for (auto i : data)
		{
			if (!checkCondition(i, position))
			{
				findFlag = false;
				break;
			}
		}
		if (findFlag)
			answer++;
	} while (next_permutation(position.begin(), position.end()));
	return answer;
}

void main()
{
	//cout << solution(2, { {"N~F=0"}, {"R~T>2"} });
	cout << solution(2, { { "M~C<2" },{ "C~M>1" } });
}