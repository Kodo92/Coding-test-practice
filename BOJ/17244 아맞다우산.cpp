/*
	[백준]	17244 아맞다우산
	문제 출처 : https://www.acmicpc.net/problem/17244

	[풀이 방법]
		1. N개의 물품 좌표를 우선순위를 정한다.
		2. 우선순위 순서대로 현재 좌표에서 물품 좌표까지 bfs로 이동한다.
		3. 이동 횟수의 누적합을 구한 다음 최솟값을 answer로 한다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

class position {
public:
	int y = 0;
	int x = 0;
public:
	position() {}
	position(int y, int x) : y(y), x(x) {}
	bool operator== (const position& other) const
	{
		if (y == other.y && x == other.x)
			return true;
		else return false;
	}
};

class cmp {
public:
	bool operator()(const std::pair<int, position>& left, const std::pair<int, position>& right)
	{
		return left.first > right.first;
	}
};

std::vector<position> pos;
std::pair<int, int> direction[]{ { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int W, H;

bool checkPosition(const position& pos)
{
	if (pos.y < 0 || pos.y >= H|| pos.x < 0 || pos.x >= W)
		return false;
	return true;
}

int BFS(const std::vector<std::vector<char>>& board, const position start, const position dest)
{
	std::vector<std::vector<bool>> isUsed (H,std::vector<bool>(W,false));
	std::priority_queue < std::pair<int, position>, std::vector<std::pair<int, position>>, cmp> queue;
	queue.push({ 0,start});
	isUsed[start.y][start.x] = true;

	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();

		int nowCost = top.first;
		position nowPos = top.second;

		if (nowPos == dest)
			return nowCost;

		for (int i = 0; i < 4; i++)
		{
			position newPos{ nowPos.y + direction[i].first, nowPos.x + direction[i].second };
			if (!checkPosition(newPos) || isUsed[newPos.y][newPos.x])	continue;
			if (board[newPos.y][newPos.x] != '.') continue;
			queue.push({ nowCost + 1,newPos });
			isUsed[newPos.y][newPos.x] = true;
		}
	}
}

int Move(const std::vector<std::vector<char>>& board, const position start, const position dest)
{
	std::vector<int> positionIndex;
	for (int i = 0; i < pos.size(); i++)
		positionIndex.push_back(i);
	int answer = 2147483647;
	do
	{
		std::vector<position> newPos(pos.size());
		for (int i = 0; i < positionIndex.size(); i++)
			newPos[positionIndex[i]] = pos[i];
		
		int cost = 0;
		position tempStart = start;
		for (int i = 0; i < positionIndex.size(); i++)
		{
			cost += BFS(board, tempStart, newPos[i]);
			tempStart = newPos[i];
		}
		cost += BFS(board, tempStart, dest);
		answer = std::min(cost, answer);

	} while (std::next_permutation(positionIndex.begin(), positionIndex.end()));
	return answer;
}

int main()
{
	std::cin >> W >> H;

	std::vector<std::vector<char>> board (H,std::vector<char>(W));
	position start, end;
	for (int i = 0; i < H; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < W; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'X')
			{
				pos.push_back(position(i, j));
				board[i][j] = '.';
			}
			else if (str[j] == 'S')
			{
				start = { i,j };
				board[i][j] = '.';
			}
			else if (str[j] == 'E')
			{
				end = { i,j };
				board[i][j] = '.';
			}
		}
	}

	std::cout <<Move(board, start, end);
}