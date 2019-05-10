#include <iostream>
#include <vector>
using namespace std;

int cache[300][2];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int solution(vector<int>& stairs) {
	cache[stairs.size() - 1][0] = cache[stairs.size() - 1][1] = stairs[stairs.size() - 1];
	cache[stairs.size() - 2][0] = cache[stairs.size() - 1][0] + stairs[stairs.size() - 2];
	cache[stairs.size() - 2][1] = 0;

	for (int i = stairs.size() - 3; i >= 0; i--) {
		cache[i][0] = max(cache[i + 1][1], cache[i + 2][0]) + stairs[i];
		cache[i][1] = cache[i + 2][0] + stairs[i];
	}

	return max(cache[0][0], cache[1][0]);
}

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	int input;
	cin >> input;

	vector<int> stairs(input);

	for (int i = 0; i < input; i++) {
		cin >> stairs[i];
	}

	cout << solution(stairs) << '\n';
	return 0;
}