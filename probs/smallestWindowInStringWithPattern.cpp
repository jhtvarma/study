#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void findSubStr(string text, string pattern);
int main() {
	
	string text = "thisisateststring";
	string pattern = "tist";

	findSubStr(text, pattern);	

	getchar();
	return 0;
}
void findSubStr(string text, string pattern) {
	int *hash_text = new int[26],
		textLength = text.length(),
		*hash_pattern = new int[26],
		patternLength = pattern.length();

	int windowSize = INT_MAX,count = 0,start = 0,startIndex=0;
	fill(hash_pattern, hash_pattern + 26, 0);
	fill(hash_text, hash_text + 26, 0);

	//Fill the hashPattern with count of pattern text
	for (int i = 0; i < patternLength; i++) {
		hash_pattern[pattern[i] - 97]++;
	}

	//Iterate through text and check window size
	int i = 0, index, k;
	while (i < textLength) {
		index = text[i] - 97;
		//Increment count of each character in hash_text
		hash_text[index]++;
		//If character is present in pattern increment count
		if (hash_pattern[index] != 0 && hash_text[index] <= hash_pattern[index]) {
			count++;
		}

		if (count == patternLength) {
			//Move start if to avoid duplicates
			k = text[start] - 97;
			while (hash_text[k]>hash_pattern[k] || hash_pattern[k] == 0) {
				if (hash_text[k]>hash_pattern[k]) {	
					hash_text[k]--;
				}
				start++;
				k = text[start] - 97;
			}
			if (i-start+1 < windowSize) {
				windowSize = i - start + 1;
				startIndex = start;
			}
		}
		i++;
	}

	delete[] hash_pattern,hash_text;

	
	cout << startIndex << ":" << windowSize << endl;
	for (i = startIndex; i < windowSize+startIndex; i++) {
		cout << text[i];
	}

	cout << endl << "Completed";
}