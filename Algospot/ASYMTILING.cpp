#include <iostream>
using namespace std;

constexpr long long DIV = 1000000007;
unsigned long long fibonacci[10000];

unsigned long long fibo(unsigned long long num) {
	if (num <= 2) {
		return num;
	}
	if (fibonacci[num]) {
		return fibonacci[num];
	}
	else {
		fibonacci[num] = (fibo(num - 1) + fibo(num - 2));
		return fibonacci[num];
	}
}
unsigned long long solution(unsigned long long num) {
	if (num <= 2) {
		return 0;
	}

	if (num % 2 == 0) {
		return ((fibo(num) - (fibo(num / 2))+DIV)%DIV - fibo(num / 2 - 1) + DIV) % DIV;
	}
	else {
		return (fibo(num) - fibo(num / 2) + DIV) % DIV;
	}
}
int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	unsigned long input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		unsigned long long tiles;
		cin >> tiles;
		cout << solution(tiles) << '\n';
	}
	return 0;
}