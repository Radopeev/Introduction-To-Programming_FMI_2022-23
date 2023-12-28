/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Radoslav Peev
* @idnumber 7MI0600261
* @task 3
*
*/
#include <iostream>
using namespace std;
void convertingToNumberArriving(char (&arrivingFlights)[1024], int (&b)[1024])
{   int i=0,j=0;
    while(arrivingFlights[j]!='\0'){
        while(arrivingFlights[j]!=' ' && arrivingFlights[j]!='\0'){
            b[i]*=10;
            b[i]+=((int)arrivingFlights[j]-48);
            j++;
        }
        i++;
        j++;
    }
}
void convertingToNumberDeparting(char (&departingFlights)[1024], int (&c)[1024])
{   int i=0,j=0;
    while(departingFlights[j]!='\0'){
        while(departingFlights[j]!=' ' && departingFlights[j]!='\0'){
            c[i]*=10;
            c[i]+=((int)departingFlights[j]-48);
            j++;
        }
        i++;
        j++;
    }
}
int main() {
    int flights,minFlights=1,flightsAtTheSameTime=0,arrivingFlightsInInt[1024]={0},departingFlightsInInt[1024]={0},count=0;
    int latestArrivingTime=0,earliestDepartingTime=999999,latestArrivingTimeAtAll[100]={0},earliestDepartingTimeAtAll[100]={0};
    char arrivingFlights[1024];
    char departingFlights[1024];
    cin>>flights;
    cin.ignore();
    cin.getline(arrivingFlights,1024);
    cin.getline(departingFlights,1024);
    convertingToNumberArriving(arrivingFlights,arrivingFlightsInInt);
    convertingToNumberDeparting(departingFlights,departingFlightsInInt);
    for(int i=0;i<flights;i++){
       for(int j=i+1;j<flights;j++){
           if ((arrivingFlightsInInt[i]<=arrivingFlightsInInt[j] && departingFlightsInInt[i]>=departingFlightsInInt[j]) ||(departingFlightsInInt[i]>=arrivingFlightsInInt[j])){
                if(arrivingFlightsInInt[j]>latestArrivingTime && arrivingFlightsInInt[j]<earliestDepartingTime){
                    latestArrivingTimeAtAll[count]=arrivingFlightsInInt[j];
                    latestArrivingTime=arrivingFlightsInInt[j];
                }
                if(departingFlightsInInt[j]<earliestDepartingTime){
                    if(departingFlightsInInt[i]<=departingFlightsInInt[j]){
                        earliestDepartingTimeAtAll[count]=departingFlightsInInt[i];
                        earliestDepartingTime=departingFlightsInInt[i];
                    }
                    else {
                        earliestDepartingTimeAtAll[count]=departingFlightsInInt[j];
                        earliestDepartingTime=departingFlightsInInt[j];
                    }
                }
               flightsAtTheSameTime++;

           }
       }if(flightsAtTheSameTime>=minFlights){
            minFlights=flightsAtTheSameTime;
            flightsAtTheSameTime=0;
            latestArrivingTime=0;
            earliestDepartingTime=99999;
            count++;
        }else flightsAtTheSameTime=1;

    }
    cout<<minFlights<<endl;
    for(int i=0;i<count;i++){
        if(latestArrivingTimeAtAll[i]<1000 && earliestDepartingTimeAtAll[i]<1000){
            cout<<"0"<<latestArrivingTimeAtAll[i]<<"-"<<"0"<<earliestDepartingTimeAtAll[i]<<endl;
        }else if(earliestDepartingTimeAtAll[i]<1000){
            cout<<latestArrivingTimeAtAll[i]<<"-"<<"0"<<earliestDepartingTimeAtAll[i]<<endl;
        }else if(latestArrivingTimeAtAll[i]<1000){
            cout<<"0"<<latestArrivingTimeAtAll[i]<<"-"<<earliestDepartingTimeAtAll[i]<<endl;
        }else {
            cout<<latestArrivingTimeAtAll[i]<<"-"<<earliestDepartingTimeAtAll[i]<<endl;
        }

    }
    return 0;
}
