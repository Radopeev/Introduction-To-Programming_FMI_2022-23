/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 2
*
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>1 && n<2000) {
        while (n!= 0) {
            if (n >= 1000) {
                for (int i = 0; i < n / 1000; i++) {
                    cout << "M";
                }
                n -= 1000;
            } else if (n == 900) {
                cout << "CM";
                n -= 900;
            } else if (n >= 500) {
                cout << "D";
                n -= 500;
            } else if (n == 400) {
                cout << "CD";
                n -= 400;
            } else if (n >= 100) {
                for (int i = 0; i < n / 100; i++) {
                    cout << "C";
                    n -= 100;
                }
            } else if (n == 90) {
                cout << "LC";
                n -= 90;
            } else if (n >= 50) {
                cout << "L";
                n -= 50;
            } else if (n == 40) {
                cout << "XL";
                n -= 40;
            } else if (n >= 10) {
                for (int i = 0; i < n / 10; i++) {
                    cout << "X";
                    n -= 10;
                }
            } else if (n == 9) {
                cout << "IX";
                n -= 9;
            } else if (n >= 5) {
                cout << "V";
                n -= 5;
            } else if (n == 4) {
                cout << "IV";
                n -= 4;
            } else if (n >= 1) {
                for (int i = 0; i < n; i++) {
                    cout << "I";
                    n -= 1;
                }
            }
        }
    }
    else {
        cout<<"Incorrect input";
    }
    return 0;
}