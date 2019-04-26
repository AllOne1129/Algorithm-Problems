#include <iostream>
using namespace std;

int cache[1000];

int tile(int num) {
	if (num == 1) {
		return 1;
	}
	else if (num == 2) {
		return 3;
	}
	else if (cache[num - 1]) {
		return cache[num - 1];
	}
	else {
		cache[num - 1] = (tile(num - 1) + (tile(num - 2) << 1)) % 10007;
		return cache[num - 1];
	}
}

int main() {
	int input;
	cin >> input;

	cout << tile(input) << '\n';
	return 0;
}