#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>&, int);

int main() {
	ios_base::sync_with_stdio();
	cin.tie();

	int test;
	cin >> test;
	for (int n = 0; n < test; n++) {
		int num;
		cin >> num;
		vector<int> sequence(num);
		for (int i = 0; i < num; i++) {
			cin >> sequence[i];
		}

		cout << LIS(sequence, 0) << endl;
	}
	return 0;
}

inline int Max(int a, int b) {
	return a > b ? a : b;
}

int LIS(vector<int>& sequence, int index) {
	if (index == sequence.size() - 1) return 1;

	int result = 1;
	int temp = sequence[index];
	for (int i = index + 1; i < sequence.size(); i++) {
		if (temp < sequence[i]) {
			temp = sequence[i];
			result++;
		}
	}

	result = Max(result, LIS(sequence, index + 1));

	return result;
}