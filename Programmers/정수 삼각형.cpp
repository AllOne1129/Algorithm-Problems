#include <iostream>
#include <vector>
using namespace std;

int cache[500][500];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j <= i; j++) {
			int temp = 0;
			if (j - 1 > 0) {
				temp = cache[i - 1][j - 1];
			}

			if (j < i) {
				temp = temp < cache[i - 1][j] ? cache[i - 1][j] : temp;
			}

			cache[i][j] = temp + triangle[i][j];
		}
	}

	for (int i = 0; i < triangle.size(); i++) {
		answer = answer > cache[triangle.size() - 1][i] ? answer : cache[triangle.size() - 1][i];
	}
	return answer;
}