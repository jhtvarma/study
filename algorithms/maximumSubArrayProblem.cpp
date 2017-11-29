/*
	Maximum sub array problem
*/
#include<iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; };
int max(int a, int b, int c) { return max(max(a, b), c); };
int maxSubArrayRecursive(int input[], int n);
int maxSubArrayDNC(int input[], int l, int h);
int maxSubArrayDP(int intput[], int n);
int maxSubArrayDNCMid(int input[], int low, int middle, int high);
int main() {
	int input[] = { -2,1,-3,4,-1,2,1,-5,4 };//{-2, -5, 6, -2, -3, 1, 5, -6}
	int size = sizeof(input) / sizeof(input[0]);

	cout << "Recursive           : " << maxSubArrayRecursive(input,size) << endl;
	cout << "Divide and conquer  : " << maxSubArrayDNC(input, 0, size-1) << endl;
	cout << "Dynamic Programming : " << maxSubArrayDP(input, size) << endl;

	getchar();
	return 0;
}
int maxSubArrayRecursive(int input[], int n) {
	int i, j, sum = INT_MIN, maxSum = INT_MIN;
	for (i = 0; i < n; i++ ) {
		sum = 0;
		for (j = i; j < n; j++) {
			sum += input[j];
			if ( sum > maxSum ) {
				maxSum = sum;
			}
		}
	}

	return maxSum;
}
int maxSubArrayDNC(int input[], int low, int high) {
	if (low == high) {
		return input[low];
	}
	int middle = low + ((high - low) / 2);
	return max(
				maxSubArrayDNC(input, low, middle),
				maxSubArrayDNC(input, middle + 1, high),
				maxSubArrayDNCMid(input, low, middle, high)
			);
}
int maxSubArrayDNCMid(int input[], int low, int middle, int high) {
	int sum = 0, max_left = INT_MIN, max_right = INT_MIN;
	for (auto i = middle; i >= low; i-- ) {
		sum += input[i];
		if (sum > max_left) {
			max_left = sum;
		}
	}

	sum = 0;
	for (auto i = middle+1; i <= high; i++) {
		sum += input[i];
		if (sum > max_right) {
			max_right = sum;
		}
	}

	return max_left + max_right;
}
int maxSubArrayDP(int input[], int n) {
	int result = input[0], 
		curr_max = input[0];
	for (auto i = 1; i < n; i++) {
		curr_max = max(input[i], curr_max+input[i]);
		result = max(result, curr_max);
	}
	return result;
}