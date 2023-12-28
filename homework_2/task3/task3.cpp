#include <iostream>
using namespace std;
int numOfOnes(int (&arr)[1000], int &j){
    int countOfOnes=0;
    int i=j;
    while(arr[i]==1){
        countOfOnes++;
        i++;
    }
    return countOfOnes;
}
int numOfTwo(int (&arr)[1000], int &j){
    int countOfTwos=0;
    int i=j;
    while(arr[i]==2){
        countOfTwos++;
        i++;
    }
    return countOfTwos;
}
int numOfThrees(int (&arr)[1000],int &j){
    int countOfThrees=0;
    int i=j;
    while(arr[i]==3){
        countOfThrees++;
        i++;

    }
    return countOfThrees;
}
int main() {
    int n;
    int arr[1000] = {1,1};
    int arr2[1000]={0};
    cin >> n;
    if(n==1){
        cout<<"1";
    }
    else if(n>1 && n<=20) {
        int k = 0;
        for (int i = 1; i < n - 1; i++) {
            int j = 0;
            while (arr[j] != 0) {
                if (arr[j] == 1) {
                    int oneCount = numOfOnes(arr, j);
                    arr2[k] = oneCount;
                    arr2[k + 1] = 1;
                    j += oneCount;
                } else if (arr[j] == 2) {
                    int twoCount = numOfTwo(arr, j);
                    arr2[k] = twoCount;
                    arr2[k + 1] = 2;
                    j += twoCount;
                } else if (arr[j] == 3) {
                    int threeCount = numOfThrees(arr, j);
                    arr2[k] = threeCount;
                    arr2[k + 1] = 3;
                    j += threeCount;
                }
                k += 2;
            }
            int p = 0;
            while (arr2[p] != 0) {
                arr[p] = arr2[p];
                p++;
            }
            k = 0;
        }
        int print = 0;
        while (arr2[print] != 0) {
            cout << arr[print];
            print++;
        }
    }
    else {
        cout<<"-1";
    }
}