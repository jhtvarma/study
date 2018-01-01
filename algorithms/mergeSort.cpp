//TODO: Find inversions in array by modfying merge sort
#include<iostream>
using namespace std;
void mergeSort(int *numbers, int start, int end);
void merge(int *numbers, int start, int middle, int end);
void print(int numbers[],int);
int main() {
	int numbers[] = {5,1,8,3,9,2,0,-1,7,-3};
	int sizeOfNumbers = sizeof(numbers) / sizeof(numbers[0]);

	print(numbers,sizeOfNumbers);
	mergeSort(numbers, 0, sizeOfNumbers-1);
	print(numbers,sizeOfNumbers);

	getchar();
	return 0;
}
void mergeSort(int *numbers,int start,int end) {
	if (start >= end) {
		return;
	}
	int middle = start + (end - start) / 2;
	mergeSort(numbers, start, middle);
	mergeSort(numbers, middle+1, end);
	merge(numbers, start, middle, end);
}
void merge(int *numbers,int start,int middle,int end) {
	int i, j, k;
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int *set1 = new int[n1],
		*set2 = new int[n2];

	for (i = 0; i < n1; i++) {
		set1[i] = numbers[start + i];
	}

	for (i = 0; i < n2; i++) {
		set2[i] = numbers[middle + i + 1];
	}
	
	i = 0;
	j = 0;
	k = start;
	while (i<n1 && j<n2) {
		if (set1[i] < set2[j]) {
			numbers[k++] = set1[i++];
		}
		else {
			numbers[k++] = set2[j++];
		}
	}

	while (i<n1) {
		numbers[k++] = set1[i++];
	}
	
	while (j<n2) {
		numbers[k++] = set2[j++];
	}

	delete[] set1;
	delete[] set2;
}
//numbers[0] address will be passed to functions
void print(int *numbers,int sizeOfNumbers) {	
	for (int i = 0; i < sizeOfNumbers;i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}