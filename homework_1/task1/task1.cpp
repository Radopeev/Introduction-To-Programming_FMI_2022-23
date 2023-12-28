/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 1
*
*/

#include <iostream>
using namespace std;
int main() {
    unsigned int num;
    int reversedNumber = 0, remainder, counter=0;
    cin>>num;
    if (num < 1000000) {
        while (Num != 0) {
            counter++;
            int firstNum = Num % 10;
            int firstNumToPower2 = firstNum*firstNum;
            while (firstNumToPower2 != 0) {
                remainder = firstNumToPower2 % 10;
                reversedNumber = reversedNumber * 10 + remainder;
                firstNumToPower2 /= 10;
            }
            Num /= 10;
        }
        cout<<reversedNumber+1;
    }
    else {
        cout<<"Incorrect input";
    }
    return 0;
}
