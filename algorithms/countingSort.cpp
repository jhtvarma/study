/*
	Counting sort
*/
#include<iostream>
using namespace std;
void countingSort(int *input, int *output, int k, int size);
void printArray(int *arr, int n);
int maximum(int *input, int size);
int main() {
	int input[] = { 1, 4, 1, 2, 7, 5, 2 };// {2, 5, 3, 0, 2, 3, 0, 3};
	const int size = sizeof(input) / sizeof(input[0]);
	int k = maximum(input, size);
	int output[size];

	printArray(input, size);
	countingSort(input, output, k+1, size);
	printArray(output, size);

	getchar();
	return 0;
}
void countingSort(int *input, int *output,int k,int size) {
	int *temp = new int[k];
	//Fill temp array with 0
	for (auto i = 0; i < k; i++) {
		temp[i] = 0;
	}
	//Fill the output array to 0
	for (auto i = 0; i < size; i++) {
		output[i] = 0;
	}
	//Find the count of each number in input array
	for (auto i = 0; i < size; i++) {
		temp[input[i]] += 1;
	}
	//Add numbers in temp array
	for (auto i = 1; i < k; i++) {
		temp[i] += temp[i-1];
	}
	
	//temp array now contains no of elements less than or equal to i
	for (auto i = size-1; i >=0 ; i--) {
		output[temp[input[i]]-1] = input[i];
		--temp[input[i]];
	}
}
int maximum(int *input, int size) {
	int maxNum = input[0];
	for (auto i = 1; i < size; i++) {
		if (input[i]>maxNum) {
			maxNum = input[i];
		}
	}
	return maxNum;
}
void printArray(int *arr,int n) {
	for (auto i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}