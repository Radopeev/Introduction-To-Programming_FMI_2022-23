//Radoslav Peev 7MI0600261 variant 1
#include<iostream>
using namespace std;
int sumOfDigits(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	unsigned int p;
	cout << "p=";
	cin >> p;
	for (unsigned int i = 1; i < p; i++) {
		for (unsigned int j = 1; j < p; j++) {
			if (i == j + sumOfDigits(j)) cout << i << " ";
		}
	}
	return 0;
}