/*
	[백준] 13460. 구슬 탈출2
	문제 출처 : https://www.acmicpc.net/problem/13460

	[풀이 방법] - 브루드 포스 & DFS
		1. 4방향으로 이동할 수 있는 부분 이동
			- 이동하지 않을 경우 체크
*/

#include <iostream>
#include <string>
#include <vector>

enum direction {UP=0,DOWN,LEFT,RIGHT};
enum checkResult {NOT = 0, OK, FAIL};		// NOT : 도착 안함, FAIL : 실패조건 달성

int answer = 11;
int N, M;

struct position {
	std::pair<int, int> goalPosition;
	std::pair<int, int> redPosition;
	std::pair<int, int> BluePosition;
};

void moveUP(std::vector<std::vector<char>>& board, std::pair<int,int>& nowPos, const std::pair<int,int>& goal)
{
	int newY = nowPos.first;
	int x = nowPos.second;
	while (newY-1 > 0 && board[newY-1][x] == '.') 	{			newY--;		}
	if (newY == nowPos.first)
		return;
	board[newY][x] = board[nowPos.first][x];
	board[nowPos.first][x] = '.';
	nowPos.first = newY;
}

void moveDOWN(std::vector<std::vector<char>>& board, std::pair<int, int>& nowPos, const std::pair<int, int>& goal)
{
	int newY = nowPos.first;
	int x = nowPos.second;
	while (newY+1 < N-1 && board[newY+1][x] == '.') {	newY++;	};
	if (newY == nowPos.first)
		return;
	board[newY][x] = board[nowPos.first][x];
	board[nowPos.first][x] = '.';
	nowPos.first = newY;
}

void moveLEFT(std::vector<std::vector<char>>& board, std::pair<int, int>& nowPos, const std::pair<int, int>& goal)
{
	int newX = nowPos.second;
	int y = nowPos.first;
	while (newX-1 > 0 && board[y][newX-1] == '.') { newX--; };
	if (newX == nowPos.second)
		return;
	board[y][newX] = board[y][nowPos.second];
	board[y][nowPos.second] = '.';
	nowPos.second = newX;
}

void moveRIGHT(std::vector<std::vector<char>>& board, std::pair<int, int>& nowPos, const std::pair<int, int>& goal)
{
	int newX = nowPos.second;
	int y = nowPos.first;
	while (newX+1 < M-1 && board[y][newX+1] == '.') { newX++; };
	if (newX == nowPos.second)
		return;
	board[y][newX] = board[y][nowPos.second];
	board[y][nowPos.second] = '.';
	nowPos.second = newX;
}

