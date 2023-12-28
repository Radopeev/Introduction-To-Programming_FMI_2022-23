//Radoslav Peev
#include<iostream>
using namespace std;
int sumOfEvenNumbers(int arr[],int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}
	return sum;
}
int main() {
	int a[] = {5}, b[] = {2,4,6}, c[20], n;
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	cout << sumOfEvenNumbers(a, 1)<<endl;
	cout << sumOfEvenNumbers(b, 3) << endl;
	cout << sumOfEvenNumbers(c, n) << endl;
}