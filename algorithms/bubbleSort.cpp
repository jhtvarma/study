/*
	Bubble sort
*/
#include<iostream>
using namespace std;
void bubbleSort(int *numbers, int size);
void printNumbers(int *numbers, int size);
void swap(int *a, int *b);
int main() {
	int input[] = {5,1,4,2,8,-1,9,-34,56};
	int size = sizeof(input) / sizeof(input[0]);

	printNumbers(input,size);
	bubbleSort(input,size);
	printNumbers(input, size);

	getchar();
	return 0;
}
void bubbleSort(int *numbers, int size) {
	for (auto i = 0; i < size-1; i++) {
		for (auto j = 0; j < size-i-1; j++) {
			if (numbers[j] > numbers[j+1]) {
				swap(&numbers[j],&numbers[j+1]);
			}
		}
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