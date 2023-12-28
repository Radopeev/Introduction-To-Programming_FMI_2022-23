/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav
* @idnumber 7MI0600261
* @task 2
*
*/
#include <iostream>
using namespace std;
void sort(char arr[255], int sz,char (&tempArray)[255],int &i)
{
    for (int k = 1; k < sz; k++)
    {
        for (int j = i; j < sz+i-k; j++)
        {
            if (arr[j] > arr[j+1])
            {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int k=0;
    for(int j=i;j<sz+i;j++){
        tempArray[k]=arr[j];
        k++;
    }
}
void sortW(char (&w)[255],int length){
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length-i; j++)
        {
            if (w[j] > w[j+1])
            {
                char temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;
            }
        }
    }
}
bool areEqual(const char a[],const char b[],int length){
    bool areEqual= true;
    for(int i=0;i<length;i++){
        if(a[i]!=b[i]) {
            areEqual = false;
        }
    }
    return areEqual;
}
void copy(char s[],const char sCopy[]){
    int j=0;
    while(sCopy[j]!='\0'){
        s[j]=sCopy[j];
        j++;
    }
}
int main() {
    char s[255],sCopy[255],w[255],tempArray[255];
    int i=0,j=0,length=0,indexes[20],index=0;
    bool areThereAnagrams=false;
    cin.getline(s,255);
    cin.getline(w,255);
    while(w[j]!='\0'){
        length++;
        j++;
    }
    j=0;
    while(s[j]!='\0'){
        sCopy[j]=s[j];
        j++;
    }
    j=0;
    sortW(w,length);
    while(s[i]!='\0'){
        while(w[j]!='\0') {
            if (s[i] == w[j]) {
                sort(s, length, tempArray,i);
                if (areEqual(w, tempArray, length)) {
                    indexes[index]=i;
                    areThereAnagrams= true;
                    index++;
                }
                copy(s,sCopy);
            }j++;
        }
        i++;
        j=0;
    }
    if(!areThereAnagrams){
        cout<<"\"no anagrams\"";
    }
    else{
        for(int k=0;k<index-1;k++){
            cout<<indexes[k]<<", ";
        }
        cout<<indexes[index-1];
    }
    return 0;
}
