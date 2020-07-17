/*
	[백준] 16236  아기상어
		문제 출처 : https://www.acmicpc.net/problem/16236


*/

#include <iostream>
#include <deque>
#include <queue>

class position {
public:
	int y = 0;
	int x = 0;
public:
	void addPos(int y, int x) { this->y += y; this->x += x;}
	position() {}
	position(int y, int x) : y(y), x(x) {}
};

position sharkPos;
int N;
int answer, nowSize, eatCount;
std::pair<int, int> dir[]{ {-1,0},{1,0},{0,-1},{0,1} };

void debug(const std::deque<std::deque<int>>& space)
{
	for (const auto& i : space) {
		for (const auto& j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}
	std::cout << "Answer : " << answer << ", Size : " << nowSize << ", Count : " << eatCount << "\n\n";
}


struct cmp {
	bool operator() (const std::pair<int, position>& a, const std::pair<int, position>& b) {
		if (a.first == b.first)
		{
			if (a.second.y == b.second.y)
				return a.second.x > b.second.x;
			return a.second.y > b.second.y;
		}
		return a.first > b.first;
	}
};

bool isMove(const position& pos)
{
	if (pos.y >= 0 && pos.y < N && pos.x >= 0 && pos.x < N)
		return true;
	return false;
}

int getDistance(const std::deque<std::deque<int>>& space, const position& destPos)
{
	std::deque<std::deque<bool>> isUsed(N, std::deque<bool>(N, false));
	std::priority_queue<std::pair<int, position>, std::vector<std::pair<int, position>>, cmp> q;
	q.push({ 0,sharkPos });
	isUsed[sharkPos.y][sharkPos.x] = true;

	while (!q.empty())
	{
		auto top = q.top();
		q.pop();

		if (top.second.y == destPos.y && top.second.x == destPos.x)
			return top.first;

		int newCost = top.first + 1;
		for (int i = 0; i < 4; i++)
		{
			position newPos = top.second;
			newPos.addPos(dir[i].first, dir[i].second);
			if (isMove(newPos) && !isUsed[newPos.y][newPos.x] && space[newPos.y][newPos.x] <= nowSize)
			{
				q.push({ newCost, newPos });
				isUsed[newPos.y][newPos.x] = true;
			}

		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::deque<std::deque<position>> fishPosition(7, std::deque<position>());
	std::deque<std::deque<int>> space(N, std::deque<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> space[i][j];
			if (space[i][j] != 0)
			{
				if (space[i][j] == 9)
					sharkPos = { i,j };
				else
					fishPosition[space[i][j]].push_back({ i,j });
			}
		}
	}

	answer = 0, nowSize = 2, eatCount = 0;

	while (true)
	{
		std::priority_queue<std::pair<int, position>, std::vector<std::pair<int, position>>, cmp> q;
		for (int i = 1; i < nowSize && i < fishPosition.size(); i++)
		{
			for (auto& pos : fishPosition[i])
				q.push({ getDistance(space,pos),pos });
		}

		if (q.empty())
			break;

		auto eat = q.top();
		answer += eat.first;

		std::deque<position>& deletePos = fishPosition[space[eat.second.y][eat.second.x]];
		for (auto val = deletePos.begin(); val != deletePos.end(); val++)
		{
			if (val->y == eat.second.y && val->x == eat.second.x)
			{
				fishPosition[space[eat.second.y][eat.second.x]].erase(val);
				break;
			}
		}
		space[sharkPos.y][sharkPos.x] = 0;
		sharkPos = eat.second;
		space[sharkPos.y][sharkPos.x] = 9;
		eatCount++;
		if (eatCount == nowSize)
		{
			eatCount = 0;
			nowSize++;
		}
	}
	std::cout << answer;
	return 0;
}
