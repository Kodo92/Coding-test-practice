#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag = false;

	do
	{
		flag = false;
		set<pair<int, int>> usedNumber;
		for (int i = 0; i<(m - 1); i++)
		{
			for (int j = 0; j<(n - 1); j++)
			{
				if (board[i][j] == '-')
					continue;
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1])
				{
					flag = true;
					usedNumber.insert(make_pair(i, j));
					usedNumber.insert(make_pair(i, j + 1));
					usedNumber.insert(make_pair(i + 1, j));
					usedNumber.insert(make_pair(i + 1, j + 1));
				}
			}
		}

		for (auto& i : usedNumber)
			board[i.first][i.second] = '-';

		answer += usedNumber.size();
		// 블록 아래로 내리기
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = 0; j<n; j++)
			{
				if (board[i][j] == '-')
				{
					for (int k = i; k >= 0; k--)
					{
						if (board[k][j] == '-')
							continue;
						else
						{
							board[i][j] = board[k][j];
							board[k][j] = '-';
							break;
						}
					}
				}
			}
		}
	} while (flag);
	return answer;
}

/*
void main()
{
	cout << solution(4, 4, { "ABCD","BACE","BCDD","BCDD" })<<endl;	// 1번
	cout << solution(2, 1, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });
	cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" });
}

- 블록 아래로 내릴 때 1번 케이스 오류 있었음. BREAK 추가.
*/