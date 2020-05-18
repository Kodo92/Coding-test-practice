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
[규칙]
1. 0과 1의 반복
2. 0과 1 사이에 N-1배열의 값들이 0부터 순서대로 들어감

N = 0 N-1[0] 1 N-1[1] 0 N-1[2] 1	

1 : 0
2 : 0 '0' 1
3: 0 '0' 1 '0' 0 '1' 1
4: 0 '0' 1 '0' 0 '1' 1 '0' 0 '0' 1 '1' 0 '1' 1


*/