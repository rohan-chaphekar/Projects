#include <iostream>
#include "PathDepOption.h"
#include "GmtrAsianCall.h"

using namespace std;
using namespace fre;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    MCModel Model(S0,r,sigma);

    double T =1.0/12.0, K=100.0;
    int m=30;

    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);

    long N=30000;
    double epsilon =0.001;
    Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
    cout << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl 
        <<"Delta = "<<Option.GetDelta()<< endl;

    Option.PriceByMC(Model,N,epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl 
        <<"Delta = " << Option.GetDelta()<< endl;

    return 0;
}
/*
rohanc:~/environment/fre6883_homework_assignment_11-rohan-chaphekar (main) $ ./HW11 
Arithmetic call price = 1.42631
Error = 0.0001389
Delta = 0.520023
Price by direct MC = 1.44306
Error = 0.012078
Delta = 0.528945

// comments added to changes 
*/

