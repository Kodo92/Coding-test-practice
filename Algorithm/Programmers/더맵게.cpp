#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool comp(int _lhs, int _rhs)
{
	return _lhs>_rhs;
}

// 정확도 테스트 76.2점, 효율성 테스트 0점
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

// 정확성 76.2점, 효율성 23.8점
int solution(vector<int> scoville, int K) {
	int answer = 0;

	// 우선순위 큐를 오름차순으로 정렬
	priority_queue<int,vector<int>,greater<int>> Queue(scoville.begin(), scoville.end());

	int firstValue = 0, secondValue = 0;
	while (true)
	{
		// 모든 음식을 K값 이상으로 만들지 못하는 경우
		// Size체크를 하지 않으면 core dump발생 : 없는데 pop && 무한루프~
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