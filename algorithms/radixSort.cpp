/*
	Radix sort
*/
#include<iostream>
#include<algorithm>
using namespace std;

void countSort(int numbers[], int size, int exp) {
	int *output = new int[size];
	int count[10] = {0};
	
	fill(output, output + size, 0);
	
	//Find count of occurences of exp digit
	for (auto i = 0; i < size; i++) {
		count[(numbers[i]/exp)%10]++;
	}
	//Add occurences such that count[i] contains the actual position of the digit
	for (auto i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	//Find the ouput array
	for (auto i = size - 1; i >= 0; i--) {
		output[count[(numbers[i]/exp)%10]-1] = numbers[i];
		count[(numbers[i] / exp) % 10]--;
	}
	//Copy numbers from output to numbers
	for (auto i = 0; i < size; i++) {
		numbers[i] = output[i];
	}

	delete[] output;	
}
void radixSort(int *numbers, int size) {
	int maxNumber = *max_element(numbers, numbers + size);

	for (auto exp = 1; maxNumber/exp > 0 ; exp *= 10) {
		countSort(numbers, size, exp);
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
	radixSort(input, size);
	printNumbers(input, size);

	getchar();
	return 0;
}