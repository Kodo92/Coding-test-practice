#include<cstdio>

/*            U
0  1  2
3  4  5
6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
-----------
9  10 11
12 13 14
15 16 17
D
*/
enum FACE { U, D, F, B, L, R, SIZE };
char init[7] = "wyrogb";
char arr[55];
int cube[SIZE][3][3];
char temp[3][3];

int rot[6][12] = {
	{ 36,37,38,18,19,20,45,46,47,27,28,29 },        //U
	{ 33,34,35,51,52,53,24,25,26,42,43,44 },        //D
	{ 6,7,8,44,41,38,11,10,9,45,48,51 },            //F
	{ 2,1,0,53,50,47,15,16,17,36,39,42 },            //B
	{ 0,3,6,35,32,29,9,12,15,18,21,24 },            //L
	{ 8,5,2,26,23,20,17,14,11,27,30,33 }            //R
};

void rotate(FACE f, int cnt) {
	char que[12];

	while (cnt--) {
		for (int i = 0; i < 12; i++) {
			que[i] = arr[rot[f][i]];
		}
		for (int i = 0; i < 12; i++) {
			arr[rot[f][i]] = que[(i + 3) % 12];
		}
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
			temp[j][2 - i] = arr[cube[f][i][j]];
		}
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) arr[cube[f][i][j]] = temp[i][j];
	}
}

int conv[256];

int main() {
	conv['-'] = 3;
	conv['+'] = 1;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;

	//큐브 인덱스 부여하기
	for (int i = 0; i < SIZE; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) cube[i][j][k] = i * 9 + j * 3 + k;
	int n, m;
	char comm[3];

	scanf("%d\n", &n);

	while (n--) {
		//큐브 초기화
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				arr[i * 9 + j] = init[i];
			}
		}

		scanf("\n%d\n", &m);

		while (m--) {
			scanf("%s \n", comm);

			int f = conv[comm[0]], cnt = conv[comm[1]];
			rotate((FACE)f, cnt);
		}

		//출력
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", arr[cube[U][i][j]]);
			}
			printf("\n");
		}
	}

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>

char colors[]{ 'w','y','r','o','g','b' };
char pageChar[]{ 'U','D','F','B','L','R' };

int rotationCondition[][5][3]{ { { 2,1,0 },{ 4,1,0 },{ 3,1,0 },{ 5,1,0 },{ 2,1,0 } },				// U
{ { 2,1,2 },{ 5,1,2 },{ 3,1,2 },{ 4,1,2 },{ 2,1,2 } },				// D
{ { 0,1,2 },{ 5,-1,0 },{ 1,1,0 },{ 4,-1,2 },{ 0,1,2 } },			// F
{ { 0,1,0 },{ 4,-1,0 },{ 1,1,2 },{ 5,-1,2 },{ 0,1,0 } },			// B
{ { 0,-1,0 },{ 2,-1,0 },{ 1,-1,0 },{ 3,-1,2 },{ 0,-1,0 } },		// L
{ { 0,-1,2 },{ 3,-1,0 },{ 1,-1,2 },{ 2,-1,2 },{ 0,-1,2 } }, };	// R

/*
void print(std::vector<std::vector<std::vector<int>>>& cube)
{
	for (const auto i : cube[0])
	{
		for (const auto j : i)
			std::cout << colors[j];
		std::cout << '\n';
	}
}
*/

void print(std::vector<std::vector<std::vector<int>>>& cube)
{
	int count = 0;
	for (const auto i : cube)
	{
		std::cout << count << std::endl; count++;
		for (const auto j : i)
		{
			for (const auto k : j)
				std::cout << colors[k];
			std::cout << '\n';
		}
	}
}
bool checkReverse(int rotationIndex, int nowIndex, int nextIndex)
{
	int prev = rotationCondition[rotationIndex][nowIndex][0];
	int next = rotationCondition[rotationIndex][nextIndex][0];
	if (rotationIndex == 2)
	{
		if (prev == 4 && next == 0)
			return true;
		else if (prev == 0 && next == 4)
			return true;
		else if (prev == 1 && next == 5)
			return true;
		else if (prev == 5 && next == 1)
			return true;
	}
	else if (rotationIndex == 3)
	{
		if (prev == 1 && next == 5)
			return true;
		else if (prev == 5 && next == 1)
			return true;
	}
	else if (rotationIndex == 4)
	{
		if (prev == 3 && next == 0)
			return true;
		else if (prev == 0 && next == 3)
			return true;
		else if (prev == 1 && next == 3)
			return true;
		else if (prev == 3 && next == 1)
			return true;
	}
	else if (rotationIndex == 5)
	{
		if (prev == 3 && next == 1)
			return true;
		else if (prev == 1 && next == 3)
			return true;
		else if (prev == 0 && next == 3)
			return true;
		else if (prev == 3 && next == 0)
			return true;
	}
	return false;
}

