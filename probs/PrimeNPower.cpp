#include<iostream>
using namespace std;
bool isPrime(int n);
unsigned long long power(int x, int y);
int main() {
	int a = 4;

	cout << isPrime(a);
	cout << power(5,15);
	getchar();
	return 0;
}
bool isPrime(int n) {
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i*i <= n; i = i + 6)
		if (n%i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
//log(n) -> 3**4 => 3*3*3*3 => 9*9 => 81
unsigned long long power(int x, int y) {
	unsigned long long res = 1;

	while (y > 0) {
		if (y & 1) {//odd
			res *= x;
		}

		y >>= 1;// y = y/2;
		x *= x;
	}

	return res;
}