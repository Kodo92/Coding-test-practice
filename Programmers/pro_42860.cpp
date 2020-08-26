/*
	[프로그래머스] 42860 조이스틱
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42860

	[풀이 방법]
		1. 상하 방향 중 최소 이동 방향을 구한다.
			- 위쪽 방향은 목표 알파벳 - 현재 알파벳 'A'
			- 아래쪽 방향은 'Z'+1 - 목표 알파벳
		2. A로 구성된 임시 문자열을 2개 생성한다.	:	name이 전부 A로 바뀌면 종료.
			- 왼쪽과 오른쪽 방향 중 제일 가까운 위치를 구한다.	: AJAAAZ 케이스 J부터 오른쪽은 3번, 왼쪽은 2번
			- 매개변수로 들어온 name과 임시 문자열 str의 값을 swap한다.
*/


#include <iostream>
#include  <string>
#include <algorithm>

using namespace std;

int nameSize;

int changeChar(string& name, string& str, const int index)
{
	int upCount = name[index] - 'A';
	int downCount = 'Z' + 1 - name[index];
	swap(str[index], name[index]);
	return min(upCount, downCount);
}

int getIndex(const string& name, const string& str, const int nowPos, int* destPos)
{
	int leftCount = 1, leftIndex = nowPos - 1, rightCount = 1, rightIndex = nowPos + 1;
	if (leftIndex < 0)
		leftIndex += str.size();
	if (rightIndex >= str.size())
		rightIndex %= str.size();

	while (name[leftIndex] == 'A')
	{
		leftIndex--;
		leftCount++;
		if (leftIndex < 0)
			leftIndex += str.size();
	}
	while (name[rightIndex] == 'A')
	{
		rightIndex++;
		rightCount++;
		if (rightIndex >= str.size())
			rightIndex %= str.size();
	}
	if (leftCount < rightCount)
	{
		*destPos = leftIndex;
		return leftCount;
	}
	else
	{
		*destPos = rightIndex;
		return rightCount;
	}
}

int solution(string name) {

	string str;

	for (int i = 0; i < name.size(); i++)
		str.push_back('A');
	string tempStr = str;
	int nowPos = 0, destPos = 0;
	int answer = 0;

	if (name[0] != 'A')
		answer += changeChar(name, str, 0);

	while (tempStr != name)
	{
		answer += getIndex(name, str, nowPos, &destPos);
		answer += changeChar(name, str, destPos);
		nowPos = destPos;
	}

	return answer;
}

int main()
{
	cout << solution("AAAAAAAAAAAAAAAAAAAA")<<endl;
	cout << solution("JAZ") << endl;
	cout << solution("JEROEN") << endl;

	return 0;
}