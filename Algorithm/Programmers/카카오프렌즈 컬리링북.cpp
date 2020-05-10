#include <iostream>
#include <vector>

using namespace std;

int height, weight;
vector<vector<int>> pic;

void dfs(pair<int, int> pos, int color, int& count)
{
	if (pos.first < 0 || pos.first >= height) return;
	if (pos.second < 0 || pos.second >= weight) return;
	if (pic[pos.first][pos.second] != color) return;

	count++;
	pic[pos.first][pos.second] = 0;

	dfs({ pos.first + 1,pos.second }, color, count);
	dfs({ pos.first - 1,pos.second }, color, count);
	dfs({ pos.first,pos.second + 1 }, color, count);
	dfs({ pos.first,pos.second - 1 }, color, count);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	const int INF = 1e9;
	height = m;
	weight = n;
	pic = picture;

	int color = 0, count = 0, maxCount = 0;
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<weight; j++)
		{
			if (pic[i][j] != 0)
			{
				color = pic[i][j];
				number_of_area++;
				dfs({ i,j }, color, count);
				if (max_size_of_one_area < count)
					max_size_of_one_area = count;
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

void main()
{
	solution(6,4,{ {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3}});
}