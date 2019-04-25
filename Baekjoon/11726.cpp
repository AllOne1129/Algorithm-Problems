#include <iostream>
using namespace std;

unsigned long long cache[1000];
unsigned long long fibonacci(int n) {
	if (cache[n - 1]) {
		return cache[n - 1];
	}
	if (n == 1) {
		cache[0] = 1;
		return 1;
	}
	else if (n == 2) {
		cache[1] = 2;
		return 2;
	}

	cache[n - 1] = (fibonacci(n - 1) + fibonacci(n - 2)) % 10007;
	return cache[n - 1];
}

int main() {
	int n;

	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}