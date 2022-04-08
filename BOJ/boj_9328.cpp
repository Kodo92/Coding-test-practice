/*
	[백준 9328] 열쇠
		출처 : https://www.acmicpc.net/problem/9328
		풀이일 : 2022.03.24
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cctype>

bool hasKey(const int hasKeys, const char door) {
	return hasKeys & (1 << (door - 'A'));
}

void setKey(int& hasKeys, const char key) {
	hasKeys |= (1 << (key - 'a'));
}

int BFS(std::vector<std::string>&map, int hasKeys, const int h, const int w)
{
	int dx[]{ 0,0,-1,1 };
	int dy[]{ -1,1,0,0 };

	int findCount = 0;
	int pendingCount = 0;	// 잠긴 문에 도착한 상태의 개수

	std::list<std::pair<int, int>> queue;
	std::vector<std::vector<bool>> isVisited(h, std::vector<bool>(w, false));

	for (int i = 0; i < h; i++) {
		if (map[i][0] != '*' && !isVisited[i][0]) {
			if(hasKey(hasKeys,map[i][0]))
				queue.push_front({ i,0 });
			else
				queue.push_back({ i,0 });
			isVisited[i][0] = true;
			if (std::isupper(map[i][0]))
				pendingCount++;
			if (std::islower(map[i][0]))
				setKey(hasKeys, map[i][0]);
		}
		if (map[i][w - 1] != '*' && !isVisited[i][w - 1]) {
			if (hasKey(hasKeys, map[i][w-1]))
				queue.push_front({ i,w-1 });
			else
				queue.push_back({ i,w-1 });
			isVisited[i][w - 1] = true;
			if (std::isupper(map[i][w - 1]))
				pendingCount++;
			if (std::islower(map[i][w - 1]))
				setKey(hasKeys, map[i][w - 1]);
		}
	}

	for (int i = 0; i < w; i++) {
		if (map[0][i] != '*' && !isVisited[0][i]) {
			if (hasKey(hasKeys, map[0][i]))
				queue.push_front({ 0,i });
			else
				queue.push_back({ 0,i });
			isVisited[0][i] = true;
			if (std::isupper(map[0][i]))
				pendingCount++;
			if (std::islower(map[0][i]))
				setKey(hasKeys, map[0][i]);
		}
		if (map[h - 1][i] != '*' && !isVisited[h - 1][i]) {
			if (hasKey(hasKeys, map[h-1][i]))
				queue.push_front({ h-1,i });
			else
				queue.push_back({ h-1,i });
			isVisited[h - 1][i] = true;
			if (std::isupper(map[h - 1][i]))
				pendingCount++;
			if (std::islower(map[h - 1][i]))
				setKey(hasKeys, map[h - 1][i]);
		}
	}

	while (!queue.empty()) {
		std::pair<int, int> now = queue.front();
		queue.pop_front();

		if (std::isupper(map[now.first][now.second])) {
			if (hasKey(hasKeys, map[now.first][now.second])) {
				pendingCount--;
			}
			else {
				queue.push_back(now);
				if (queue.size() == pendingCount)
					break;
				continue;
			}
		}


		if (map[now.first][now.second] == '$')
			findCount++;

		for (int i = 0; i < 4; i++) {
			int newY = now.first + dy[i];
			int newX = now.second + dx[i];

			if (newY < 0 || newY >= h || newX < 0 || newX >= w) continue;
			if (map[newY][newX] == '*') continue;
			if (isVisited[newY][newX]) continue;

			isVisited[newY][newX] = true;

			if (std::islower(map[newY][newX]))
				hasKeys |= (1 << (map[newY][newX] - 'a'));

			if (std::isupper(map[newY][newX])) {
				pendingCount++;
				if (hasKey(hasKeys, map[newY][newX])) {
					queue.push_front({ newY,newX });
					continue;
				}
			}
			queue.push_back({ newY,newX });
		}
	}

	return findCount;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	for (size_t testCase = 1; testCase <= T; testCase++)
	{
		int h, w;
		std::cin >> h >> w;

		std::vector<std::string> map(h);
		for (size_t i = 0; i < h; i++)
			std::cin >> map[i];

		std::string keys;
		std::cin >> keys;

		int hasKeys = 0;
		if (keys != "0") {
			for (char c : keys) {
				setKey(hasKeys, c);
			}
		}

		std::cout << BFS(map, hasKeys, h, w) << '\n';

	}
}

/*
3
3 6
****.*
Z$B$B*
******
b
5 8
********
*DcB.*b*
*$*..*A*
*E$C...*
****.***
a
15 15
**$*.**********
****.*******$**
****B.$****b.**
$*****c*****.**
*C$.*****fD..**
*$*xd******.**$
$.C********A.**
**h********.AA.
***************
***.i**********
***.***.K$*****
*k.$$I.$*******
******.$..j***$
*******D*******
****$**F*******
za

1
5 11
*x*********
*...*...*.*
*X*.*.*.*.*
*$*...*...*
***********
0

# 1
# 5 5
# ABABA
# AabaB
# Bb$aB
# AbabB
# AABAa
# 0

# 3
# 5 17
# *****************
# .............**$*
# *B*A*P*C**X*Y*.X.
# *y*x*a*p**$*$**$*
# *****************
# cz
# 5 11
# *.*********
# *...*...*x*
# *X*.*.*.*.*
# *$*...*...*
# ***********
# 0
# 7 7
# *ABCDE*
# X.....F
# W.$.G
# V.$.H
# U.$.J
# T.....K
# *SQPMI*
# irony

# 1
6 3
***
...
*X*
*X*
*$*
***
x

1
2 2
$
$
0

1
3 3
aaa
a$a
aaa
0

4 5
1
*A***
*$*a.
**$**
**A**
0

1
5 11
*x*********
*...*...*.*
*X*.*.*.*.*
*$*...*...*
***********
0

1
3 4
****
*$A*
****
a

*/