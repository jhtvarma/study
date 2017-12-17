/*
	Shell sort
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort(float *numbers, int size) {
	vector<float> buckets[10];
	int index;

	for (auto i = 0; i < size; i++) {
		index = (int)numbers[i] * 10;
		buckets[index].push_back(numbers[i]);
	}

	for (auto i = 0; i < 10; i++) {
		sort(buckets[i].begin(), buckets[i].end());
	}

	index = 0;
	for (auto i = 0; i < 10; i++) {
		for (auto j = 0; j < buckets[i].size(); j++) {
			numbers[index++] = buckets[i][j];
		}
	}
}
void printNumbers(float *numbers, int size) {
	for (auto i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}
int main() {
	float input[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int size = sizeof(input) / sizeof(input[0]);

	printNumbers(input, size);
	bucketSort(input, size);
	printNumbers(input, size);

	getchar();
	return 0;
}