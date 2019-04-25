#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string first = a + b;
	string second = c + d;

	long long first2 = atoi(first.c_str());
	long long second2 = atoi(second.c_str());

	cout << first2 + second2 << '\n';
	return 0;
}