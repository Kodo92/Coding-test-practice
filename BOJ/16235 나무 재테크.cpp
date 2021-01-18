#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

struct treeData
{
	int age;
	int x;
	int y;
};

auto cmp = [](treeData& a, treeData& b) -> bool {return a.age < b.age; };

typedef std::deque<treeData> treeVec;		// vector보다 deque가 메모리 초기 메모리 사용량은 높지만 데이터의 추가,삭제가 vector보다 빠르다.

int yPos[8] = { -1,-1,-1,0,0,1,1,1 };
int xPos[8] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K;

void mealTime(std::vector<std::vector<int>>& meals, treeVec& trees)
{
	std::deque<treeData> liveTrees, deadTrees;

	// 나무 양분 먹기
	for (auto& tree : trees)
	{
		if (meals[tree.y][tree.x] >= tree.age)
		{
			meals[tree.y][tree.x] -= tree.age;
			tree.age += 1;
			liveTrees.push_back(tree);	// 나이 많은 나무가 뒤로 온다.
		}
		else
			deadTrees.push_back(tree);
	}

	trees.swap(liveTrees);

	// 죽은 나무 나이만큼 양분 추가
	for (const auto tree : deadTrees)
		meals[tree.y][tree.x] += (tree.age / 2);
}

void breeding(treeVec& trees)
{
	treeVec temp(trees);
	int endIndex = trees.size();
	for (int i = 0; i<endIndex; i++)
	{
		if (trees[i].age % 5 != 0)
			continue;

		for (int j = 0; j < 8; j++)
		{
			int newX = trees[i].x + xPos[j];
			int newY = trees[i].y + yPos[j];
			if (newX >= 0 && newX < N && newY >= 0 && newY < N)
				temp.push_front({ 1,newX,newY });	// push_front 해주므로써 정렬을 안해도 앞에는 어린 나무들이 온다.
		}
	}

	trees.swap(temp);
}

void addMeal(const std::vector<std::vector<int>>& addValue, std::vector<std::vector<int>>& foods)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			foods[i][j] += addValue[i][j];
	}
}

int main()
{
	std::cin >> N >> M >> K;
	std::vector<std::vector<int>>meals(N, std::vector<int>(N, 5));	// 현재 나무의 양분
	std::vector<std::vector<int>>addData(N, std::vector<int>(N));	// A배열

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> addData[i][j];
	}

	treeVec trees;
	for (int i = 0; i < M; i++)
	{
		treeData data;
		std::cin >> data.y >> data.x >> data.age;		//  주의하자. x,y는 변수명이지 x좌표, y좌표가 아니다.
		data.x -= 1;
		data.y -= 1;
		trees.push_back(data);
	}

	for (int years = 0; years < K; years++)
	{
		mealTime(meals, trees);
		breeding(trees);
		addMeal(addData, meals);
	}

	std::cout << trees.size();
	return 0;
}

/*
5 2 7
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

answer : 71
*/

// 더러운 시간초과. vector을 사용할 경우 sort가 문제가 된다. -> deque활용
// priority_queue를 쓴다면?