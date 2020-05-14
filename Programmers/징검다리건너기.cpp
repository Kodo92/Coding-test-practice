#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int count = 0, retVal = 0, popPos=0;

	multiset<int> queue;


	for (count; count < k; count++)
		queue.insert(stones[count]);
	
	answer = *(queue.rbegin());

	for (count; count < stones.size(); count++, popPos++)
	{
		queue.erase(queue.find(stones[popPos]));
		queue.insert(stones[count]);
		retVal =*(queue.rbegin());
		answer = (answer > retVal) ? retVal : answer;
	}
	
	return answer;
}

int main()
{
//	cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << endl;
//	cout << solution({ 5,2,1,2,2 }, 4) << endl;
//	cout << solution({ 100 }, 1) << endl;
	cout << solution({ 2,2,2 }, 2) << endl;

	return 1;
}