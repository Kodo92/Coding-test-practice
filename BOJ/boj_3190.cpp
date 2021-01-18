/*
	[백준] 뱀
		문제 출처 : https://www.acmicpc.net/problem/3190
		구분 : 삼성 SW 대비
*/

#include <iostream>
#include <vector>
#include <queue>

enum Direction { NONE = -1,UP,DOWN,LEFT,RIGHT };
const std::vector<std::pair<int, int>> kDirectionPosition{ {-1,0},{1,0},{0,-1},{0,1} };

int N, K, L;

struct Snake_position {
	std::queue<std::pair<int, int>> body_position;
	Direction dir = RIGHT;
};

Direction GetDirection(Direction now_direction, char next_dir)
{
	switch (now_direction)
	{
	case UP:
		if (next_dir == 'L')
			return Direction::LEFT;
		else
			return Direction::RIGHT;
		break;
	case DOWN:
		if (next_dir == 'L')
			return Direction::RIGHT;
		else
			return Direction::LEFT;
		break;
	case LEFT:
		if (next_dir == 'L')
			return Direction::DOWN;
		else
			return Direction::UP;
		break;
	case RIGHT:
		if (next_dir == 'L')
			return Direction::UP;
		else
			return Direction::DOWN;
		break;
	default:
		return NONE;
		break;
	}
}

bool IsMove(std::vector<std::vector<int>>& map, Snake_position& snake)
{
	std::pair<int, int> head_position = snake.body_position.back();
	std::pair<int, int> tail_position = snake.body_position.front();
	std::pair<int, int> next_position = { head_position.first + kDirectionPosition[snake.dir].first, head_position.second + kDirectionPosition[snake.dir].second };
	if (next_position.first < 0 || next_position.first >= N || next_position.second < 0 || next_position.second >= N)
		return false;

	snake.body_position.push(next_position);

	if (map[next_position.first][next_position.second] == 1)
		return false;

	if (map[next_position.first][next_position.second] == 0)
	{
		map[tail_position.first][tail_position.second] = 0;
		snake.body_position.pop();
	}
	map[next_position.first][next_position.second] = 1;
	return true;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N >> K;
	std::vector<std::vector<int>> map(N,std::vector<int>(N,0));


	for (int i = 0; i < K; i++)
	{
		int y, x;
		std::cin >> y >> x;
		map[y-1][x-1] = 2;
	}

	std::cin >> L;
	std::vector<std::pair<int, char>> move_direction(L);
	for (int i = 0; i < L; i++)
		std::cin >> move_direction[i].first >> move_direction[i].second;

	Snake_position snake;
	snake.body_position.push({ 0,0 });
	map[0][0] = 1;

	int time = 0;
	int move_index = 0;
	while (true)
	{
		time++;
		// Move
		if (!IsMove(map, snake))
			break;
		// Turn
		if (move_index < move_direction.size() && move_direction[move_index].first == time)
		{
			snake.dir = GetDirection(snake.dir, move_direction[move_index].second);
			move_index++;
		}
	}

	std::cout << time;
	return 0;
}

/*
1. 7% 이후 런타임에러
	- queue size == 0? -> x
	- line 90 map[y-1][x-1] ?
	- isMove 내부 out of range
	- Direction?

	=> IsMove 마지막 return true 안했...
*/