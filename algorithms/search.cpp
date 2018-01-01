#include<iostream>
#include<algorithm>
using namespace std;
bool linearSearch(int *numbers, int size, int search);
bool iterativeBinarySearch(int *numbers, int start, int end, int search);
bool recursiveBinarySearch(int *numbers, int start, int end, int search);
int main() {
	int numbers[] = { 6,9,4,2,7,-8,0,1 },
		size = sizeof(numbers) / sizeof(numbers[0]),
		expected = -8,
		isNumberFound = false;

	//Linear Search - O(n) 
	cout << "Linear Search : " << linearSearch(numbers, size, expected);

	//Binary Search - O(log2 n)
	sort(numbers,numbers+size);
	cout << endl << "Iterative Binary search : " << iterativeBinarySearch(numbers, 0, size-1, expected);
	cout << endl << "Recursive Binary search : " << recursiveBinarySearch(numbers, 0, size-1, expected);
	cout << endl << "STL Binary search : " << binary_search(numbers, numbers+size, 4);

	//Jump Search - O(sqrt(n))
	//m = sqrt(n) -> n/m + m - 1 -> use differentiation

	//Ternary Search - O(log3 n)
	//Binary search is better than ternary search

	//Interpolation Search - Avg : O(log(log n)) - Worst : O(n)
	//pos = lo + (((double)(hi-lo) / (arr[hi] - arr[lo]))*(x - arr[lo]));
	//https://stackoverflow.com/questions/32330185/computing-mid-in-interpolation-search/45131360#45131360

	//Exponential Search
	//int i = 1;
	//while (i < n && arr[i] <= x)
	//	i = i * 2;
	//return binarySearch(arr, i / 2, min(i, n), x);	

	//Fibonacci search - O(log n) - Golden ratio?
	//Search numbers in fibonacii indices and then linearly

	//The Ubiquitous binary search
	//Binary search with less comparisions
	//Prob : Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.
	//prob : Given a sorted array of distinct elements, and the array is rotated at an unknown position. Find minimum element in the array.

	getchar();
	return 0;
}
bool linearSearch(int *numbers,int size,int search) {
	for (auto i = 0; i < size; i++) {
		if (numbers[i] == search) {
			return true;
		}
	}
	return false;
}
bool iterativeBinarySearch(int *numbers, int start, int end, int search) {
	int middle;
	while (start <= end) {
		middle = start + (end - start) / 2;
		if (numbers[middle] == search) {
			return true;
		} else if (numbers[middle] > search) {
			end = middle - 1;
		} else {
			start = middle + 1;
		}
	}
	return false;
}
bool recursiveBinarySearch(int *numbers, int start, int end, int search) {
	if (start > end) {
		return false;
	}
	int middle = start + (end-start) / 2;
	
	if (numbers[middle] == search) {
		return true;
	} else if (numbers[middle] > search) {
		return recursiveBinarySearch(numbers, start, middle-1, search);
	} else {
		return recursiveBinarySearch(numbers, middle+1, end, search);
	}
}
