#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

	int input, find;
	scanf("%d %d", &input, &find);

	int* num = new int[input];
	for (int i = 0; i < input; i++) {
		scanf("%d", &num[i]);
	}

	sort(&num[0],&num[input]);
	printf("%d\n", num[find - 1]);
	return 0;
}