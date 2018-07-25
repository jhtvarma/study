/*
	Length of Longest sub-string that can be removed
	Given a binary string (consists of only 0 and 1). 
	If there is “100” as a sub-string in the string, then we can delete this sub-string. 
	Input  : str = "1011100000100"
	Output : 6 -> 101{110000}0{100}
	https://www.geeksforgeeks.org/length-longest-sub-string-can-make-removed/
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int longestSubStringLength(string str);
int main() {
	
	cout << longestSubStringLength("1011100000100");
	
	getchar();

	return 0;
}

int longestSubStringLength(string str) {
	vector<pair<char, int>> arr;
	arr.push_back({ '@', -1 });
	
	int maxLength = 0;

	for (int i = 0; i < str.length(); i++) {
		arr.push_back({str[i], i});

		while (
			arr.size() >= 3 &&
			arr[arr.size() - 3].first == '1' &&
			arr[arr.size() - 2].first == '0' &&
			arr[arr.size() - 1].first == '0'
		) {

			arr.pop_back();
			arr.pop_back();
			arr.pop_back();
		}

		int tmp = arr.back().second;
		maxLength = max(maxLength, i - tmp);
	}

	return maxLength;
}