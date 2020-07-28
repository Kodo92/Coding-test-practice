/*
	[PRO] 키패드 누르기
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67256

	[풀이 방법] 구현
		1. 목적지와 출발지 거리를 배열을 이용해서 계산한다.

	[실패 과정]
		1. 세로줄 숫자들의 값 차이는 3이다. 이를 이용해서 단순 숫자의 차를 구해서 거리를 계산했는데 
			왼손은 1, 오른손은 3, 목적지는 5일 때 오류가 있었다.

	[풀이 일자] 2020.07.28
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> position[] { {3,1},{0,0} ,{ 0,1 } ,{ 0,2 } ,{ 1,0 } ,{ 1,1 } ,{ 1,2 } ,{ 2,0 } ,{ 2,1 } ,{ 2,2 } } ;

int getDistance(const pair<int, int> source, const pair<int,int> dest)
{
	return abs(dest.first - source.first) + abs(dest.second - source.second);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> leftPosition = { 3,0 }, rightPosition = { 3,2 };

	for (auto i : numbers)
	{
		if (i == 1 || i == 4 || i == 7)
		{
			answer += 'L';
			leftPosition = position[i];
		}
		else if (i == 3 || i == 6 || i == 9)
		{
			answer += 'R';
			rightPosition = position[i];
		}
		else
		{
			int leftDistance = getDistance(leftPosition, position[i]);
			int rightDistance = getDistance(rightPosition, position[i]);
			if (leftDistance > rightDistance)
			{
				answer += 'R';
				rightPosition = position[i];
			}
			else if (rightDistance > leftDistance)
			{
				answer += 'L';
				leftPosition = position[i];
			}
			else
			{
				if (hand == "left")
				{
					answer += 'L';
					leftPosition = position[i];
				}
				else
				{
					answer += 'R';
					rightPosition = position[i];
				}
			}
		}
	}
	return answer;
}

int main()
{
	cout << solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");

	return 0;
}