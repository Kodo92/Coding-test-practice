/*
	[백준] 로봇 청소기
		문제 출처 : https://www.acmicpc.net/problem/4991
		키워드 : DFS + BFS
*/

#include <iostream>
#include <vector>
#include <queue>

int dy[]{ -1,0,1,0 };
int dx[]{ 0,1,0,-1 };

int w, h;
const int INF = 2147483647;
int answer = INF;
std::vector<std::vector<char>> *map;

struct Node
{
	int cost;
	std::pair<int, int> position;
};

int GetBFS(const std::pair<int, int> start_position, const std::pair<int, int> dest_position)
{
	auto cmp = [](const Node& left, const Node& right) { return left.cost > right.cost; };
	std::priority_queue<Node, std::vector<Node>, decltype(cmp)> queue(cmp);
	std::vector<std::vector<bool>> is_visited(h, std::vector<bool>(w, false));

	queue.push({ 0,{start_position} });
	is_visited[start_position.first][start_position.second] = true;
	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();
		int now_y = top.position.first;
		int now_x = top.position.second;
		if (now_y == dest_position.first && now_x == dest_position.second)
			return top.cost;

		for (int i = 0; i < 4; i++)
		{
			int new_y = now_y + dy[i];
			int new_x = now_x + dx[i];
			if (new_y < 0 || new_y >= h || new_x < 0 || new_x >= w)
				continue;
			if ((*map)[new_y][new_x] == 'x' || is_visited[new_y][new_x])
				continue;
			is_visited[new_y][new_x] = true;
			queue.push({ top.cost + 1,{new_y,new_x} });
		}
	}
	return -1;
}

void Init(std::vector<Node>& nodes, std::pair<int,int>& start_position, int& dirty_count)
{
	for (int i = 0; i < h; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < w; j++)
		{
			if (str[j] == '.')
				continue;
			(*map)[i][j] = str[j];
			if (str[j] == 'o')
				start_position = { i,j };
			if (str[j] == '*')
			{
				dirty_count++;
				(*map)[i][j] = '*';
				nodes.push_back({ 0, { i,j } });
			}
		}
	}
}

void DFS(const std::vector<Node>& nodes, const std::pair<int, int> start_position, const std::pair<int, int> dest_position, std::vector<bool> is_visited, const int cost, const int count)
{
	if (answer < cost)
		return;
	
	int distance = GetBFS(start_position, dest_position);

	if (count+1 == nodes.size())
	{
		answer = (answer > cost+distance) ? cost+distance : answer;
		return;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (is_visited[i])
			continue;
		is_visited[i] = true;
		DFS(nodes, dest_position, nodes[i].position, is_visited, cost + distance,count+1);
		is_visited[i] = false;
	}
}

bool Slove()
{
	std::cin >> w >> h;

	if (w == 0 && h == 0)
		return false;

	map = new std::vector<std::vector<char>>(h, std::vector<char>(w, '.'));
	std::vector<Node> nodes;
	int dirty_count = 0;
	std::pair<int, int> start_position;
	Init(nodes, start_position, dirty_count);

	std::vector<bool> is_visited(nodes.size(), false);

	for (int i = 0; i < nodes.size(); i++)
	{
		is_visited[i] = true;
		DFS(nodes, start_position, nodes[i].position, is_visited, 0,0);
		is_visited[i] = false;
	}
	if (answer == INF)
		answer = -1;
	std::cout << answer << '\n';
	answer = INF;
	delete map;
	return true;
}
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	while (true)
	{
		if (!Slove())
			break;
	}

	return 0;
}