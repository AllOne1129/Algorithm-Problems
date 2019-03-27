#include <iostream>
using namespace std;

int main() {
	int degree;
	cin >> degree;

	int x, y;
	cin >> y >> x;

	int num = 0;
	int addNum = 1;

	for (; x > 0; x = x >> 1) {
		if (x % 2 == 1) {
			num += addNum;
		}
		addNum = addNum << 2;
	}

	addNum = 2;

	for (; y > 0; y = y >> 1) {
		if (y % 2 == 1) {
			num += addNum;
		}
		addNum = addNum << 2;
	}

	cout << num << endl;
	return 0;
}