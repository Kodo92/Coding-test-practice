/*
	[백준] 주사위 굴리기
		문제 출처 : https://www.acmicpc.net/problem/14499
*/

#include <iostream>
#include <vector>

// 주사위 초기 상 : 1 / 동 : 3 -> 1번 위치
int N, M, K;
std::pair<int, int> direction_offset[] { {0,1},{0,-1},{-1,0},{1,0} };
std::vector<int> dice_rot_index = { 2,0,1,3 };
std::vector<std::vector<int>> dice_rotation{ {3,5,4,2}, {3,1,4,6},{6,5,1,2},{2,1,5,6},{3,6,4,1},{3,2,4,5} };

class Dice {
private:
	std::pair<int, int> position_;
	int now_;
	std::vector<int> values_;

private:
	int	GetBottom(const int top);
public:
	Dice(const int x, const int y) { position_ = { x,y }; now_ = 1; values_.resize(6, 0); }
	bool	Move(const int direction);
	int		SetValue(std::vector<std::vector<int>>& map);
};

int Dice::GetBottom(const int top)
{
	switch (top)
	{
	case 1:
		return 5;
	case 2:
		return 4;
	case 3:
		return 3;
	case 4:
		return 2;
	case 5:
		return 1;
	case 6:
		return 0;
	default:
		return -1;
	}
}

bool Dice::Move(const int direction)
{
	int new_y = position_.first + direction_offset[direction].first;
	int new_x = position_.second + direction_offset[direction].second;

	if (new_y < 0 || new_y >= N || new_x < 0 || new_x >= M)
		return false;

	position_ = { new_y,new_x };
	now_ = dice_rotation[now_-1][dice_rot_index[direction]];

	return true;
}

int Dice::SetValue(std::vector<std::vector<int>>& map)
{
	if (map[position_.first][position_.second] == 0)
		map[position_.first][position_.second] = values_[GetBottom(now_)];
	else
	{
		values_[GetBottom(now_)] = map[position_.first][position_.second];
		map[position_.first][position_.second] = 0;
	}
	return values_[now_-1];
}

int main()
{
	int x, y;
	std::cin >> N >> M >> x >> y >> K;

	std::vector<std::vector<int>> map(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			std::cin >> map[i][j];
	}

	Dice dice(x, y);
	for (int i = 0; i < K; i++)
	{
		int number;
		std::cin >> number;
		if (dice.Move(number-1))
			std::cout << dice.SetValue(map) << std::endl;
	}
	
	return 0;
}