checkResult moveBoard(int dir, std::vector<std::vector<char>>& board, position& pos)
{
	checkResult ret = checkResult::NOT;
	switch ((direction)dir)
	{
	case direction::UP:
	{
		if (pos.BluePosition.first > pos.redPosition.first)	// blue [y] > red[y] -> red먼저
		{
			moveUP(board, pos.redPosition, pos.goalPosition);
			moveUP(board, pos.BluePosition, pos.goalPosition);
		}
		else
		{
			moveUP(board, pos.BluePosition, pos.goalPosition);
			moveUP(board, pos.redPosition, pos.goalPosition);
		}

		// 완료 조건
		if (pos.goalPosition.first - pos.redPosition.first == -1 && pos.goalPosition.second == pos.redPosition.second)
		{
			if (pos.redPosition.first - pos.BluePosition.first == -1 && pos.redPosition.second == pos.BluePosition.second)
				ret = checkResult::FAIL;
			else
				ret = checkResult::OK;
		}
		else if (pos.goalPosition.first - pos.BluePosition.first == -1 && pos.goalPosition.second == pos.BluePosition.second)
			ret = checkResult::FAIL;
		break;
	}
	case direction::DOWN:
	{
		if (pos.BluePosition.first < pos.redPosition.first)
		{
			moveDOWN(board, pos.redPosition, pos.goalPosition);
			moveDOWN(board, pos.BluePosition, pos.goalPosition);
		}
		else
		{
			moveDOWN(board, pos.BluePosition, pos.goalPosition);
			moveDOWN(board, pos.redPosition, pos.goalPosition);
		}

		// 완료 조건
		if (pos.goalPosition.first - pos.redPosition.first == 1 && pos.goalPosition.second == pos.redPosition.second)
		{
			if (pos.redPosition.first - pos.BluePosition.first == 1 && pos.redPosition.second == pos.BluePosition.second)
				ret = checkResult::FAIL;
			else
				ret = checkResult::OK;
		}
		else if (pos.goalPosition.first - pos.BluePosition.first == 1 && pos.goalPosition.second == pos.BluePosition.second)
			ret = checkResult::FAIL;
		break;
	}
	case direction::LEFT:
	{
		if (pos.BluePosition.second > pos.redPosition.second)	
		{
			moveLEFT(board, pos.redPosition, pos.goalPosition);
			moveLEFT(board, pos.BluePosition, pos.goalPosition);
		}
		else
		{
			moveLEFT(board, pos.BluePosition, pos.goalPosition);
			moveLEFT(board, pos.redPosition, pos.goalPosition);
		}

		// 완료 조건
		if (pos.goalPosition.second - pos.redPosition.second == -1 && pos.goalPosition.first == pos.redPosition.first)
		{
			if (pos.redPosition.second - pos.BluePosition.second == -1 && pos.redPosition.first == pos.BluePosition.first)
				ret = checkResult::FAIL;
			else
				ret = checkResult::OK;
		}
		else if (pos.goalPosition.second - pos.BluePosition.second == -1 && pos.goalPosition.first == pos.BluePosition.first)
			ret = checkResult::FAIL;
		break;
	}
	case direction::RIGHT:
	{
		if (pos.BluePosition.second < pos.redPosition.second)
		{
			moveRIGHT(board, pos.redPosition, pos.goalPosition);
			moveRIGHT(board, pos.BluePosition, pos.goalPosition);
		}
		else
		{
			moveRIGHT(board, pos.BluePosition, pos.goalPosition);
			moveRIGHT(board, pos.redPosition, pos.goalPosition);
		}

		// 완료 조건
		if (pos.goalPosition.second - pos.redPosition.second == 1 && pos.goalPosition.first == pos.redPosition.first)
		{
			if (pos.redPosition.second - pos.BluePosition.second == 1 && pos.redPosition.first == pos.BluePosition.first)
				ret = checkResult::FAIL;
			else
				ret = checkResult::OK;
		}
		else if (pos.goalPosition.second - pos.BluePosition.second == 1 && pos.goalPosition.first == pos.BluePosition.first)
			ret = checkResult::FAIL;
		break;
	}
	default:
		break;
	}
	return ret;
}

void dfs(std::vector<std::vector<char>> board, int dir, int count, position pos)
{
	if (count >= answer)
		return;
	if (count > 10)
		return;

	checkResult retval = moveBoard(dir, board,pos);
	if (retval == checkResult::OK)
	{
		answer = count;
		return;
	}
	else if (retval == checkResult::FAIL)
		return;

	for (int i = 0; i < 4; i++)
		dfs(board, i, count + 1,pos);
}

int main()
{
	std::cin >> N >> M;
	
	std::vector<std::vector<char>> board(N, std::vector<char>(M));
	position pos;
	for (int i = 0; i < N; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'O')
				pos.goalPosition = { i,j };
			else if(str[j] == 'R')
				pos.redPosition = { i,j };
			else if(str[j] == 'B')
				pos.BluePosition = { i,j };
		}
	}

	for(int i=0;i<4;i++)
		dfs(board, i,1, pos);

	if (answer == 11)
		answer = -1;
	std::cout << answer;
}