#include	<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
bool getPosDirection(string name)
{
	// name�� ���̰� 1���� ���� ��� ����
	if (name.size() == 1)
		return false;

	// name�� ������ ���ڰ� A�� ��� ������ ��ȸ
	if (name.back() == 'A')
		return false;
	else
		return true;
}

int getAPos(string name, bool left)
{
	int Pos;
	if (!left)
	{
		for (Pos = name.size()-1; Pos >0; Pos--)
		{
			if (name[Pos] != 'A')
			{
				Pos++;
				break;
			}
		}
	}
	else
	{
		for (Pos = 1; Pos < name.size(); Pos++)
		{
			if (name[Pos] != 'A')
			{
				Pos--;
				break;
			}
		}
	}

	return Pos;
}
int solution(string name) {
	int answer = 0;
	int leftValue = 0, rightValue = 0;
	bool leftFlag = getPosDirection(name);
	int aPos = getAPos(name, leftFlag);


	leftValue = name.front() - 'A';
	rightValue = ('Z' + 1) - name.front();
	answer += (leftValue > rightValue) ? rightValue : leftValue;
	if (leftFlag)
	{
		for (int i = name.size() - 1; i > aPos; i--)
		{
			leftValue = name[i] - 'A';
			rightValue = ('Z' + 1) - name[i];
			answer += (leftValue > rightValue) ? rightValue : leftValue;
			answer++;
		}
	}
	else
	{
		for (int i =  1; i <aPos; i++)
		{
			leftValue = name[i] - 'A';
			rightValue = ('Z' + 1) - name[i];
			answer += (leftValue > rightValue) ? rightValue : leftValue;
			answer++;
		}
	}
	return answer;
}
*/

/*
int solution(string name)
{
	int answer = 0;
	vector<int> controlPos;
	for (int i = name.size() - 1; i > 0; i--)
	{
		if (name[i] != 'A')
			controlPos.push_back(i);
	}

	int nowPos = 0, nextPos = 0;
	int leftDirection = 0, rightDirection = 0;
	answer += min('Z' + 1 - name[nowPos], name[nowPos] - 'A');
	while (nextPos != controlPos.size())
	{
		leftDirection = (nowPos > controlPos[nextPos]) ? nowPos - controlPos[nextPos] : name.size() + nowPos - controlPos[nextPos];
		rightDirection = (nowPos > controlPos[nextPos]) ? name.size() + controlPos[nextPos] - nowPos : controlPos[nextPos] - nowPos;
		
		if(rightDirection < leftDirection && nowPos > controlPos[nextPos])
		{
			nextPos = 0;
			nowPos = 0;
			answer = 0;
			reverse(controlPos.begin(),controlPos.end()); continue;
		}
		answer += (leftDirection > rightDirection) ? rightDirection : leftDirection;
		
		nowPos = controlPos[nextPos];

		answer += min('Z' + 1 - name[nowPos], name[nowPos] - 'A');
		nextPos++;
	}

	return answer;
}
*/

// 2ȸ Ǯ��
/*
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
*/
int solution(string name)
{
	int answer = 0;
	string compare(name.size(),'A');

	int nextPos = 0, leftDirection = 0, rightDirection = 0;
	
	while (compare != name)
	{
		answer += min(name[nextPos] - 'A', 'Z' + 1 - name[nextPos]);
		compare[nextPos] = name[nextPos];

		if (compare == name) break;

		for (int i = 1; i < name.size(); i++)
		{
			leftDirection = (nextPos - i < 0) ? nextPos + name.size() - i : nextPos - i;
			rightDirection = (nextPos + i >= name.size()) ? nextPos + i - name.size() : nextPos + i;

			if (compare[rightDirection] != name[rightDirection])
			{
				nextPos = rightDirection;
				answer += i;
				break;
			}
			else if (compare[leftDirection] != name[leftDirection])
			{
				nextPos = leftDirection;
				answer += i;
				break;
			}
			else continue;
		}
	}

	return answer;
}

void main()
{
	cout << solution("JAAZ") << '\n';
	cout << solution("AAA") << '\n';
	cout << solution("JAZ") << '\n';
	cout << solution("ZZZ") << '\n';
	cout << solution("BBBBAAAABA") << '\n';
	cout << solution("AABAAAAAAABBB") << '\n';

}

/*
�׽�Ʈ ���̽� :
JAAZ : 11
AAA : 0
JZA : 11
ZZZ : 5
ABABAAAAABA : 13		-> ���� ABAB �� �����ʼ�ȸ
AABAAAAAAABBB : 12
*/

/*
������ ��ġ -> ���� -> ù��° ��ġ : ok
*/