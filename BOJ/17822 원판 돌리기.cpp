#include <iostream>
#include <vector>
#include <deque>
#include <set>

int N, M, T;

std::vector<std::deque<int>> numbers;

void rotation(int x, int d, int k)
{
	for (int i = 1; ((x*i)-1) < N; i++)
	{
		auto& data = numbers[((x*i)-1)];
		switch (d)
		{
		case 0:
			for (int i = 0; i < k; i++)
			{
				data.push_front(data.back());
				data.pop_back();
			}
			break;
		case 1:
			for (int i = 0; i < k; i++)
			{
				data.push_back(data.front());
				data.pop_front();
			}
		default:
			break;
		}
	}
}

void Readjustment()
{
	int count = 0;
	double avr = 0;
	for (int index = 0; index < N; index++)
	{
		for (const auto i : numbers[index])
		{
			if (i == 0) continue;
			count++;
			avr += i;
		}
	}
	if(count != 0)
		avr /= count;
	for (int index = 0; index < N; index++)
	{
		for (auto& i : numbers[index])
		{
			if (i == 0) continue;
			if (i > avr)
				i -= 1;
			else if( i < avr)
				i += 1;
		}
	}
}

bool findAdjacent()
{
	std::set<std::pair<int,int>> deletePos;	// y,x

	for (int index = 0; index < N; index++)
	{
		int prevIndex = -1, nextIndex = -1;
		if (index > 1)
			prevIndex = index - 1;
		if (index < N - 1)
			nextIndex = index + 1;

		for (int i = 0; i < M; i++)
		{
			if (numbers[index][i] == 0) continue;
			// 원판 간 인접 체크
			if (prevIndex != -1 && numbers[index][i] == numbers[prevIndex][i])
			{
				deletePos.insert({ prevIndex,i });
				deletePos.insert({ index,i });
			}
			if (nextIndex != -1 && numbers[index][i] == numbers[nextIndex][i])
			{
				deletePos.insert({ nextIndex,i });
				deletePos.insert({ index,i });
			}

			// 한 원판내 인접 체크
			int next = i + 1;
			if (next == M) next = 0;
			if (numbers[index][i] == numbers[index][next])
			{
				deletePos.insert({ index,i });
				deletePos.insert({ index,next });
			}
		}
	}

	for (auto i : deletePos)
		numbers[i.first][i.second] = 0;

	return deletePos.size();
}

void findNerase()
{
	if (!findAdjacent())
		Readjustment();
}

int sum()
{
	int sum = 0;
	for (const auto i : numbers)
		for (const auto j : i)
			sum += j;
	return sum;
}

int main()
{

	std::cin >> N >> M >> T;

	numbers.resize(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			std::cin >> temp; 
			numbers[i].push_back(temp);
		}
	}

	for (int i = 0; i < T; i++)
	{
		int X, D, K;
		std::cin >> X >> D >> K;
		rotation(X, D, K);
		findNerase();
	}

	std::cout << sum();
	
	return 0;
}

/*
#include <iostream>
using namespace std;

int board[50][50];
int start_line[50];
int chk_board[50][50];
int N, M, T;

void showCurcle() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int idx = (start_line[i] + j) % M;
			if (board[i][idx] == -1) cout << "x ";
			else cout << board[i][idx] << ' ';
		}
		cout << '\n';
	}
}
void rotCurcle() {
	bool isremove = false;
	for (int i = 0; i < N; i++) {
		int prev_idx = M - 1;
		for (int j = 0; j < M; j++) {
			if (board[i][j] == -1) {
				prev_idx = j;
				continue;
			}

			if (board[i][prev_idx] == board[i][j]) {
				chk_board[i][prev_idx] = true;
				chk_board[i][j] = true;
				isremove = true;
			}
			prev_idx = j;
		}
	}

	for (int i = 0; i < M; i++) {
		int prev_idx = (start_line[0] + i) % M;
		for (int j = 1; j < N; j++) {
			int cur_idx = (start_line[j] + i) % M;
			if (board[j][cur_idx] == -1) {
				prev_idx = cur_idx;
				continue;
			}

			if (board[j - 1][prev_idx] == board[j][cur_idx]) {
				chk_board[j - 1][prev_idx] = true;
				chk_board[j][cur_idx] = true;
				isremove = true;
			}

			prev_idx = cur_idx;
		}
	}

	if (isremove) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (chk_board[i][j])
					board[i][j] = -1;
			}
		}
	}
	else {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != -1) {
					sum += board[i][j];
					cnt++;
				}
			}
		}
		if (cnt == 0) return;
		double avg = (double)sum / cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != -1) {
					if (avg < board[i][j])
						board[i][j] -= 1;
					else if (avg > board[i][j])
						board[i][j] += 1;
				}
			}
		}

	}
}

int calcStore() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != -1) {
				sum += board[i][j];
			}
		}
	}
	return sum;
}
int main(void) {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		for (int j = x; j <= N; j += x) {
			if (d == 0)
				start_line[j - 1] = (start_line[j - 1] - k + M) % M;
			else
				start_line[j - 1] = (start_line[j - 1] + k) % M;
		}
		rotCurcle();
		showCurcle();
	}
	cout << calcStore() << endl;
	return 0;
}
*/
