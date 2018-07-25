#include<iostream>
using namespace std;
int main() {
	
	char *str = "abcd";
	int n = strlen(str);

	subStr1(str);
	subStr2(str);

	//https://www.geeksforgeeks.org/count-substrings-with-same-first-and-last-characters/
	//n(n+1)/2 - total possible substrings
	//https://www.geeksforgeeks.org/recursive-solution-count-substrings-first-last-characters/

	getchar();
	return 0;
}
void subStr1(char *str) {
	int strLen = strlen(str);
	for (int i = 0; i < strLen; i++) {
		for (int j = i; j < strLen; j++) {
			for (int k = i; k <= j; k++) {
				cout << str[k];
			}
			cout << endl;
		}
		cout << endl;
	}//abc -> a,ab,abc,b,bc,c
}
void subStr2(char *str) {
	int strLen = strlen(str);
	for (int len = 1; len <= strLen; len++) {
		for (int i = 0; i <= strLen - len; i++) {
			for (int j = i; j <= i + len - 1; j++) {
				cout << str[j];
			}
			cout << endl;
		}
	}//abc -> a,b,c,ab,bc,abc
}