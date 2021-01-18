/*
	[백준] 로봇 청소기
		문제 출처 : https://www.acmicpc.net/problem/4991
		키워드 : DFS + BFS
		포인트 : 청소가 안되는 경우의 수 존재 체크
		참고  : https://icpc.iisf.or.jp/past-icpc/domestic2005/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dy[]{ -1,0,1,0 };
int dx[]{ 0,1,0,-1 };

int w, h;
const int INF = 2147483647;
std::vector<std::vector<char>> *map;

struct Node
{
	int cost;
	std::pair<int, int> position;
};

int BFS(const std::pair<int, int> start_position, const std::pair<int, int> dest_position)
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
	return 0;
}

void GetDistance(const std::vector<std::pair<int, int>>& nodes, std::vector<std::vector<int>>& distances)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			if (i == j)
				continue;
			if (distances[i][j] != 0)
				continue;
			distances[i][j] = BFS(nodes[i], nodes[j]);
			distances[j][i] = distances[i][j];
		}
	}
}

void Init(std::vector<std::pair<int, int>>& nodes)
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
				nodes[0] = { i,j };
			if (str[j] == '*')
				nodes.push_back({ i,j } );
		}
	}
}

bool Slove()
{
	std::cin >> w >> h;

	if (w == 0 && h == 0)
		return false;

	map = new std::vector<std::vector<char>>(h, std::vector<char>(w, '.'));
	std::vector<std::pair<int, int>> nodes(1);

	Init(nodes);

	std::vector<std::vector<int>> distances(nodes.size(), std::vector<int>(nodes.size(),0));
	GetDistance(nodes, distances);

	std::vector<int> permutations(nodes.size()-1);
	for (int i = 0; i < permutations.size(); i++)
		permutations[i] = i+1;

	int answer = INF;
	do
	{
		bool is_false = false;
		int sum = distances[0][permutations[0]];
		if (sum == 0)
			break;
		for (int i = 0; i < permutations.size() - 1; i++)
		{
			int temp = distances[permutations[i]][permutations[i + 1]];
			if (temp == 0)
			{
				is_false = true;
				break;
			}
			sum += temp;
		}
		if (is_false)
		{
			answer = INF;
			break;
		}
		answer = (answer > sum) ? sum : answer;
	} while (std::next_permutation(permutations.begin(), permutations.end()));

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