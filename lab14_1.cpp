#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sumA=0,SDA=0,GM=1,HM=0,MaxA=A[0],MinA=A[0];
    for (int i = 0; i < N; i++)
    {
        sumA += A[i];
        GM *= A[i];
        HM += 1/A[i];
    }

    B[0] = sumA/N;
    B[2] = pow(GM,1.0/N);
    B[3] = N/HM;


    for (int i = 0; i < N; i++)
    {
        SDA += pow(A[i]-B[0],2.0) ;
    }
    SDA = sqrt(SDA/N);

    B[1] = SDA ;


    for (int i = 1; i < N; i++)
    {
        if (A[i] > MaxA)
            MaxA = A[i];

  
        if (A[i] < MinA)
            MinA = A[i];
    }

    B[4] = MaxA ;
    B[5] = MinA;    
}
