#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, nowWeight = 0;
	queue<int> inputTime;
	queue<int> onBridgeTrucksWeights;
	while (true)
	{
		if (truck_weights.empty() && inputTime.empty())
			break;
		answer++;
		// Ʈ���� �ٸ� Ż��
		if (!inputTime.empty())
		{
			if (answer >= (inputTime.front() + bridge_length))
			{
				nowWeight -= onBridgeTrucksWeights.front();
				onBridgeTrucksWeights.pop();
				inputTime.pop();
			}
		}
		// Ʈ���� �ٸ� ����
		if (truck_weights.empty())
			continue;
		if (nowWeight + truck_weights.front() > weight)
			continue;
		nowWeight += truck_weights.front();
		onBridgeTrucksWeights.push(truck_weights.front());
		inputTime.push(answer);
		truck_weights.erase(truck_weights.begin());
	}
	return answer;
}

void main()
{
	cout << solution(2, 10, { 7,4,5,6 });
}