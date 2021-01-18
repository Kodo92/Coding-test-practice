#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> supplyQ;
	int startIndex = 0;

	while (stock < k)
	{
		for (int i = startIndex; i < dates.size() && stock >= dates[i]; i++)
		{
			supplyQ.push(supplies[i]);
			startIndex = i + 1;
		}
		answer++;
		stock += supplyQ.top();
		supplyQ.pop();
	}
	return answer;
}

void main()
{
	//cout << solution(4, { 4,10,15 }, { 20,5,10 }, 30);	// return 2 : ok
	//cout << solution(2, { 1 }, { 10 }, 2);		// return 0 : ok
	cout << solution(4, { 4,5,6,7,8,9,10,11 }, { 1,3,5,7,10,13,15,20 }, 30);	// return 4 : ok
	cout << solution(4, { 1,2,3,4 }, { 10,40,30,20 }, 100);	// return 4 : ok
}

/*
stock += supplies[index] -> stock은 버틸 수 있는 일수가 된다.
최소한의 횟수로 공급을 받고 싶어하므로 stock일 전까지의 최대량을 받는다.
dates loop & if(dates[index] >= stock) 로 할 경우 '재고량 > 마지막 공급일'의 경우 발생
dates loop가 끝났으면 공급일자가 모두 지났음 -> 지난 공급일 자 중 최대치만 쏙쏙 골라먹으면 ㅇㅋ

테스트 케이스 3번 : stock과 dates[index]가 같은 경우 

*/
