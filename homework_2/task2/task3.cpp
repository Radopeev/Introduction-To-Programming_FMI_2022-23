#include <iostream>
using namespace std;
const double epsilon=0.000001;
double whichIsGreater(double a, double b){
    if(a>b) return a-b;
    else return b-a;
}
bool doubleEquals(double left, double right, double e) {
    return (whichIsGreater(left,right) < e);
}
const double circleR=10.0;
const double mouthX1=-5.0;
const double mouthX2=5.0;
const double mouthY1=-4.0;
const double mouthY2=-6.0;
const double noseR=1.0;
const double eyeR=2.0;
const double eyeDiff=4.0;
double isInsideTheTarget(double a, double b,double& border){
    if(a>circleR || b>circleR) return 0;
    else if(doubleEquals(a,circleR,epsilon) || doubleEquals(b,circleR,epsilon)) return border=1;
    else return 1;
}
double isInsideMouth(double a,double b,double& border)
{
    if (a > mouthX1 && a < mouthX2 && b <mouthY1 && b > mouthY2) return 1;
    else if(doubleEquals(a,mouthX1,epsilon)  && (b <-4 && b > -6)) {
        return border=1;}
    else if (doubleEquals(a,mouthX2,epsilon) && (b < -4 && b > -6)) {
        return border = 1;}
    else if ((a > -5 && a < 5) && doubleEquals(b,mouthY1,epsilon) ) {
        return border = 1;}
    else if ((a > -5 && a < 5) && doubleEquals(b,mouthY2,epsilon)) {
        return border = 1; }
    return 0;
}
double isInsideNose(double a, double b,double& border)
{
    if (a * a+b * b < noseR * noseR) return 1;
    else if(doubleEquals(a * a+b * b,noseR,epsilon)) {
        return border=1;
    }else return 0;
}
double isInsideEye(double a,double b,double& border){
    if (((a-eyeDiff) * (a-eyeDiff)+(b-eyeDiff) * (b-eyeDiff) < eyeR * eyeR) ||((a+eyeDiff) * (a+eyeDiff)+(b+eyeDiff) * (b+eyeDiff) < eyeR * eyeR) ) return 1;
    else if((doubleEquals((a-4) * (a-4)+(b+4) * (b+4),eyeR,epsilon)) || (doubleEquals((a+4) * (a+4)+(b+4) * (b+4),eyeR,epsilon))){
        return border=1;
    }
    else return 0;
}
double isInsideCircle(double a,double b,double& border){
    if (a * a+b * b > circleR * circleR) return 0;
    else if(doubleEquals(a * a+b * b ,circleR,epsilon)){
        return border=1;
    }
    else return 1;
}

int main() {
    double a,b,border=0;
    cin>>a>>b;
    isInsideTheTarget(a,b,border);
    if(isInsideTheTarget(a,b,border)==1 && border!=1){
        if(isInsideCircle(a,b,border)==1 && border!=1){
            if(isInsideMouth(a,b,border)==1 && border!=1){
                cout<<"Mouth";
            }else if(isInsideEye(a,b,border)==1 && border!=1){
                cout<<"Eye";
            }else if(isInsideNose(a,b,border)==1&& border!=1){
                cout<<"Nose";
            }else if (border == 1)cout << "Border";
            else { cout << "Face"; }
        }else {
            cout<<"Background";
        }
    }else {
        cout<<"Miss";
    }

    return 0;
}
