#include <iostream>
#include "PathDepOption02.h"

using namespace std;
using namespace fre;
int main()
{
    int d=3;
    Vector S0(d);
    S0[0]=40.0;
    S0[1]=60.0;
    S0[2]=100.0;
    double r=0.03;
    
    Vector delta(d);           // delta changes
    double epsilon = 0.001;    // delta changes

    Matrix C(d);
    for(int i=0;i<d;i++) C[i].resize(d);

    C[0][0] =  0.1;  C[0][1] = -0.1;  C[0][2] = 0.0;
    C[1][0] = -0.1;  C[1][1] =  0.2;  C[1][2] = 0.0;
    C[2][0] =  0.0;  C[2][1] =  0.0;  C[2][2] = 0.3;
    MCModel Model(S0,r,C);

   double T=1.0/12.0, K=200.0;
   int m=30;
   ArthmAsianCall Option(T,K,m,delta);  //expanding for delta

   long N=3000;
   
   cout << "Arithmetic Basket Call Price = " << Option.PriceByMC(Model, N, epsilon) << endl;
   
   delta = Option.GetDelta();   //delta changes
   for (int i = 0; i < d; i++)
   {
       cout<<"delta ["<<i<<"] : "<<delta[i]<<endl;
   }

   return 0;
}

/* 
rohanc:~/environment/fre6883_homework_assignment_12-rohan-chaphekar (main) $ ./HW12 
Arithmetic Basket Call Price = 2.21647
delta [0] : 0.509991
delta [1] : 0.516658
delta [2] : 0.532594

*/
