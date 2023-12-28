/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav
* @idnumber 7MI0600261
* @task 1
*
*/
#include <iostream>
using namespace std;
int length(char (&a)[55][55],int row){
    int index=0;
    while(a[row][index]!='\0'){
        index++;
    }
    return index;
}
int lengthTwo(char (&cleanArrayTwo)[55][55],int row){
    int index=0;
    while(cleanArrayTwo[row][index]!='.' && cleanArrayTwo[row][index]!=',' && cleanArrayTwo[row][index]!='\0'){
        index++;
    }
    return index;
}
void swap(char (&cleanArrayTwo)[55][55],int indexOne,int indexTwo){
    int len1= length(cleanArrayTwo,indexOne),len2= length(cleanArrayTwo,indexTwo);
    if(len1>len2) {
        int swapIndex;
        for(swapIndex=0;swapIndex<len1;swapIndex++) {
        char swap;
        swap = cleanArrayTwo[indexTwo][swapIndex];
        cleanArrayTwo[indexTwo][swapIndex] = cleanArrayTwo[indexOne][swapIndex];
        cleanArrayTwo[indexOne][swapIndex] = swap;
        }
    }
    else {
        int swapIndex;
        for(swapIndex=0;swapIndex<len2;swapIndex++){
            char swap;
            swap = cleanArrayTwo[indexTwo][swapIndex];
            cleanArrayTwo[indexTwo][swapIndex] = cleanArrayTwo[indexOne][swapIndex];
            cleanArrayTwo[indexOne][swapIndex] = swap;
        }
    }
}
void sort(char (&cleanArrayTwo)[55][55],int rows){
    for(int i=0;i<rows-1;i++){
        for(int k=0;k<rows-i-1;k++) {
            int len1 = lengthTwo(cleanArrayTwo, k);
            int len2 = lengthTwo(cleanArrayTwo, k + 1);
            if (cleanArrayTwo[k][0] == '-' && cleanArrayTwo[k + 1][0] != '-') {
                break;
            } else if (cleanArrayTwo[k][0] != '-' && cleanArrayTwo[k + 1][0] == '-') {
                swap(cleanArrayTwo, k, k + 1);
            } else {
                if (len1 != len2) {
                    if (len1 > len2) {
                        swap(cleanArrayTwo, k, k + 1);
                        break;
                    }
                } else {
                    for (int j = 0; j < len1; j++) {
                        if (cleanArrayTwo[k][j] > cleanArrayTwo[k + 1][j] && cleanArrayTwo[k + 1][j] != '\0') {
                            swap(cleanArrayTwo, k, k + 1);
                        }
                    }
                }
            }
        }
    }
}
void deletingZerosBeforeDot(char (&cleanArray)[55][55],char (&a)[55][55],int rowsOfDoubleNumbers){
    bool zerosAreRemoved= false;
    for(int i=0;i<rowsOfDoubleNumbers;i++){
        int len= length(a,i);
        int index=0;
        if(a[i][0]=='0') {
            for (int j = 1; j <= len; j++) {
                if(!zerosAreRemoved) {
                    if (a[i][j] == '0' && a[i][j - 1] == '0') {
                        continue;
                    } else {
                        cleanArray[i][index]=a[i][j];
                        zerosAreRemoved = true;
                        index++;
                    }
                }
                else {
                    cleanArray[i][index]=a[i][j];
                    index++;
                }
            }
        }
        else {
            for (int j = 0; j <= len; j++) {
                    cleanArray[i][index]=a[i][j];
                    index++;
            }
        }
    }
}
void reverseArray(char (&cleanArrayTwo)[55][55],int row) {
    int start = 0;
    int end = lengthTwo(cleanArrayTwo,row)-1;
    while (start < end) {
        char temp = cleanArrayTwo[row][start];
        cleanArrayTwo[row][start] = cleanArrayTwo[row][end];
        cleanArrayTwo[row][end] = temp;
        start++;
        end--;
    }
}
void deletingZerosAfterDot(char (&cleanArrayTwo)[55][55],char (&cleanArray)[55][55],int rowsOfDoubleNumbers){
    bool zerosAreRemoved= false;
    for(int i=0;i<rowsOfDoubleNumbers;i++){
        int len= length(cleanArray,i);
        int index=0;
        if(cleanArray[i][len-1]=='0') {
            for (int j =len-2; j >= 0; j--) {
                if(!zerosAreRemoved) {
                    if (cleanArray[i][j] == '0' && cleanArray[i][j + 1] == '0') {
                        continue;
                    } else {
                        cleanArrayTwo[i][index]=cleanArray[i][j];
                        zerosAreRemoved = true;
                        index++;
                    }
                }
                else {
                    cleanArrayTwo[i][index]=cleanArray[i][j];
                    index++;
                }
            }
        }
        else {
            for (int j = 0; j <= len; j++) {
                cleanArrayTwo[i][index]=cleanArray[i][j];
                index++;
            }
        }
        if(zerosAreRemoved) {
            reverseArray(cleanArrayTwo, i);
        }
    }
}
int main() {
    int n,k=0,rowsOfDoubleNumbers=0,count=0;
    bool isDouble=false;
    cin>>n;
    char arr[55][55];
    char a[55][55]={0};
    char cleanArray[55][55]={0},cleanArrayTwo[55][55]={0};
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        while(arr[i][k]!='\0') {
            if (arr[i][k] == '.' || arr[i][k] == ',') {
                a[rowsOfDoubleNumbers][k] = arr[i][k];
                count++;
                isDouble= true;
            }
            else if(arr[i][k]>='0' && arr[i][k]<='9'){
                a[rowsOfDoubleNumbers][k]=arr[i][k];
                isDouble= true;
            }
            else if(arr[i][k]=='-'){
                a[rowsOfDoubleNumbers][k] = arr[i][k];
            }
            else {
                isDouble=false;
            }
            k++;
        }
        if(isDouble && count<2){
            rowsOfDoubleNumbers++;
            count=0;
        }
        k=0;
    }
    deletingZerosBeforeDot(cleanArray,a,rowsOfDoubleNumbers);
    deletingZerosAfterDot(cleanArrayTwo,a,rowsOfDoubleNumbers);
    sort(cleanArrayTwo,rowsOfDoubleNumbers);
    for(int i=0;i<rowsOfDoubleNumbers;i++){
        int j=0;
        while(cleanArrayTwo[i][j]!='\0') {
            cout << cleanArrayTwo[i][j];
            j++;
        }
        cout<<" ";
    }
    return 0;
}
