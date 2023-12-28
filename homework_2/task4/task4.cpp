#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int gcd;
    for (int i=1;i<=a&&i<=b;i++) {
        if(a%i==0 && b%i == 0 ) {
            gcd=i;
        }
    }
    return gcd;
}
int isMagicNumber(unsigned int (&arr)[1024], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
            return 1;
        }
    }
    return result;
}
int main() {
    int n;
    unsigned int arr[1024];
    cin>>n;
    if(n>=2 && n<=1024){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isMagicNumber(arr,n)==1)cout<<1;
    else cout<<0;}
    else {
        cout<<"-1";
    }
    return 0;
}

