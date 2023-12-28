/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 3
*
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n>=2 && n<=9) {
        for(int linesToCenter=0;linesToCenter<(25 -( 2*n - 1)) / 2 ;++linesToCenter)
        {
            cout<<endl;
        }
        for (int nRows = 1; nRows <= n; nRows++) {
            for (int spacesToCenter = 0; spacesToCenter < (80 - (3 * n)) / 2; ++spacesToCenter) {
                cout << " ";
            }
            for (int numberFromOneToN = 1; numberFromOneToN <= nRows; numberFromOneToN++) {
                cout << numberFromOneToN;
            }
            if (nRows == n) {
                for (int firstNRows = 1; firstNRows <= n; firstNRows++) {
                    cout << "-";
                }
            } else {
                for (int leftToCenterSpaces = n + n; leftToCenterSpaces > nRows; leftToCenterSpaces--) {
                    cout << " ";
                }
                for (int centerToRightSpaces = n; centerToRightSpaces > nRows; centerToRightSpaces--) {
                    cout << " ";
                }
            }
            for (int numbersForNtoOne = nRows; numbersForNtoOne >= 1; numbersForNtoOne--) {
                cout << numbersForNtoOne;
            }
            cout << endl;
        }
        for (int secondNRows = n; secondNRows > 1; secondNRows--) {

            for (int spacesToCenter = 0; spacesToCenter < (80 - (3 * n)) / 2; spacesToCenter++) {
                cout << " ";
            }
            for (int numbersFromOneToN = 1; numbersFromOneToN < secondNRows; numbersFromOneToN++) {
                cout << numbersFromOneToN;
            }
            for (int leftToCenterSpaces = secondNRows; leftToCenterSpaces <= n; leftToCenterSpaces++) {
                cout << " ";
            }
            for (int centerToRightSpaces = secondNRows; centerToRightSpaces <= n + n; centerToRightSpaces++) {
                cout << " ";
            }
            for (int numbersFromNToOne = secondNRows - 1; numbersFromNToOne >= 1; numbersFromNToOne--) {
                cout << numbersFromNToOne;
            }
            cout << endl;
        }
        for(int linesToCenter=0;linesToCenter<(25 -( 2*n - 1)) / 2 ;++linesToCenter)
        {
            cout<<endl;
        }
    }
    else {
        cout<<"Incorrect input";
    }
    return 0;
}