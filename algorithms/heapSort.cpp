/*
	javascript : Uses Insertion sort and Quick sort
	If no of elements < 10 -> Insertion else Quick sort
	(https://github.com/v8/v8/blob/master/src/js/array.js)
	Java : 
	Uses TimSort(For Objects),
	Dual Pivoted Quick sort(For Primitives) - length<27 use Insertion else quick
	(http://codeblab.com/wp-content/uploads/2009/09/DualPivotQuicksort.pdf)
	(https://stackoverflow.com/questions/4018332/is-java-7-using-tim-sort-for-the-method-arrays-sort)
	(http://hg.openjdk.java.net/jdk7/jdk7/jdk/rev/bfd7abda8f79)
	C++ : Uses IntroSort (Combo of Quick,Heap and Insertion sort)
	Python : Timsort and BinarySort
	(https://github.com/python/cpython/blob/master/Objects/listobject.c)
	Sorting alogorithms in different languages
	http://www.geeksforgeeks.org/know-sorting-algorithm-set-1-sorting-weapons-used-programming-languages/
*/
/*
	Heap sort
*/
#include<iostream>
using namespace std;
void heapSort(int *numbers, int size);
void printNumbers(int *numbers, int size);
void swap(int *a, int *b);
void heapify(int *arr,int n, int i);
int main() {
	int input[] = {5,1,4,2,8,-1,9,-34,56};//{1,2,3,4,5,6,7,8,9}
	int size = sizeof(input) / sizeof(input[0]);

	printNumbers(input,size);
	heapSort(input,size);
	printNumbers(input, size);

	getchar();
	return 0;
}
// i is the index of subtree which need to be heapify
void heapify(int *numbers, int n, int i) {
	int largest = i; //Initialize root as largest 
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	//If left child is larger that root
	if (left<n && numbers[left]>numbers[largest]) {
		largest = left;
	}

	//If right child is larger that root
	if (right<n && numbers[right]>numbers[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(&numbers[i],&numbers[largest]);

		heapify(numbers, n, largest);
	}

}
void heapSort(int *numbers, int size) {
	for (auto i = size/2-1; i >=0; i--) {
		heapify(numbers, size, i);
	}
	printNumbers(numbers,size);
	for (auto i = size - 1; i >= 0; i--) {
		swap(&numbers[0],&numbers[i]);
		heapify(numbers,i,0);
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