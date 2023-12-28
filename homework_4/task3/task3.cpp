/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav
* @idnumber 7MI0600261
* @task 3
*
*/
#include <iostream>
using namespace std;
int main() {
    char input[260], bracketsOnly[255]={0},temp=0;
    int leftBracketsCounter = 0, rightBracketsCounter = 0, i = 0, j = 0;
    bool isRight = false, isClosed = false;
    cin.getline(input, 255);
    while (input[i] != '\0') {
        if (input[i] == '(') {
            leftBracketsCounter++;
            bracketsOnly[j] = input[i];
            j++;
        } else if (input[i] == ')') {
            rightBracketsCounter++;
            bracketsOnly[j] = input[i];
            j++;
        }
        i++;
    }
    j = 0;
    while (bracketsOnly[j] != '\0') {
        if (temp==0 && bracketsOnly[i]=='(') {
            temp=bracketsOnly[j];
        } else if ( temp== '(' && bracketsOnly[j] == ')') {
            temp=0;
        }
        j++;
    }
    if (temp==0) {
        isClosed= true;
    }
    if (leftBracketsCounter == rightBracketsCounter) {
        isRight=true;
    }
    if(isClosed && isRight){
        cout<<"correct";
    }else {
        cout<<"incorrect";
    }
    return 0;
}
