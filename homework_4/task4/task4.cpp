/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav
* @idnumber 7MI0600261
* @task 4
*
*/
#include <iostream>
using namespace std;
int fill(int a,int n){
    while(a!=n){
        a++;
    }
    return a;
}
int drain(){
    return 0;
}
void overflowFromOneToTwo(int &basinOne,int &basinTwo,int m){
        while(basinOne!=0 && basinTwo!=m) {
            basinOne--;
            basinTwo++;
        }
}
void overflowFromTwoToOne(int &basinTwo,int &basinOne,int m){
    while(basinTwo!=0 && basinOne!=m) {
        basinTwo--;
        basinOne++;
    }
}
int abs(int a, int b){
    if(a>b) return a-b;
    else return b-a;
}
int main() {
    int n,m,k;
    int basinOne=0;
    int basinTwo=0;
    int count=0;
    cin>>n;
    cin>>m;
    cin>>k;
    if(n<k && m<k){
        cout<<"-1";
    }
    else if(k% abs(n,m)!=0) {
        cout<<"-1";
    }
    else {
            if (n == k || m == k) {
                cout << "1";
            }
            else if (n > m) {
                while (basinOne != k) {
                    basinOne = fill(basinOne, n);
                    count++;
                    overflowFromOneToTwo(basinOne, basinTwo, m);
                    count++;
                    if (basinOne == k) {
                        cout << count;
                        break;
                    }
                    basinTwo = drain();
                    count++;
                    overflowFromOneToTwo(basinOne, basinTwo, m);
                    count++;
                }
            } else if (n < m) {
                while (basinTwo != k) {
                    basinTwo = fill(basinTwo, m);
                    count++;
                    overflowFromTwoToOne(basinTwo, basinOne, n);
                    count++;
                    if (basinTwo == k) {
                        cout << count;
                        break;
                    }
                    basinOne = drain();
                    count++;
                    overflowFromTwoToOne(basinTwo, basinOne, n);
                    count++;
                }
            }
        }
    return 0;
}
