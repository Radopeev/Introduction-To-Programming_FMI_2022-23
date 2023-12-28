/**
*
* Solution to homework assignment 3
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
int digitCounter(int a) {
    int count = 0;
    while(a != 0) {
        a = a / 10;
        count++;
    }
    return count;
}
int power(int power,int num){
    int result=1;
    for(int i=0;i<power;i++){
        result=result*num;
    }
    return result;
}
int proection(int (&a)[15],int n){
    int proection=0;
    for(int i=0;i<n;i++){
        proection+=a[i];
        proection*= power(digitCounter(a[i+1]),10);
    }
    return proection;
}
int reversed(int a){
    int reversed_number = 0, remainder;
    while(a != 0) {
        remainder = a % 10;
        reversed_number = reversed_number * 10 + remainder;
        a/= 10;
    }
    return reversed_number;
}
int numbersCompare(int a,int b){
    int result=1;
    int digit1,digit2,changedA=a,changedB=b;
    while(changedA!=0 || changedB!=0){
        digit1=changedA%10;
        digit2=changedB%10;
        if(digit1>digit2 || digit1==0) {
            result=1;break;
        }
        else if(digit2>digit1 || digit2==0) {
            result=2;break;
        }
        else {
            changedA/=10;
            changedB/=10;
            if(changedA==0 && changedB==0){
                result=3;
            }
        }
    }
    return result;
}
void comparison(int (&a)[15],int n){
    int swap;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++) {
            if(numbersCompare(reversed(a[i]), reversed(a[j]))==2) {
                swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
            else if(numbersCompare(reversed(a[i]), reversed(a[j]))==3) {
                if (a[i] > a[j]) {
                    swap = a[i];
                    a[i] = a[j];
                    a[j] = swap;
                }
            }
            else if(numbersCompare(reversed(a[i]), reversed(a[j]))==1){
                int proection1= proection(a,n);
                if (a[i] > a[j]) {
                    swap = a[i];
                    a[i] = a[j];
                    a[j] = swap;
                }
                int proection2=proection(a,n);
                if(proection1>proection2){
                    swap = a[i];
                    a[i] = a[j];
                    a[j] = swap;
                }
            }
        }
    }
}
int main() {
    int a[15]={0},n;
    bool flag= false;
    cin>>n;
    if(n<0 || n>15){
        cout<<"-1";
    }else {
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<1 || a[i]>9999){
                flag= true;
            }
        }
    }
    if(!flag) {
        comparison(a, n);
        for (int i = 0; i < n; i++) {
            cout << a[i]<<" ";
        }
    }else {
        cout << "-1";
    }
    return 0;
}
