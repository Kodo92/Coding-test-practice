/*
	[����] 1717 ������ ǥ��
		���� ��ó : https://www.acmicpc.net/problem/1717
		�з� : Disjoint set

		1. �迭�� �̿��� Disjoint set�� �ð� �ʰ�
		2. Ʈ�� + ��� ����ȭ ���� (�迭 ����) 
			- �ð� 44ms, �޸� 9800KB
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

	// a���տ� b�� ���Եȴ�.
	groupIndex[b] = a;
}

// �ܼ� �迭 ���� - Union �ð� ���⵵ : O(n), Find �ð� ���⵵ : O(1)
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
		Link(B, A);		// ���� B�� A�� ��ģ��.
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