/*
	4가지 버전 : 로직은 같지만 사용하는 자료구조를 바꿔가며 성능을 올림
	1번 : queue,array,vector사용														12,692kb		/	30ms
	2번 : queue,array -> unorded_map, vector, set (new) 사용				12,712kb		/	36ms
	3번 : queue, (unorded_map, vector, set -> int[]) 사용						12,696kb		/	25ms
	4번 : queue -> int[] 사용																12,680kb		/	24ms
*/

// 1번
/*
#include<iostream>
#include<array>
#include<vector>
#include<queue>

using namespace std;

array<int, 100>parkingArea{};
int Revenue = 0;
queue<int> waitQueue;
vector<int> parkingCost, carWeight;
int N = 0, M = 0;

int getEmptyArea()
{
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == 0)
			return i;
	}
	return -1;
}

int getWaitNumber()
{
	if (waitQueue.size() == 0)
		return -1;
	int retVal = waitQueue.front();
	waitQueue.pop();
	return retVal;
}

bool pushParking(int carNumber)
{
	if (carNumber == -1) return false;
	int retVal = getEmptyArea();
	if (retVal == -1)
	{
		waitQueue.push(carNumber);
		return false;
	}
	parkingArea[retVal] = carNumber;
	Revenue += parkingCost[retVal] * carWeight[carNumber - 1];
	return true;
}

void popParking(int carNumber)
{
	carNumber *= -1;
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == carNumber)
		{
			parkingArea[i] = 0;
			return;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int Count = 0, inputData = 0;
	int orderCount = 0;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Revenue = 0;
		parkingCost.clear();
		carWeight.clear();
		parkingArea.fill(0);

		cin >> N >> M;
		for (Count = 0; Count<N; Count++)
		{
			cin >> inputData;
			parkingCost.push_back(inputData);
		}
		for (Count = 0; Count<M; Count++)
		{
			cin >> inputData;
			carWeight.push_back(inputData);
		}

		orderCount = M * 2;
		for (Count = 0; Count<orderCount; Count++)
		{
			cin >> inputData;
			if (inputData<0) {
				popParking(inputData);
				inputData = getWaitNumber();
			}
			pushParking(inputData);
		}
		cout << '#' << test_case << ' ' << Revenue << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/

// 2번
/*
#include<iostream>
#include<array>
#include<set>
#include<unordered_map>
#include<queue>

using namespace std;

int Revenue = 0;
queue<int> waitQueue;
vector<int> parkingCost, carWeight;
unordered_map<int, int> parkingArea;
set<int> emptyArea;
int N = 0, M = 0;

int getEmptyArea()
{
	auto retVal = emptyArea.begin();
	if (retVal == emptyArea.end())
		return -1;
	emptyArea.erase(emptyArea.begin());
	return *retVal;
}

int getWaitNumber()
{
	if (waitQueue.size() == 0)
		return -1;
	int retVal = waitQueue.front();
	waitQueue.pop();
	return retVal;
}

bool pushParking(int carNumber)
{
	if (carNumber == -1) return false;
	int retVal = getEmptyArea();
	if (retVal == -1)
	{
		waitQueue.push(carNumber);
		return false;
	}
	parkingArea.insert(make_pair(carNumber, retVal));
	Revenue += parkingCost[retVal] * carWeight[carNumber - 1];
	return true;
}

void popParking(int carNumber)
{
	carNumber *= -1;
	auto retVal = parkingArea.find(carNumber);
	if (retVal == parkingArea.end())
	{
		return;
	}
	emptyArea.insert(retVal->second);
	parkingArea.erase(retVal);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int Count = 0, inputData = 0;
	int orderCount = 0;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Revenue = 0;
		parkingCost.clear();
		carWeight.clear();
		parkingArea.clear();
		emptyArea.clear();

		cin >> N >> M;
		for (Count = 0; Count<N; Count++)
			emptyArea.insert(Count);
		for (Count = 0; Count<N; Count++)
		{
			cin >> inputData;
			parkingCost.push_back(inputData);
		}
		for (Count = 0; Count<M; Count++)
		{
			cin >> inputData;
			carWeight.push_back(inputData);
		}

		orderCount = M * 2;
		for (Count = 0; Count<orderCount; Count++)
		{
			cin >> inputData;
			if (inputData<0) {
				popParking(inputData);
				inputData = getWaitNumber();
			}
			pushParking(inputData);
		}
		cout << '#' << test_case << ' ' << Revenue << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/

// 3번
/*
#include<iostream>

#include<queue>

using namespace std;

int Revenue = 0;
queue<int> waitQueue;
int parkingCost[100]{}, carWeight[2000]{};
int parkingArea[100]{};
int N = 0, M = 0;
int emptyCount = 0;

int getEmptyArea()
{
	if (emptyCount == 0) return -1;
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == 0)
			return i;
	}
	return -1;
}

int getWaitNumber()
{
	if (waitQueue.size() == 0)
		return -1;
	int retVal = waitQueue.front();
	waitQueue.pop();
	return retVal;
}

void pushParking(int carNumber)
{
	if (carNumber == -1) return;
	int retVal = getEmptyArea();
	if (retVal == -1)
		waitQueue.push(carNumber);
	else
	{
		parkingArea[retVal] = carNumber, retVal;
		emptyCount--;
		Revenue += parkingCost[retVal] * carWeight[carNumber - 1];
	}
}

void popParking(int carNumber)
{
	carNumber *= -1;
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == carNumber)
		{
			emptyCount++;
			parkingArea[i] = 0;
			return;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int Count = 0, inputData = 0;
	int orderCount = 0;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Revenue = 0;

		cin >> N >> M;
		emptyCount = N;

		for (Count = 0; Count<N; Count++)
		{
			cin >> inputData;
			parkingCost[Count] = inputData;
		}

		for (Count = 0; Count<M; Count++)
		{
			cin >> inputData;
			carWeight[Count] = inputData;
		}

		orderCount = M * 2;
		for (Count = 0; Count<orderCount; Count++)
		{
			cin >> inputData;
			if (inputData<0) {
				popParking(inputData);
				inputData = getWaitNumber();
			}
			pushParking(inputData);
		}
		cout << '#' << test_case << ' ' << Revenue << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/

// 4번
/*
#include<iostream>

using namespace std;

int Revenue = 0;
int *parkingCost, *carWeight;
int *parkingArea, *waitingArea;
int N = 0, M = 0;
int emptyCount = 0, waitingRearPos = 0, waitingFrontPos = 0;

int getEmptyArea()
{
	if (emptyCount == 0) return -1;
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == 0)
			return i;
	}
	return -1;
}

int getWaitNumber()
{
	if (waitingRearPos <= waitingFrontPos) return -1;
	waitingFrontPos++;

	return waitingArea[waitingFrontPos - 1];

}

void setWaitingNumber(int carNumber)
{
	waitingArea[waitingRearPos] = carNumber;
	waitingRearPos++;
}

void pushParking(int carNumber)
{
	if (carNumber == -1) return;
	int retVal = getEmptyArea();
	if (retVal == -1)
		setWaitingNumber(carNumber);
	else
	{
		parkingArea[retVal] = carNumber, retVal;
		emptyCount--;
		Revenue += parkingCost[retVal] * carWeight[carNumber - 1];
	}
}

void popParking(int carNumber)
{
	carNumber *= -1;
	for (int i = 0; i<N; i++)
	{
		if (parkingArea[i] == carNumber)
		{
			emptyCount++;
			parkingArea[i] = 0;
			return;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int Count = 0, inputData = 0;
	int orderCount = 0;

	parkingCost = new int[100]{};
	parkingArea = new int[100]{};
	carWeight = new int[2000]{};
	waitingArea = new int[2000]{};
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Revenue = 0;

		cin >> N >> M;
		emptyCount = N;

		for (Count = 0; Count<N; Count++)
		{
			cin >> inputData;
			parkingCost[Count] = inputData;
		}

		for (Count = 0; Count<M; Count++)
		{
			cin >> inputData;
			carWeight[Count] = inputData;
		}

		orderCount = M * 2;
		for (Count = 0; Count<orderCount; Count++)
		{
			cin >> inputData;
			if (inputData<0) {
				popParking(inputData);
				inputData = getWaitNumber();
			}
			pushParking(inputData);
		}
		cout << '#' << test_case << ' ' << Revenue << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/