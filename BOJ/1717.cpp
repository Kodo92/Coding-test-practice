/*
	[백준] 1717 집합의 표현
		문제 출처 : https://www.acmicpc.net/problem/1717
		분류 : Disjoint set

		1. 배열을 이용한 Disjoint set은 시간 초과
		2. 트리 + 경로 최적화 버전 (배열 구현) 
			- 시간 44ms, 메모리 9800KB
*/

#include <iostream>
#include <vector>

std::vector<int> groupIndex;

int Find(int x)
{
	if (groupIndex[x] == x)
		return x;
	return groupIndex[x] = Find(groupIndex[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return;

	// a집합에 b가 삽입된다.
	groupIndex[b] = a;
}

// 단순 배열 버전 - Union 시간 복잡도 : O(n), Find 시간 복잡도 : O(1)
/*


int Find(int x)
{
	return groupIndex[x];
}

void Link(int source, int dest)
{
	for (auto& i : groupIndex)
	{
		if (i == source)
			i = dest;
	}
}

void Union(int aIndex, int bIndex)
{
	int A = Find(aIndex);
	int B = Find(bIndex);

	if (A != B)
		Link(B, A);		// 집합 B를 A에 합친다.
}
*/
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	N += 1;
	groupIndex.resize(N);

	for (int i = 0; i < N; i++)
		groupIndex[i] = i;


	for (int i = 0; i < M; i++)
	{
		int type, a, b;
		std::cin >> type >> a >> b;
		if (type == 0) Union(a, b);
		else
		{
			if (Find(a) == Find(b))
				std::cout << "YES" << '\n';
			else
				std::cout << "NO" << '\n';
		}
	}
}