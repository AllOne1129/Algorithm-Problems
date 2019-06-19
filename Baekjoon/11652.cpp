#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	int input;
	cin >> input;

	vector<long long> cards(input);
	for (int i = 0; i < input; i++) {
		cin >> cards[i];
	}

	sort(cards.begin(), cards.end());
	long long temp = 0;
	int tempCount = 0;
	long long max = 0;
	int maxCount = 0;
	for (int i = 0; i <= input; i++) {
		if (i == input || temp != cards[i]) {
			int n = tempCount;

			if (maxCount < n) {
				maxCount = n;
				max = temp;
			}
			if (i == input) {
				break;
			}
			temp = cards[i];
			tempCount = 0;
		}
		tempCount++;
	}

	cout << max << endl;
	return 0;
}