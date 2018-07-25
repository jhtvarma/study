#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findLCM(int *numbers, int size);
int main() {
	int numbers[] = { 2,4,8,15 },
		size = sizeof(numbers) / sizeof(numbers[0]);
	
	cout << findLCM(numbers, size);

	getchar();
	return 0;
}

int findLCM(int *numbers, int size) {
	int pivot = 2, k=0, res = 1;
	int maxNum = *max_element(numbers, numbers + size);

	vector<int> dividedIndices;

	while (k < maxNum) {
		for (int i = 0; i < size; i++) {
			if (numbers[i] % pivot == 0) {
				dividedIndices.push_back(i);
			}
		}

		if (dividedIndices.size() < 2) {
			pivot += 1;
		} else {
			for (int j = 0; j < dividedIndices.size(); j++) {
				numbers[dividedIndices[j]] /= pivot;
			}
			res *= pivot;
		}
		
		dividedIndices.clear();
		k++;
	}
	
	for (int i = 0; i<size; i++)
		res = res*numbers[i];
	return res;
}

//Other ways
int findLCM1(int a,int b) {
	return (a*b) / findGCD1(a, b);
}
int findGCD1(int a,int b) {
	if (a == 0) {
		return b;
	}
	return findGCD1(b%a, a);
}
int findGCD2(int a, int b) {
	if (a == b)
		return a;

	if (a > b)
		return findGCD2(a - b, b);
	else 
		return findGCD2(a, b - a);
}