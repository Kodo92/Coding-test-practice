#include <iostream>


using std::cout;
using std::cin;

int main()
{
	int go = 0, back = 0, height = 0;
	cin >> go >> back >> height;

	if ((height - go) % (go - back) != 0)
		cout << ((height - go) / (go - back)) + 2;
	else
		cout << ((height - go) / (go - back)) + 1;
	return 0;
}