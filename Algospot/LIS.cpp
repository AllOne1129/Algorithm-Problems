#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>&);

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

		cout << LIS(sequence) << endl;
	}
	return 0;
}

inline int Max(int a, int b) {
	return a > b ? a : b;
}

int LIS(vector<int>& sequence) {
	if (sequence.empty()) return 0;
	int result = 0;

	for (int i = 0; i < sequence.size(); i++) {
		vector<int> temp;
		for (int j = i + 1; j < sequence.size(); j++) {
			if (sequence[i] < sequence[j])
				temp.push_back(sequence[j]);
		}

		result = Max(result, 1 + LIS(temp));
	}
	return result;
}