void copyData(std::pair<int, int> conditionIndex, bool clockwise, std::vector<std::vector<std::vector<int>>>& cube, std::vector<int>& dest)
{
	// conditionIndex.first = 기준 면 / conditionIndex.second = rotationCondition[conditionIndex.first][conditionIndex.second] 
	int index = conditionIndex.first;
	int subIndex = conditionIndex.second;
	int* condition = rotationCondition[index][subIndex];
	int nowIndex = (clockwise) ? ((subIndex + 1) % 5) : (subIndex - 1);
	if (nowIndex < 0) nowIndex = 0;
	bool reverse = checkReverse(index, subIndex, nowIndex);
	if (condition[1] == 1)	// 가로
	{
		if (reverse)
		{
			for (int i = 0; i < 3; i++)
				dest[i] = cube[condition[0]][condition[2]][2 - i];
		}
		else
		{
			for (int i = 0; i < 3; i++)
				dest[i] = cube[condition[0]][condition[2]][i];
		}
	}
	else
	{
		if (reverse)
		{
			for (int i = 0; i < 3; i++)
				dest[i] = cube[condition[0]][2 - i][condition[2]];
		}
		else
		{
			for (int i = 0; i < 3; i++)
				dest[i] = cube[condition[0]][i][condition[2]];
		}
	}
}

void copyData(std::vector<int>& source, std::vector<int>& dest)
{
	for (int i = 0; i < 3; i++)
		dest[i] = source[i];
}

void setData(std::pair<int, int> conditionIndex, int prevIndex, std::vector<int>& source, std::vector<std::vector<std::vector<int>>>& dest)
{
	int index = conditionIndex.first;
	int subIndex = conditionIndex.second;
	int* condition = rotationCondition[index][subIndex];
	int* prevCondition = rotationCondition[index][prevIndex];
	if (condition[1] == 1)	// 가로
	{
		if (condition[1] == prevCondition[1])	// 가로 -> 가로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][condition[2]][i] = source[i];
		}
		else // 세로 -> 가로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][condition[2]][i] = source[i];
		}
	}
	else // 세로
	{
		if (condition[1] == prevCondition[1])	// 세로 -> 세로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][i][condition[2]] = source[i];
		}
		else // 가로 -> 세로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][i][condition[2]] = source[i];
		}
	}
}

void pageRotation(std::vector<std::vector<std::vector<int>>>& cube, int rotationIndex, bool clockWise)
{
	std::vector<std::vector<int>>temp(3, std::vector<int>(3));
	if (clockWise)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				temp[j][2 - i] = cube[rotationIndex][i][j];
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				temp[2 - j][i] = cube[rotationIndex][i][j];
		}
	}
	cube[rotationIndex].swap(temp);
}

void rotation(std::vector<std::vector<std::vector<int>>>& cube, int cubeIndex, bool clockwise)
{
	std::vector<int> prev(3), next(3);

	if (clockwise)	// 시계방향
	{
		copyData({ cubeIndex,0 }, clockwise, cube, prev);
		copyData({ cubeIndex,1 }, clockwise, cube, next);

		for (int i = 1; i < 5; i++)
		{
			setData({ cubeIndex,i }, i - 1, prev, cube);
			copyData(next, prev);
			if (i + 1 < 5)
				copyData({ cubeIndex,(i + 1) }, clockwise, cube, next);
		}
	}
	else
	{
		copyData({ cubeIndex,4 }, clockwise, cube, prev);
		copyData({ cubeIndex,3 }, clockwise, cube, next);

		for (int i = 3; i >= 0; i--)
		{
			setData({ cubeIndex,i }, i + 1, prev, cube);
			copyData(next, prev);
			if (i - 1 >= 0)
				copyData({ cubeIndex,(i - 1) }, clockwise, cube, next);
		}
	}
}

void proc(std::vector<std::string>& conditions)
{
	// cube initialize
	std::vector<std::vector<std::vector<int>>> cube(6, std::vector<std::vector<int>>(3, std::vector<int>(3)));
	for (int i = 0; i < 6; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
				cube[i][y][x] = i;
		}
	}

	for (const auto value : conditions)
	{
		int i = 0;
		for (; i < 6; i++)
		{
			if (pageChar[i] == value[0])
				break;
		}
		bool isClockwise = true;
		if (value[1] == '-')	 // 반시계
			isClockwise = false;

		rotation(cube, i, isClockwise);
		pageRotation(cube, i, isClockwise);
		std::cout << value << std::endl;
		print(cube);
		std::cout<<std::endl;
	}
	//print(cube);
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		std::cin >> M;
		std::vector<std::string> conditions;
		for (int j = 0; j < M; j++)
		{
			std::string str;
			std::cin >> str;
			conditions.push_back(str);
		}
		proc(conditions);
	}
}
*/