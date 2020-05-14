#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool comp(int _lhs, int _rhs)
{
	return _lhs>_rhs;
}

// ��Ȯ�� �׽�Ʈ 76.2��, ȿ���� �׽�Ʈ 0��
/*
	sort_heap : 2nlogn
	make_heap: 3n
*/
/*
int solution(vector<int> scoville, int K) {
	int answer = 0;

	make_heap(scoville.begin(), scoville.end(),comp);
	int firstValue = 0, secondValue = 0;
	while (true)
	{
		sort_heap(scoville.begin(), scoville.end());

		if (scoville.size() == 1 && scoville.back() < K) 
		{
			answer = -1; 
			break;
		}
		if (scoville.back() > K) break;

		firstValue = scoville.back();
		scoville.pop_back();
		sort_heap(scoville.begin(), scoville.end());
		secondValue = scoville.back();
		scoville.pop_back();

		scoville.push_back(firstValue + (secondValue * 2));

		answer++;		
	}

	return answer;
}
*/

// ��Ȯ�� 76.2��, ȿ���� 23.8��
int solution(vector<int> scoville, int K) {
	int answer = 0;

	// �켱���� ť�� ������������ ����
	priority_queue<int,vector<int>,greater<int>> Queue(scoville.begin(), scoville.end());

	int firstValue = 0, secondValue = 0;
	while (true)
	{
		// ��� ������ K�� �̻����� ������ ���ϴ� ���
		// Sizeüũ�� ���� ������ core dump�߻� : ���µ� pop && ���ѷ���~
		if (Queue.size() == 1 && Queue.top() < K)
			return -1;
		if (Queue.top() > K) break;

		firstValue = Queue.top();
		Queue.pop();
		secondValue = Queue.top();
		Queue.pop();

		Queue.push(firstValue + (secondValue * 2));
		answer++;
	}

	return answer;
}

void main()
{
	cout << solution({ 1,2,3,9,10,12 }, 7);

}