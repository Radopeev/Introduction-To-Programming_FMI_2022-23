#include<iostream>
using namespace std;
int reversed(int a){
    int reversed_number = 0, remainder;
    while(a != 0) {
        remainder = a % 10;
        reversed_number = reversed_number * 10 + remainder;
        a/= 10;
    }
    return reversed_number;
}
int operationOne(int n){
    n= reversed(n);
    n/=10;
    n= reversed(n);
    return n;
}
int operationTwo(int n){
    return n/100;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void minimalOpearations(int n,int &min){
    int cannotBecomePrime= 0;
    int count=0;
    int changedN=n;
    while (changedN != 0) {
        if (isPrime(operationOne(changedN)) || isPrime(operationTwo(changedN))) {
            count++;
            break;
        }
        changedN = operationOne(changedN);
        if (changedN == 0) {
            min = -1;
            cannotBecomePrime= 1;
            break;
        }
        count++;
    }
    changedN=n;
    if(count<min){
        min=count;
        count=0;
    }
    while(changedN!=0){
        if(cannotBecomePrime){
            min=-1;
            break;
        }
        if (isPrime(operationOne(changedN)) || isPrime(operationTwo(changedN))) {
            count++;
            break;
        }
        changedN= operationTwo(n);
        count++;
    }
    if(count<min){
        min=count;
    }
}
int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<-2;
    }else {
        int min = 1000000;
        if (isPrime(n)) {
            cout << "0";
        } else {
            minimalOpearations(n, min);
            cout << min;
        }
    }
}
