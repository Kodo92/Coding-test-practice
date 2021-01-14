/*
	[백준] 마법사 상어와 파이어볼
		문제 출처 : https://www.acmicpc.net/problem/20056
		키워드 : 구현
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>

int N, M, K;

int dr[] { -1,-1,0,1,1,1,0,-1 };
int dc[] { 0,1,1,1,0,-1,-1,-1 };

struct Fireball
{
	int mass_;
	int speed_;
	int direction_;
	int r;
	int c;
};

std::queue<Fireball*> queue;
std::vector<std::vector < std::list<Fireball*>>> *map;

std::pair<int, int> GetNextPosition(const int r, const int c, const int direction, const int speed)
{
	int new_r = (r + (dr[direction] * speed))%N;
	int new_c = (c + (dc[direction] * speed)) %N;

	if (new_r < 0)
		new_r += N;
	if (new_c < 0)
		new_c += N;

	return { new_r,new_c };
}

void Init()
{
	for (int i = 0; i < M; i++)
	{
		int r, c, m, d, s;
		std::cin >> r >> c >> m >> s >> d;
		auto new_node = new Fireball({ m, s, d, r-1, c-1 });
		queue.push(new_node);
	}
}

void Move()
{
	while (!queue.empty())
	{
		auto top = queue.front();
		queue.pop();
		auto next_dir = GetNextPosition(top->r, top->c, top->direction_, top->speed_);
		top->r = next_dir.first;
		top->c = next_dir.second;
		(*map)[next_dir.first][next_dir.second].push_back(top);
	}
}

void Merge()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			auto& this_node = (*map)[i][j];

			if (this_node.empty())
				continue;

			if (this_node.size() < 2)
			{
				for (auto& k : this_node)
					queue.push(k);
			}
			else
			{
				bool is_odd = this_node.front()->direction_ % 2;
				bool second_direction = false;
				int mass = 0, speed = 0;
				const int count = this_node.size();
				while (!this_node.empty())
				{
					auto& top = *(this_node.begin());
					if (top->direction_ % 2 != is_odd)
						second_direction = true;

					mass += top->mass_;
					speed += top->speed_;

					this_node.erase(this_node.begin());
					delete top;
				}

				int start_direction = (int)second_direction;
				int new_mass = mass / 5;
				int new_speed = speed / count;
				if (mass / 5 != 0)
				{
					for (int k = 0; k < 4; k++)
						queue.push(new Fireball({ new_mass,new_speed,start_direction + (k * 2),i,j }));
				}
			}
			this_node.clear();
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N >> M >> K;
	
	map = new std::vector<std::vector < std::list<Fireball*>>>(N, std::vector<std::list<Fireball*>>(N, std::list<Fireball*>()));

	 Init();
	 for (int i = 0; i < K; i++)
	 {
		 Move();
		 Merge();
	 }

	 int answer = 0;
	 while (!queue.empty())
	 {
		 answer += queue.front()->mass_;
		 queue.pop();
	 }

	 std::cout << answer;
	return 0;
}