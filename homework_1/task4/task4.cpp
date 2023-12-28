/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 4
*
*/

#include <iostream>
using namespace std;
bool checkIfRemarkable(int n){
    bool isRemarkable= true;
    while(n>0){
        int numUsedForChecking=n;
        int numBeingChecked=n%10;
        while(numUsedForChecking/10>0){
            numUsedForChecking/=10;
            if(numBeingChecked==numUsedForChecking%10){
                isRemarkable= false;
                break;
            }
        }
        if (!isRemarkable) break;
        n/=10;
    }
    return isRemarkable;
}
bool checkIfSimple(int n){
    bool isSimple = true;
    if (n == 0 || n == 1) {
        isSimple = false;
    }
    for (int i = 2; i <=n/2; ++i) {
        if (n % i == 0) {
            isSimple = false;
            break;
        }
    }
    return isSimple;
}
int abs(int n) {return n * ((n>0) - (n<0));}
int main() {
    int n;
    cin>>n;
    if(n>=1 && n<=1000000000) {
        if (checkIfRemarkable(n) && checkIfSimple(n)) {
            cout << n;
        } else {
            int distanceOfAscendingToN=0, distanceOfDescendingToN=0;
            int ascendingToN, descendingToN;
            for (int higherRemarkableNum = n + 1; higherRemarkableNum < 1000000000; higherRemarkableNum++) {
                if (checkIfRemarkable(higherRemarkableNum) && checkIfSimple(higherRemarkableNum)) {
                    distanceOfAscendingToN = higherRemarkableNum - n, ascendingToN = higherRemarkableNum;
                    break;
                } else {
                    continue;
                }
            }
            for (int lowerRemarkableNum = n - 1; lowerRemarkableNum >= 0; lowerRemarkableNum--) {
                if (checkIfRemarkable(lowerRemarkableNum) && checkIfSimple(lowerRemarkableNum)) {
                    distanceOfDescendingToN = lowerRemarkableNum - n, descendingToN = lowerRemarkableNum;
                    break;
                } else {
                    continue;
                }
            }
            if (abs(distanceOfAscendingToN) == abs(distanceOfDescendingToN)) {
                cout << descendingToN;
            } else {
                if (distanceOfAscendingToN > abs(distanceOfDescendingToN)) {
                    cout << descendingToN;
                } else {
                    cout << ascendingToN;
                }
            }
        }
    }
    else {
        cout<<"Incorrect input";
    }
    return 0;
}
