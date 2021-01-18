#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n : n����, t : ���ؾ� �ϴ� Ƚ��, m : ���ӿ� �����ϴ� �ο�, p : Ʃ���� ����
string solution(int n, int t, int m, int p) {
	string answer = "";

	int speakCount = 0;
	int tubeSpeakCount = 0;
	int number = 0;

	while (tubeSpeakCount < t)
	{
		vector<int> tempData;
		int tempNumber = number;

		if(tempNumber == 0)
			tempData.push_back(0);

		while (tempNumber > 0)
		{
			tempData.push_back(tempNumber % n);
			tempNumber /= n;
		}

		// number�� n������ ��ȯ�� ����� ������� ���Ѵ�.
		for (auto value = tempData.rbegin() ; value != tempData.rend(); value++)
		{
			if (speakCount == (p-1))
			{
				tubeSpeakCount++;
				if(*value >= 10)
					answer += *value + 55;
				else
					answer += to_string(*value);

				if (tubeSpeakCount >= t)
					break;
			}

			speakCount++;
			speakCount %= m;
		}
		number++;
	}
	return answer;
}

/*
number�� n������ �ٲٴ� ������� mod������ �����Ͽ���.

10���� A,B,C,D,E,F�� ��ȯ�ϴ� ���� int�� ���� char�� ��ȯ�� string�� �߰����־���.

*/