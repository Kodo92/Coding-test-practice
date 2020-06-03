/*
#include <iostream>
#include <algorithm>
#include <map>

std::map<int, std::map<int, int>> list;
int n, m;

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> m;

	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		if (list[a][b] < c)
			list[a][b] = c;
	}


	int start = 0, end = 0;
	std::cin >> start >> end;

	int first = list[start][end];
	int second = list[end][start];

	std::cout << std::max(first, second);
	return 0;
}
*/