#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Defint 
{
    private: 
    int a, b;
    double (*f) (double x);
    
    public:
    
    Defint (int my_a, int my_b, double (*my_f)(double x))
    {
        a = my_a;
        b = my_b;
        f = my_f;
    }
    
    double ByTrapezoid(int n);
    double BySimpson(int n);
};

double Defint::ByTrapezoid (int n)
{
    double h = double((b - a))/double(n);
    double counter = f(a) + f(b);
    
    for (int i = 1; i < n; i++)
    {
        double temp = 2*f(a+i*h);
        counter+=temp;
    }
    counter = counter * h/2;
    return counter;
}

double Defint::BySimpson (int n)
{
    double h = double((b - a))/double(n);
    
    double counter = f(a) + f(b);
    
    for (int i = 1; i < n; i++)
    {
        double temp = a+i*h;
        
        if(i%2 == 0)
            counter += 2*f(temp);
        else 
            counter += 4*f(temp);
    }
    counter = counter *h/3;
    return counter;  
}

double valfun(double x)
{
    return pow(x,3) - pow(x,2) + 1;
}

int main ()
{
    int a, b, n;
    cout<<"Enter value for lower limit, upper limit and n: "<<endl;
    cin>>a>>b>>n;
    
    Defint MyInt(a,b,valfun);
    cout<<"definite integral of given function x^3 - x^2 + 1 \n";
    cout<<"Integral value for Trapezoidal method: "<<MyInt.ByTrapezoid(n)<<endl;
    cout<<"Integral value for Simpson method: "<<MyInt.BySimpson(n)<<endl;
    
    return 0;
}
/*

Output:
Running /home/ec2-user/environment/fre6883_homework_assignment_3-rohan-chaphekar/assignment3_rohan.cpp
Enter value for lower limit, upper limit and n: 
1
2
100
definite integral of given function x^3 - x^2 + 1 
Integral value for Trapezoidal method: 2.41673
Integral value for Simpson method: 2.41667

*/