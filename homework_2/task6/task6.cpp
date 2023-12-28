	#include <iostream>
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
int countDig(int n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count = count + 1;
    }
    return count;
}
bool isPalindromeArray(int (&arr)[20], int n)
{
    int flag = 0;
    for (int i = 0; i <= n / 2; i++) {
        if (arr[i] != arr[n - i - 1] || arr[i]==0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) return false;
    else return true;
}

bool isPalindrom(int a){
    int n=countDig(a);
    if(n>=3){
    if(a== reversed(a))return true;
    else return false;
    }else return 0;
}
void convertToArray(int a,int (&arr)[20]){
    int n= countDig(a);
    for(int i=n-1;i>=0 ;i--){
      arr[i]=a%10;
      a/=10;
    }
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int isHalfPalindrom(int a) {
    int arr[20];
    bool flag= false;
    int n=countDig(a);
    if(n>=3){
    convertToArray(a,arr);
    for(int i=0;i< n;i++){
        {
            swap(arr[i], arr[i + 1]);
            if (isPalindromeArray(arr, n)) flag= true;
            else {swap(arr[i], arr[i + 1]);}
        }
    }
    if(flag==true)return true;
    else return false;
    }else return 0;
}
int main() {
    int start, end, count = 0;
    cin >> start >> end;
    if (start <= end) {
        for (int i = start; i <= end; i++) {
            if (isPalindrom(i)) {
                count++;
            } else if (isHalfPalindrom(i)) {
                count++;
            }
        }
        cout << count;
    } else cout << -1;
}
