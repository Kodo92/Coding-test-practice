#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<vector<int>> answer{ {0} };

	for (int i = 1; i < n; i++)
	{
		int Number = 0;
		vector<int> data;
		for (;; Number++)
		{
			data.push_back(Number % 2);
			if (Number == answer[i - 1].size())
				break;
			data.push_back(answer[i - 1][Number]);
		}
	}
	return answer.back();
}

/*
[��Ģ]
1. 0�� 1�� �ݺ�
2. 0�� 1 ���̿� N-1�迭�� ������ 0���� ������� ��

N = 0 N-1[0] 1 N-1[1] 0 N-1[2] 1	

1 : 0
2 : 0 '0' 1
3: 0 '0' 1 '0' 0 '1' 1
4: 0 '0' 1 '0' 0 '1' 1 '0' 0 '0' 1 '1' 0 '1' 1


*/