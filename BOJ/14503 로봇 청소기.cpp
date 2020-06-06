#include <iostream>
#include <vector>
#include <set>

// 0 : 북 -> 동 -> 남 -> 서 (%4)
int map[51][51];
typedef std::vector<std::vector<int>> vector;
typedef std::pair<int, int> pair;
typedef std::set<pair> set;

int n, m;

pair getPos(pair nowPos, int direction)
{
	switch (direction)
	{
	case 0:
		nowPos.second -= 1;
		break;
	case 1:
		nowPos.first -= 1;
		break;
	case 2:
		nowPos.second += 1;
		break;
	case 3:
		nowPos.first += 1;
		break;
	default:
		break;
	}

	return nowPos;
}

pair getBackPos(pair nowPos, int direction)
{
	switch (direction)
	{
	case 0:
		nowPos.first += 1;
		break;
	case 1:
		nowPos.second -= 1;
		break;
	case 2:
		nowPos.first -= 1;
		break;
	case 3:
		nowPos.second += 1;
		break;
	default:
		break;
	}
	return nowPos;
}

void cleanning(pair pos, int &count)
{
	count++;
	map[pos.first][pos.second] = count + 1;
}

void dfs(pair pos, int direction, int& count)
{
	// 현재 위치 청소
	cleanning(pos, count);

	// 왼쪽 공간 청소 유무 체크
	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			pair destPos = getPos(pos, direction);
			direction = (direction == 0) ? 3 : direction - 1;
			// 청소하지 않은 공간이면서 벽이 아닌 경우 체크
			if (map[destPos.first][destPos.second] == 0)
				return dfs(destPos, direction, count);
		}
		// 4방향 모두 청소가 되었거나 벽인 경우 -> 후진
		pos = getBackPos(pos, direction);
		if (map[pos.first][pos.second] == 1)
			return;
	}

}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;

	int r = 0, c = 0, d = 0;
	std::cin >> r >> c >> d;

//	vector map;
//	map.resize(n);
	for (int i = 0; i < n; i++)
	{
//		map[i].resize(m);
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j];
	}
	int count = 0;
	dfs(std::make_pair(r, c), d, count);
	std::cout << count;
	return 0;
}

/*
입력:
6 6
2 1 3
1 1 1 1 1 1
1 0 0 0 0 1
1 0 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 1 1 1 1 1
정답: 7

*/