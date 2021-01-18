/*
	[프로] 블록 이동하기
		문제 출처 :https://programmers.co.kr/learn/courses/30/lessons/60063
		비고 : 2020 KAKAO BLIND RECRUITMENT
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum direction {UP=0,DOWN,LEFT,RIGHT};
int directionX[]{ 0,0,-1,1 };
int directionY[]{ -1,1,0,0 };
int limitSize;
struct robot
{
	int y, x;
	direction dir;
	int time;
};

bool checkPosition(const int y, const int x)
{
	if (y < 0 || y >= limitSize || x < 0 || x >= limitSize)
		return false;
	return true;
}

int solution(vector<vector<int>> board) {
	limitSize = board.size();
	pair<int, int> destPosition{ limitSize-1,limitSize-1 };
	robot root{0, 0, direction::RIGHT, 0};
	vector<vector<vector<bool>>> isVisited(board.size(), vector<vector<bool>>(board.front().size(), vector<bool>(4,false)));
	isVisited[0][0][direction::RIGHT] = true;

	auto cmp = [](const robot& a, const robot& b) {return a.time > b.time; };
	priority_queue<robot, vector<robot>, decltype(cmp)> queue(cmp);
	queue.push(root);

	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();

		pair<int, int> originPosition, sidePosition;
		originPosition = { top.y,top.x };
		sidePosition = { top.y + directionY[top.dir], top.x + directionX[top.dir] };
		
		if (originPosition == destPosition || sidePosition == destPosition)
			return top.time;

		int newTime = top.time + 1;

		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int newOriginY = originPosition.first + directionY[i];
			int newOriginX = originPosition.second + directionX[i];
			int newSideY = sidePosition.first + directionY[i];
			int newSideX = sidePosition.second + directionX[i];

			if (!checkPosition(newOriginY, newOriginX)) continue;
			if (!checkPosition(newSideY, newSideX)) continue;
			if (isVisited[newOriginY][newOriginX][top.dir]) continue;
			if (board[newOriginY][newOriginX] == 1 || board[newSideY][newSideX] == 1) continue;
			isVisited[newOriginY][newOriginX][top.dir] = true;
			queue.push({ newOriginY,newOriginX,top.dir,newTime });
		}

		// 90도 이동
		int originStartValue = (top.dir < 2) ? 2 : 0;
		int sideStartValue = (originStartValue < 2) ? 2 : 0;
		for (int i = 0; i < 2; i++)
		{
			if (top.dir < 2)
			{
				int newSideY = originPosition.first;
				int newSideX = originPosition.second + directionX[originStartValue + i];
				int newOriginY = sidePosition.first;
				int newOriginX = sidePosition.second + directionX[originStartValue + i];

				if (checkPosition(newSideY,newSideX) && board[newSideY][newSideX] == 0 && !isVisited[originPosition.first][originPosition.second][originStartValue + i])
				{
					int checkY = newSideY + directionY[top.dir];
					int checkX = newSideX;
					if (checkPosition(checkY,checkX) && board[checkY][checkX] == 0)
					{
						isVisited[originPosition.first][originPosition.second][originStartValue + i] = true;
						queue.push({ originPosition.first,originPosition.second,(direction)(originStartValue + i),newTime });
					}
				}
				if (checkPosition(newOriginY, newOriginX) && board[newOriginY][newOriginX] == 0)
				{
					int nextDir = ((top.dir+ 1) % 2 == 0) ? 0 : 1;
					int checkY = newOriginY + directionY[nextDir];
					int checkX = newOriginX;
					if (checkPosition(checkY, checkX) && board[checkY][checkX] == 0)
					{
						nextDir = ((originStartValue + i + 1) % 2 == 0) ? 2 : 3;
						if (!isVisited[newOriginY][newOriginX][nextDir])
						{
							isVisited[newOriginY][newOriginX][nextDir] = true;
							queue.push({ newOriginY,newOriginX,(direction)(nextDir),newTime });
						}
					}
				}
			}
			else
			{
				int newSideY = originPosition.first + directionY[originStartValue + i];
				int newSideX = originPosition.second;
				int newOriginY = sidePosition.first + directionY[originStartValue + i];
				int newOriginX = sidePosition.second;

				if (checkPosition(newSideY, newSideX) && board[newSideY][newSideX] == 0 && !isVisited[originPosition.first][originPosition.second][originStartValue + i])
				{
					int checkY = newSideY;
					int checkX = newSideX + directionX[top.dir];
					if (checkPosition(checkY, checkX) && board[checkY][checkX] == 0)
					{
						isVisited[originPosition.first][originPosition.second][originStartValue + i] = true;
						queue.push({ originPosition.first,originPosition.second,(direction)(originStartValue + i),newTime });
					}
				}

				if (checkPosition(newOriginY, newOriginX) && board[newOriginY][newOriginX] == 0)
				{
					int nextDir = ((top.dir + 1) % 2 == 0) ? 2 : 3;
					int checkY = newOriginY;
					int checkX = newOriginX + directionX[nextDir];
					if (checkPosition(checkY, checkX) && board[checkY][checkX] == 0)
					{
						nextDir = ((originStartValue + i + 1) % 2 == 0) ? 0 : 1;
						if (!isVisited[newOriginY][newOriginX][nextDir])
						{
							isVisited[newOriginY][newOriginX][nextDir] = true;
							queue.push({ newOriginY,newOriginX,(direction)(nextDir),newTime });
						}
					}
				}
			}
		}
	}
}

int main()
{
	//cout << solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0 } })<<endl;
	cout << solution({ {0, 0, 0, 0, 0, 0, 1},{1, 1, 1, 1, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 1, 0},{0, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 0, 1, 1},{0, 0, 1, 0, 0, 0, 0 } })<<endl;
	cout << solution({ {0, 0, 0, 0, 0, 0, 1},{1, 1, 1, 1, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 0, 0},{0, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 0, 1, 0},{0, 0, 1, 0, 0, 0, 0 } }) << endl;
	cout << solution({ {0, 0, 0, 0, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1, 0, 0},{1, 1, 1, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 1, 1, 0, 0},{0, 1, 1, 1, 1, 1, 1, 1, 1},{0, 0, 1, 1, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1, 1, 0} });

	return 0;
}
