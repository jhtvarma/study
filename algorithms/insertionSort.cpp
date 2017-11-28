#include<iostream>
using namespace std;
void insertionSort(int numbers[],int);
void print(int numbers[],int);
int main() {
	int numbers[] = {5,1,8,3,9,2,0,-1,7,-3};
	int sizeOfNumbers = sizeof(numbers) / sizeof(numbers[0]);
	
	//include algorithm header
	//Send address of first and last numbers
	//sort(numbers, numbers+sizeOfNumbers); - ascending 
	//sort(numbers, numbers+sizeOfNumbers, greater<int>()); - descending
	//Combo of quick sort and heap sort - intro sort - hybrid algo - worst case - O(nlogn)
	//http://www.geeksforgeeks.org/c-qsort-vs-c-sort/

	print(numbers,sizeOfNumbers);
	insertionSort(numbers,sizeOfNumbers);
	print(numbers,sizeOfNumbers);

	getchar();
	return 0;
}
//in place sort - O(n^2)
void insertionSort(int *numbers, int sizeOfNumbers) {
	int i, j, key;

	for(j = 1; j < sizeOfNumbers; j++) {
		key = numbers[j];
		i = j - 1;
		while (i>=0 && numbers[i]<key) {
			numbers[i + 1] = numbers[i];
			i = i - 1;
		}
		numbers[i+1] = key;
	}
}
//numbers[0] address will be passed to functions
void print(int *numbers,int sizeOfNumbers) {	
	for (int i = 0; i < sizeOfNumbers;i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n";
}