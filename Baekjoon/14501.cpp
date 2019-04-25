#include <iostream>
#include <vector>
using namespace std;

int cache[500];
int solution(vector<int>& days,vector<int>& costs,int day);

int main() {
	cin.tie();
	ios_base::sync_with_stdio();

	int input;
	cin >> input;

	vector<int> requireDays(input);
	vector<int> costs(input);

	for (int i = 0; i < input; i++) {
		cin >> requireDays[i] >> costs[i];
	}

	cout << solution(requireDays, costs, 0) << endl;
	return 0;
}

int solution(vector<int>& days, vector<int>& costs, int day) {
	if (day >= days.size()) {
		return 0;
	}
	
	if (cache[day]) {
		return cache[day];
	}
	
	int answer = 0;
	if (!(day + days[day] > days.size())) {
		answer = costs[day];
		int max = 0;
		for (int i = day + days[day]; i < days.size(); i++) {
			int temp = solution(days, costs, i);
			max = max > temp ? max : temp;
		}
		answer += max;
		cache[day] = answer;
	}
	
	int temp = solution(days, costs, day + 1);
	answer = answer > temp ? answer : temp;

	return answer;
}