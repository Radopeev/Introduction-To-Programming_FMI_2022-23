#include <iostream>
using namespace std;
int checkWhichIsLonger(int n,int m){
    if(n>m) return n;
    else return m;
}
bool isCOnlyZeros(int (&c)[100],int n){
    bool isOnlyZeros= false;
    for(int i=0;i<n-1;i++){
        if(c[i]==0) {
            isOnlyZeros = true;
        }else {
            isOnlyZeros=false ;
        }
    }
    return isOnlyZeros;
}
bool isDOnlyZeros(int (&d)[100],int n){
    bool isOnlyZeros= false;
    for(int i=0;i<n-1;i++){
        if(d[i]==0) {
            isOnlyZeros = true;
        }else {
            isOnlyZeros= false;
        }
    }
    return isOnlyZeros;
}
int abs(int n) {return n * ((n>0) - (n<0));}
void reverseA(char (&a)[100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        char temp = a[i];
        a[i] = a[n-1];
        a[n-1] = temp;
        n--;
    }
}
void reverseB(char (&b)[100],int m)
{
    for(int i=0;i<m-1;i++)
    {
        char temp = b[i];
        b[i] = b[m-1];
        b[m-1] = temp;
        m--;
    }
}
void reverseC(int (&c)[100],int n){
    for(int i=0;i<n-1;i++)
    {
        int temp = c[i];
        c[i] = c[n-1];
        c[n-1] = temp;
        n--;
    }
}
void reverseD(int (&d)[100],int n){
    for(int i=0;i<n-1;i++)
    {
        int temp = d[i];
        d[i] = d[n-1];
        d[n-1] = temp;
        n--;
    }
}
void positiveNumbers(char (&a)[100],char (&b)[100],int n,int m) {
    int c[100] = {0}, d[100] = {0};
    int lengthOfResult = checkWhichIsLonger(n, m);
    if (a[0] == '-') {
        reverseA(a, n + 1);
    } else { reverseA(a, n); }
    if (b[0] == '-') {
        reverseB(b, m + 1);
    } else { reverseB(b, m); }
    if (a[n] != '-' && b[m] != '-') {
        for (int i = 0; i < lengthOfResult; i++) {
            if (b[i] != 0 && a[i] != 0) {
                c[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
            } else if (a[i] == 0) {
                c[i] += ((int) (b[i]) - 48);
            } else if (b[i] == 0) {
                c[i] += ((int) a[i] - 48);
            }
            if (c[i] > 9) {
                c[i] %= 10;
                c[i + 1]++;
            }
        }
        if (n >= m) {
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (a[i]) - 48) - ((int) (b[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] += ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] -= ((int) (d[i]) - 48);
                }
                if (d[i] < 0) {
                    if (n == m && a[lengthOfResult] == 0) break;
                    if (a[i] == 0) {
                        d[i] = abs(d[i]);
                    } else {
                        d[i] = 10 - abs(d[i]);
                        d[i + 1]--;
                    }
                }
            }
            if (c[lengthOfResult] != 0) {
                reverseC(c, lengthOfResult + 1);
                for (int i = 0; i <= lengthOfResult; i++) {
                    cout << c[i];
                }
            } else {
                reverseC(c, lengthOfResult);
                for (int i = 0; i < lengthOfResult; i++) {
                    cout << c[i];
                }
            }
            if (d[lengthOfResult] == 0) {
                reverseD(d, lengthOfResult);
            } else {
                reverseD(d, lengthOfResult + 1);
            }
            cout << endl;
            if (isDOnlyZeros(d, lengthOfResult)) {
                cout << "0";
            } else {
                if (d[0] == 0) {
                    for (int i = 1; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
                } else
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
            }
        } else if (n < m) {
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (b[i]) - 48) - ((int) (a[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] -= ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] += ((int) (b[i]) - 48);
                }
                if (d[i] < 0) {
                    if (b[i] == 0) {
                        d[i] = abs(d[i]);
                    } else {
                        d[i] = 10 - abs(d[i]);
                        d[i + 1]--;
                    }
                }
            }
            reverseC(c, lengthOfResult);
            reverseD(d, lengthOfResult);
            if (isCOnlyZeros(c, lengthOfResult)) {
                cout << "0";
            } else {
                for (int i = 0; i <= lengthOfResult - 1; i++) {
                    cout << c[i];
                }
            }
            cout << endl;
            if (isDOnlyZeros(d, lengthOfResult)) {
                cout << "0";
            } else {
                cout << "-";
                if (d[0] == 0) {
                    for (int i = 1; i <= lengthOfResult - 1; i++) {
                        cout << d[i];
                    }
                } else
                    for (int i = 0; i <= lengthOfResult - 1; i++) {
                        cout << d[i];
                    }
            }
        }
    } else if (a[n] == '-' && b[m] != '-') {
        if (n >= m) {
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    c[i] += ((int) (a[i]) - 48) - ((int) (b[i]) - 48);
                } else if (b[i] == 0) {
                    c[i] += ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    c[i] -= ((int) (b[i]) - 48);
                }
                if (c[i] < 0) {
                    if (n == m && a[lengthOfResult] == 0) break;
                    if (a[i] == 0) {
                        c[i] = abs(c[i]);
                    } else {
                        c[i] = 10 - abs(c[i]);
                        c[i + 1]--;
                    }
                }
            }
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] += ((int) (b[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] += ((int) a[i] - 48);
                }
                if (d[i] > 9) {
                    d[i] %= 10;
                    d[i + 1] += 1;
                }
            }
            if (c[lengthOfResult] == 0) {
                reverseC(c, lengthOfResult);
            } else {
                reverseC(c, lengthOfResult + 1);
            }
            if (isCOnlyZeros(c, lengthOfResult)) {
                cout << "0";
            } else {
                cout << "-";
                if (c[0] == 0) {
                    for (int i = 1; i < lengthOfResult; i++) {
                        cout << c[i];
                    }
                } else
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << c[i];
                    }
            }
            cout << endl;
            if (d[lengthOfResult] != 0) {
                reverseD(d, lengthOfResult + 1);
                cout << "-";
                for (int i = 0; i <= lengthOfResult; i++) {
                    cout << d[i];
                }
            } else {
                reverseD(d, lengthOfResult);
                cout << "-";
                for (int i = 0; i < lengthOfResult; i++) {
                    cout << d[i];
                }
            }

        } else if (n < m) {
            a[n] = 0;
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    c[i] += ((int) (b[i]) - 48) - ((int) (a[i]) - 48);
                } else if (b[i] == 0) {
                    c[i] -= ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    c[i] += ((int) (b[i]) - 48);
                }
                if (c[i] < 0) {
                    if (n == m && a[lengthOfResult] == 0) break;
                    if (b[i] == 0) {
                        c[i] = abs(c[i]);
                    } else {
                        c[i] = 10 - abs(c[i]);
                        c[i + 1]--;
                    }
                }
            }
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] += ((int) (b[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] += ((int) a[i] - 48);
                }
                if (d[i] > 9) {
                    d[i] %= 10;
                    d[i + 1]++;
                }
            }
            if (c[lengthOfResult] == 0) {
                reverseC(c, lengthOfResult);
            } else {
                reverseC(c, lengthOfResult + 1);
            }

            if (isCOnlyZeros(c, lengthOfResult)) {
                cout << "0";
            } else {
                if (c[0] == 0) {
                    for (int i = 1; i < lengthOfResult; i++) {
                        cout << c[i];
                    }
                } else
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << c[i];
                    }
            }
        }
        cout << endl;
            if (d[lengthOfResult] != 0) {
                reverseD(d, lengthOfResult + 1);
                for (int i = 0; i <= lengthOfResult; i++) {
                    cout << d[i];
                }
            } else {
                reverseD(d, lengthOfResult);
                for (int i = 0; i < lengthOfResult; i++) {
                    cout << d[i];
                }
            }

        } else if (b[m] == '-' && a[n] != '-') {
            if (n >= m) {
                b[m] = 0;
                for (int i = 0; i < lengthOfResult; i++) {
                    if (b[i] != 0 && a[i] != 0) {
                        c[i] += ((int) (a[i]) - 48) - ((int) (b[i]) - 48);
                    } else if (b[i] == 0) {
                        c[i] += ((int) (a[i]) - 48);
                    } else if (a[i] == 0) {
                        c[i] -= ((int) (b[i]) - 48);
                    }
                    if (c[i] < 0) {
                        if (n == m && a[lengthOfResult] == 0) break;
                        if (a[i] == 0) {
                            c[i] = abs(c[i]);
                        } else {
                            c[i] = 10 - abs(c[i]);
                            c[i + 1]--;
                        }
                    }
                }
                for (int i = 0; i < lengthOfResult; i++) {
                    if (b[i] != 0 && a[i] != 0) {
                        d[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
                    } else if (a[i] == 0) {
                        d[i] += ((int) (b[i]) - 48);
                    } else if (b[i] == 0) {
                        d[i] = ((int) a[i] - 48);
                    }
                    if (d[i] > 9) {
                        d[i] %= 10;
                        d[i + 1]++;
                    }
                }
                if (c[lengthOfResult] == 0) {
                    reverseC(c, lengthOfResult);
                } else {
                    reverseC(c, lengthOfResult + 1);
                }
                if (isCOnlyZeros(c, lengthOfResult)) {
                    cout << "0";
                } else {
                    if (c[0] == 0) {
                        for (int i = 1; i < lengthOfResult; i++) {
                            cout << c[i];
                        }
                    } else
                        for (int i = 0; i < lengthOfResult; i++) {
                            cout << c[i];
                        }
                }
                cout<<endl;
                if (d[lengthOfResult] != 0) {
                    reverseD(d, lengthOfResult + 1);
                    for (int i = 0; i <= lengthOfResult; i++) {
                        cout << d[i];
                    }
                } else {
                    reverseD(d, lengthOfResult);
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
                }

            } else if (n < m) {
                for (int i = 0; i < lengthOfResult - 1; i++) {
                    if (b[i] != 0 && a[i] != 0) {
                        c[i] += ((int) (b[i]) - 48) - ((int) (a[i]) - 48);
                    } else if (b[i] == 0) {
                        c[i] -= ((int) (a[i]) - 48);
                    } else if (a[i] == 0) {
                        c[i] += ((int) (b[i]) - 48);
                    }
                    if (c[i] < 0) {
                        if (a[i] != 0) {
                            c[i] = abs(c[i]);
                        } else {
                            c[i] = 10 - abs(c[i]);
                            c[i + 1]--;
                        }
                    }
                }
                for (int i = 0; i < lengthOfResult - 1; i++) {
                    if (b[i] != 0 && a[i] != 0) {
                        d[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
                    } else if (a[i] == 0) {
                        d[i] += ((int) (b[i]) - 48);
                    } else if (b[i] == 0) {
                        d[i] += ((int) a[i] - 48);
                    }
                    if (d[i] > 9) {
                        d[i] %= 10;
                        d[i + 1]++;
                    }
                }
                if (c[lengthOfResult] == 0) {
                    reverseC(c, lengthOfResult);
                } else {
                    reverseC(c, lengthOfResult + 1);
                }
                if (isCOnlyZeros(c, lengthOfResult)) {
                    cout << "0";
                } else {
                    if (c[0] == 0) {
                        for (int i = 1; i < lengthOfResult; i++) {
                            cout << c[i];
                        }
                    } else
                        for (int i = 0; i < lengthOfResult; i++) {
                            cout << c[i];
                        }
                }
                cout<<endl;
                if (d[lengthOfResult] != 0) {
                    reverseD(d, lengthOfResult + 1);
                    for (int i = 0; i <= lengthOfResult; i++) {
                        cout << d[i];
                    }
                } else {
                    reverseD(d, lengthOfResult);
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
                }
        } else if (a[n] == '-' && b[m] == '-') {
            a[n] = 0;
            b[m] = 0;
        for (int i = 0; i < lengthOfResult; i++) {
            if (b[i] != 0 && a[i] != 0) {
                c[i] += ((int) (a[i]) - 48) + ((int) (b[i]) - 48);
            } else if (a[i] == 0) {
                c[i] += ((int) (b[i]) - 48);
            } else if (b[i] == 0) {
                c[i] += ((int) a[i] - 48);
            }
            if (c[i] > 9) {
                c[i] %= 10;
                c[i + 1]++;
            }
        }
        if (n >= m) {
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (a[i]) - 48) - ((int) (b[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] += ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] -= ((int) (d[i]) - 48);
                }
                if (d[i] < 0) {
                    if (n == m && a[lengthOfResult] == 0) break;
                    if (a[i] == 0) {
                        d[i] = abs(d[i]);
                    } else {
                        d[i] = 10 - abs(d[i]);
                        d[i + 1]--;
                    }
                }
            }
            if (c[lengthOfResult] != 0) {
                reverseC(c, lengthOfResult + 1);
                cout<<"-";
                for (int i = 0; i <= lengthOfResult; i++) {
                    cout << c[i];
                }
            } else {
                reverseC(c, lengthOfResult);
                cout<<"-";
                for (int i = 0; i < lengthOfResult; i++) {
                    cout << c[i];
                }
            }
            if (d[lengthOfResult] == 0) {
                reverseD(d, lengthOfResult);
            } else {
                reverseD(d, lengthOfResult + 1);
            }
            cout << endl;
            if (isDOnlyZeros(d, lengthOfResult)) {
                cout << "0";
            } else {
                cout<<"-";
                if (d[0] == 0) {
                    for (int i = 1; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
                } else
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
            }
        } else if (n < m) {
            for (int i = 0; i < lengthOfResult; i++) {
                if (b[i] != 0 && a[i] != 0) {
                    d[i] += ((int) (b[i]) - 48) - ((int) (a[i]) - 48);
                } else if (b[i] == 0) {
                    d[i] -= ((int) (a[i]) - 48);
                } else if (a[i] == 0) {
                    d[i] += ((int) (b[i]) - 48);
                }
                if (d[i] < 0) {
                    if (b[i] == 0) {
                        d[i] = abs(d[i]);
                    } else {
                        d[i] = 10 - abs(d[i]);
                        d[i + 1]--;
                    }
                }
            }
            if (c[lengthOfResult] != 0) {
                reverseC(c, lengthOfResult + 1);
                cout << "-";
                for (int i = 0; i <= lengthOfResult; i++) {
                    cout << c[i];
                }
            } else {
                reverseC(c, lengthOfResult);
                cout << "-";
                for (int i = 0; i < lengthOfResult; i++) {
                    cout << c[i];
                }
            }
            if (d[lengthOfResult] == 0) {
                reverseD(d, lengthOfResult);
            } else {
                reverseD(d, lengthOfResult + 1);
            }
            cout << endl;
            if (isDOnlyZeros(d, lengthOfResult)) {
                cout << "0";
            } else {
                cout << "-";
                if (d[0] == 0) {
                    for (int i = 1; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
                } else
                    for (int i = 0; i < lengthOfResult; i++) {
                        cout << d[i];
                    }
            }
        }
        }
    }
}
int main() {
    int n, m;
    char a[100] = {0}, b[100] = {0};
    cin >> n;
    cin >> a;
    cin >> m;
    cin >> b;
    positiveNumbers(a, b, n, m);
}
