/*
	Selection sort
*/
#include<iostream>
using namespace std;
void selectionSort(int *numbers, int size);
void printNumbers(int *numbers, int size);
void swap(int *a, int *b);
int main() {
	int input[] = {5,1,4,2,8,-1,9,-34,56};
	int size = sizeof(input) / sizeof(input[0]);

	printNumbers(input,size);
	selectionSort(input,size);
	printNumbers(input, size);

	getchar();
	return 0;
}
void selectionSort(int *numbers, int size) {
	int minIndex;
	for (auto i = 0; i < size - 1; i++) {
		minIndex = i;
		for (auto j = i+1; j < size; j++) {
			if (numbers[j] < numbers[minIndex]) {
				minIndex = j;
			}
		}
		swap(&numbers[i], &numbers[minIndex]);
	}
}
void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
void printNumbers(int *numbers, int size) {
	for (auto i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}