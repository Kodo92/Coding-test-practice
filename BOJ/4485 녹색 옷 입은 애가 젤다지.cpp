#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int N;
std::pair<int,int> addPos[4]{ {-1,0},{1,0},{0,-1},{0,1} };
std::vector<int> answer;
class pos
{
public:
	int cost = 0;
	int y = 0, x = 0;

public:
	pos(int cost, int y, int x) : cost(cost), y(y), x(x) {}
};

struct cmp
{
	bool operator()(const pos& a, const pos& b) { return a.cost > b.cost; }
};

bool checkRange(int y, int x)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}

void bfs(const std::vector<std::vector<int>>&cave)
{
	std::vector<std::vector<std::pair<int, bool>>> isUsed(N, std::vector<std::pair<int, bool>>(N, { 2147483647,false}));
	std::priority_queue<pos,std::vector<pos>,cmp> Q;

	Q.push(pos(cave[0][0], 0, 0 ));
	isUsed[0][0].second = true;

	int min = 2147483647;
	while (!Q.empty())
	{
		auto top = Q.top();
		Q.pop();

		if (top.y == N - 1 && top.x == N - 1)
		{
			min = std::min(top.cost, min);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int newX = top.x + addPos[i].second;
			int newY = top.y + addPos[i].first;
			if (!checkRange(newY, newX)) continue;

			int newCost = top.cost + cave[newY][newX];
			if (!isUsed[newY][newX].second && isUsed[newY][newX].first > newCost)
			{
				Q.push({ top.cost + cave[newY][newX],newY,newX });
				isUsed[newY][newX].second = true;
				isUsed[newY][newX].first = newCost;
			}
		}

	}

	answer.push_back(min);
}
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	while (true)
	{
		std::cin >> N;
		if (N == 0)
			break;

		std::vector<std::vector<int>>cave (N, std::vector<int>(N));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				std::cin >> cave[i][j];
			
		bfs(cave);

	}

	for (int i = 0; i < answer.size(); i++)
		std::cout << "Problem " << (i + 1) << ": " << answer[i] << '\n';
	return 0;
}