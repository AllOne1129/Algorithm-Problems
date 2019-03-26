#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>&, vector<int>&, int);

int main() {
	int test;
	cin >> test;
	for (int n = 0; n < test; n++) {
		int num;
		cin >> num;
		vector<int> sequence(num);
		vector<int> cache(num, -1);
		for (int i = 0; i < num; i++) {
			cin >> sequence[i];
		}

		cout << LIS(sequence,cache,0) << endl;
	}
	return 0;
}

inline int Max(int a, int b) {
	return a > b ? a : b;
}

int LIS(vector<int>& sequence, vector<int>& cache, int index) {
	if (index == sequence.size() - 1) return 1;

	if (cache[index] != -1) return cache[index];

	int nextIdx;

	int maxNum = sequence[index];
	int lisLength = 1;

	for (nextIdx = index + 1; nextIdx < sequence.size(); nextIdx++) {
		if (maxNum < sequence[nextIdx]) {
			maxNum = sequence[nextIdx];
			lisLength++;
		}
	}

	cache[index] = lisLength;

	return Max(LIS(sequence,cache,index+1),cache[index]);

}