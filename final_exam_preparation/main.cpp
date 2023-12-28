#include <iostream>
using namespace std;
void task3(int n,int m, char symbol){
    for(int i=0;i<n;i++){
        cout<<" ";
        for(int j=0;j<m;j++){
            cout<<symbol;
        }
        cout<<endl;
    }
}
int task4(int (&arr)[10][10],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        int j=i;
        sum+=arr[i][j];
    }
    return sum;
}
void task5(int (&arr)[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
}
void revert(char (&arr2)[10]){
    int i=0;
    while(arr2[i]!='\0') {
        if (arr2[i] >= 'a' & arr2[i] <= 'z') {
            arr2[i] -= 32;
        } else if (arr2[i] >= 'A' & arr2[i] <= 'Z') {
            arr2[i] += 32;
        }
        i++;
    }
}
bool CheckDate(char (&arr3)[5]){
    bool flagOne=false,flagTwo=false,flagThree=false,flagFour= false,flagFive= false;
    if(arr3[0]>'0' & arr3[0]<'3'){
        flagOne= true;
    }
    if(arr3[1]>'0' & arr3[1]<'9') {
        flagTwo = true;
        if(arr3[0]=='3' & arr3[1]>'1'){
            flagTwo=false;
        }
    }
    if(arr3[2]=='.'){
        flagThree= true;
    }
    if(arr3[3]=='0' && (arr3[4]>'0' && arr3[4]<'9')){
        flagFour= true;
    }
    if(arr3[3]=='1' && arr3[4]>'2'){
        flagFive= true;
    }
    if(flagOne && flagTwo && flagThree && (flagFour || flagFive)){
        return true;
    }
    else {
        return false;
    }
}
int DigitPos(long num, int k){
    int arr[10],i=0;
    while(num!=0){
        arr[i]=num%10;
        num/=10;
        i++;
    }
    if(i-k<0){
        return -1;
    }
    int output=arr[i-k];
    return output;
}
bool doExist(char* symbols, char* word){
    bool flag= false;
    while(*symbols!='\0') {
        if (*symbols == *word) {
            flag = true;
            word++;
            if(*word=='\0'){
                break;
            }
        } else {
            flag = false;
        }
        symbols++;
    }
    return flag;
}
int main() {
    cout<<doExist("kopele","kip");
    return 0;
}
