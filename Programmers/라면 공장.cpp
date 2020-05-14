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
stock += supplies[index] -> stock�� ��ƿ �� �ִ� �ϼ��� �ȴ�.
�ּ����� Ƚ���� ������ �ް� �;��ϹǷ� stock�� �������� �ִ뷮�� �޴´�.
dates loop & if(dates[index] >= stock) �� �� ��� '��� > ������ ������'�� ��� �߻�
dates loop�� �������� �������ڰ� ��� ������ -> ���� ������ �� �� �ִ�ġ�� ��� �������� ����

�׽�Ʈ ���̽� 3�� : stock�� dates[index]�� ���� ��� 

*/
