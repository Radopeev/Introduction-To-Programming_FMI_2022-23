#include <iostream>
using namespace std;
int Task1(const int arr[], const unsigned size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
int Task2(const int arr[], const unsigned size){
    int sum=0;
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){
            sum+=arr[i];
        }
    }
    return sum;
}
int Task3(const int arr[], const unsigned size){
    int max=0;
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int Task4(const int arr[], const unsigned size){
    int max=0;
    for(int i=0;i<size;i++){
        if(arr[i]%2==1 && arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int Task5(const int arr[], const unsigned size) {
    unsigned i = 0;
    int smallest = 1;
    while (i < size) {
        if (arr[i] % 2 == 0) {
            smallest = arr[i];
            ++i;
            break;
        }
        ++i;
    }

    while (i < size) {
        if (arr[i] % 2 == 0 && arr[i] < smallest) {
            smallest = arr[i];
        }
        ++i;
    }
    return smallest;
}
int Task6(const int arr[], const unsigned size){
    int sum=0;
    for(int i=0;i<size-1;i++){
        if(arr[i]%2==0 & arr[i]>0){
            sum+=arr[i];
        }
    }
    return sum;
}
int Task7(const int arr[], const unsigned size){
    int max=arr[0];
    for(int i=0;i<size-1;i+=2){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int Task8(const int arr[], const unsigned size){
    int sum=0;
    for (int i = 1; i < size; i += 2) {
            sum += arr[i];
        }
    return sum;
}
int Task9(const int arr[], const unsigned size){
    int sum=0;
    sum=arr[0]+arr[size-1];
    return sum;
}
bool Task10(const int arr[], const unsigned size){
    for (int i = 0; i < size; i ++) {
        if(arr[i]==arr[i+1]){
            return true;
        }
    }
    return false;
}
void Task11(int arr[],const unsigned size){
    for(int i=0;i<size;i++){
        arr[i]=arr[i]*(-1);
    }
}
bool Task12(const int arr[],const unsigned size){
     int evenCount=0,oddCount=0;
     for(int i=0;i<size;i++){
         if(arr[i]%2==0){
             evenCount++;
         }else {
             oddCount++;
         }
     }
     if(evenCount>oddCount) return true;
     else return false;
}
bool Task13(const int arr[],const unsigned size){
    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
bool Task14(const int arr[],const unsigned size){
    for(int i=0;i<size;i++){
        if(arr[i]<arr[i+1]){
            return false;
        }
    }
    return true;
}
bool Task15(const int arr[], const unsigned size, const unsigned numb){
    for(int i=0;i<size;i++){
        if(arr[i]==numb){
            return true;
        }
    }
    return false;
}
unsigned Task16(const char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    return i++;
}
void Task17(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i]=='+'){
            arr[i]='-';
        }
        i++;
    }
}
bool Task18(const char arr[]) {
    bool U = false, P = false;
    for (unsigned i = 0; i < Task16(arr) && !(U && P);
         ++i) {
        if (arr[i] == 'U') {
            U = true;
        }

        else if (arr[i] == 'P') {
            P = true;
        }
    }

    return (U && P);
}
void Task19(char arr[]) {
    for (unsigned i = 0; i < Task16(arr); ++i) {
        if (arr[i] >= 65 &&
            arr[i] <= 90) {
            arr[i] += 32;
        }
    }
}
void Task20(char arr[]) {
    for (unsigned i = 0; i < Task16(arr); ++i) {
        if (arr[i] >= 97 && arr[i] <= 122) {
            arr[i] -= 32;
        }
        else if (arr[i] >= 65 && arr[i] <= 90) {
            arr[i] += 32;
        }
    }
    // swap cases
}
void Task21(const unsigned numb) {
    const int HH = numb / 3600;
    const int MM = (numb % 3600) / 60;
    if (HH < 10) {
        std::cout << '0';
    }

    std::cout << HH << ':';
    if (MM < 10) {
        std::cout << '0';
    }

    std::cout << MM;
    // receives seconds and turns them into HH:MM
}
void Task22(const unsigned numb){
    int n=numb,sum=0,i=0;
    while(n>0){
        sum+=numb%10;
        n/=10;
        i++;
    }
    return sum/i;
}
int main() {
    int arr[5]={4,4,8,3,-1};
    cout<<Task1(arr,5)<<endl;
    cout<<Task2(arr,5)<<endl;
    cout<<Task3(arr,5)<<endl;
    cout<<Task4(arr,5)<<endl;
    cout<<Task5(arr,5)<<endl;
    cout<<Task6(arr,5)<<endl;
    cout<<Task7(arr,5)<<endl;
    return 0;
}
