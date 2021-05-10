#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
	int answer = 0;
	size_t heightSize = board.size();
	size_t widthSize = board.front().size();

	for (int i = 1; i < heightSize; i++) {
		for (int j = 1; j < widthSize; j++) {
			if (!board[i][j]) continue;
			board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
			answer = (answer < board[i][j]) ? board[i][j] : answer;
		}
	}

	return answer;
}

int main()
{
	//cout << solution({ {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} });
	cout << solution({ {0,0,1,1},{0,0,1,0}});

	return 0;
}

/*
TC 1 : 1มู
TC 8 : All 0
*/