#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	char word[10000];
	cin >> word;

	vector<string> suffix(strlen(word));
	for (int i = 0; i < suffix.size(); i++) {
		suffix[i] = word + i;
	}

	sort(suffix.begin(), suffix.end());
	for (int i = 0; i < suffix.size(); i++) {
		cout << suffix[i] << endl;
	}
	return 0;
}