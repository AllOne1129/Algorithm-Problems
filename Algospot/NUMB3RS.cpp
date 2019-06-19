#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double cache[50];
int route[50][50];

int village, day;
double solution(int current, int count, int dst) {
	if (count == 1) { 
		if(route[current][dst]) return cache[current];
		else return 0;
	}
	
	double result = 0;
	for (int i = 0; i < village; i++) {
		if (route[current][i]) result += solution(i, count - 1,dst);
	}

	return result * cache[current];
}

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int start;
		cin >> village >> day >> start;

		for (int j = 0; j < village; j++) {
			int temp = 0;
			for (int k = 0; k < village; k++) {
				cin >> route[j][k];
				if (route[j][k]) {
					temp++;
				}
			}

			cache[j] = 1.0 / temp;
		}

		int find;
		cin >> find;

		vector<int> findVil(find);
		for (int j = 0; j < find; j++) {
			cin >> findVil[j];
		}

		cout.precision(8);
		for (int j = 0; j < find; j++) {
			cout << solution(start, day,findVil[j]) << endl;
		}
	}
	return 0;
}