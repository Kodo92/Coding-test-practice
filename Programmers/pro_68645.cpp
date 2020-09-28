/*
	[����] �ﰢ ������
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/68645
		��� : ���� �ڵ� ç���� ����1 - 9��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {

	vector<int> startingIndexs(n);
	startingIndexs[0] = 0;
	for (int i = 1; i < n; i++)
		startingIndexs[i] = startingIndexs[i - 1] + i;



	vector<int> answer((n * (n + 1) / 2), 0);
	pair<int, int> prevIndex{ 0,0 };
	int number = 1;
	for (int i = 0; i < n; i++)
	{
		int range = n - i;
		switch (i % 3)
		{
			// /
		case 0:
		{
			int yIndex = i / 3 * 2;
			int xIndex = i / 3;
			for (int j = 0; j < range; j++, yIndex++)
				answer[(startingIndexs[yIndex] + xIndex)] = number++;

			prevIndex = { yIndex - 1,xIndex };
			break;
		}
		// -
		case 1:
		{
			int yIndex = prevIndex.first;
			int xIndex = prevIndex.second + 1;
			for (int j = 0; j < range; j++, xIndex++)
				answer[(startingIndexs[yIndex] + xIndex)] = number++;

			prevIndex = { yIndex,xIndex - 1 };
			break;
		}
		case 2:
		{
			int yIndex = prevIndex.first - 1;
			int xIndex = prevIndex.second - 1;
			for (int j = 0; j < range; j++, yIndex--, xIndex--)
				answer[(startingIndexs[yIndex] + xIndex)] = number++;
			prevIndex = { yIndex + 1,xIndex + 1 };
			break;
		}
		default:
			break;
		}
	}
	return answer;
}

int main()
{
	solution(4);
	return 0;
}