/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 4
*
*/
#include <iostream>
using namespace std;
void insert(int (&binaryArray)[9999],int &indexOfBinaryArray,int &tempIndex){
    int diff=indexOfBinaryArray-tempIndex;
    while(indexOfBinaryArray%8!=0){
        for(int j= indexOfBinaryArray; j > diff; j--)
        { binaryArray[j] = binaryArray[j-1];}
        binaryArray[diff] = 0;
        diff++;
        indexOfBinaryArray++;
    }
}
void reverseA(int (&binaryArray)[9999],int &indexOfBinaryArray,int &tempIndex)
{
    int n=indexOfBinaryArray;
    for(int k=indexOfBinaryArray-tempIndex;k<n;k++)
    {
        int temp = binaryArray[k];
        binaryArray[k] = binaryArray[n-1];
        binaryArray[n-1] = temp;
        n--;
    }
}
void convertToBinary(int (&binaryArray)[9999],char (&input)[99999],int &indexOfBinaryArray,int &tempIndex) {
    int decimalNumber=0;
    int j=0;
    while(input[j]!='\0'){
        tempIndex=0;
        while (input[j]!=' ' && input[j]!='\0'){
            decimalNumber*=10;
            decimalNumber+=(int)input[j]-48;
            j++;
        }
        if(decimalNumber==0){
            indexOfBinaryArray++;
            while(indexOfBinaryArray%8!=0){
            binaryArray[indexOfBinaryArray]=0;
            indexOfBinaryArray++;
                }
        }else {
            while (decimalNumber != 0) {
                binaryArray[indexOfBinaryArray] = decimalNumber % 2;
                decimalNumber/= 2;
                indexOfBinaryArray++;
                tempIndex++;
            }
            reverseA(binaryArray, indexOfBinaryArray, tempIndex);
            if (indexOfBinaryArray % 8 != 0) {
                insert(binaryArray, indexOfBinaryArray, tempIndex);
            }
            j++;
        }
    }
}
void convertToDecimal(int (&binaryArray)[9999],int (&decimalArray)[1024],int &indexOfBinaryArray,int &indexOfDecimalArray){
    for(int j=0;j<indexOfBinaryArray;j+=3){
        decimalArray[indexOfDecimalArray]=binaryArray[j+2]*1+binaryArray[j+1]*2+binaryArray[j]*4;
        if(decimalArray[indexOfDecimalArray]==0 && decimalArray[indexOfDecimalArray-1]==0){
            break;
        }
        indexOfDecimalArray++;
    }
}
int main() {
    int n,binaryArray[9999]={0},indexOfBinaryArray=0,tempIndex,indexOfDecimalArray=0,counterOfPrintedSymbols=1,decimalArray[1024]={1},sumOfDecimalNumbers=0;
    cin>>n;
    cin.ignore();
    char input[99999];
    cin.getline(input,9999);
    convertToBinary(binaryArray,input,indexOfBinaryArray,tempIndex);
    convertToDecimal(binaryArray,decimalArray,indexOfBinaryArray,indexOfDecimalArray);
    for(int j=0;j<indexOfDecimalArray;j++){
        sumOfDecimalNumbers+=decimalArray[j];
    }
    if(sumOfDecimalNumbers%n!=0){
        cout<<"Invalid input";
    }else {
        for (int j = 0; j < indexOfDecimalArray; j++) {
                if (j % 2 == 0) {
                    for (int x=0; x <decimalArray[j];x++ , counterOfPrintedSymbols++) {
                        cout << ".";
                        if(counterOfPrintedSymbols%n==0) cout<<endl;
                    }
                } else {
                    for (int x=0; x < decimalArray[j];x++ , counterOfPrintedSymbols++) {
                        cout << "#";
                        if(counterOfPrintedSymbols%n==0) cout<<endl;
                    }
                }
        }
    }
    return 0;
}
