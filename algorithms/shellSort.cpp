/*
	Shell sort
*/
#include<iostream>
#include<algorithm>
using namespace std;

void shellSort(int *numbers, int size) {
	
	for (auto gap = size / 2; gap > 0; gap /= 2) {
		
		for (auto j = gap; j < size; j++) {
			int temp = numbers[j];
			int k;
			for (k = j; k >= gap && numbers[k - gap] > temp; k -= gap) {
				numbers[k] = numbers[k - gap];
			}
			numbers[k] = temp;
		}

	}
}
void printNumbers(int *numbers, int size) {
	for (auto i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}
int main() {
	int input[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int size = sizeof(input) / sizeof(input[0]);

	printNumbers(input, size);
	shellSort(input, size);
	printNumbers(input, size);

	getchar();
	return 0;
}