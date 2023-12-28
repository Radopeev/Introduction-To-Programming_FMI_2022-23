/**
*
* Solution to homework assignment 3
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
void crypt(char (&input)[1024], char (&encryptedInput)[1024],char key){
    int i=0;
    while(input[i]!='\0'){
        encryptedInput[i]=input[i]^key;
        i++;
    }
    int j=0;
    while(encryptedInput[j]!='\0'){
        cout<<encryptedInput[j];
        j++;
    }
}
int main() {
    char input[1024]={0},encryptedInput[1024],key;
    cin>>key;
    cin>>input;
    crypt(input,encryptedInput,key);
    return 0;
}
