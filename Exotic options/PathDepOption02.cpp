#include "PathDepOption02.h"
#include <cmath>

namespace fre {
    
    void Rescale (SamplePath& S, Vector x)   // delta change rescale function
    {
        int m = S.size();
        for (int i = 0; i < m; i++)
            S[i] = S[i] * x;
    }
    
    
    double PathDepOption::PriceByMC(MCModel& Model, long N, double epsilon)
    {
        double H = 0.0;
        SamplePath S(m);
        
        int del = (int)delta.size();  //delta change 
        Vector Heps(del);

        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
            
            for (int j = 0; j < del; j++)                //delta change     
            {
                Vector vnew(del, 1);
                vnew[j] += epsilon;
                SamplePath Scopy = S;
                Rescale(Scopy, vnew);
                Heps[j] = (i * Heps[j] + Payoff(Scopy)) / (i + 1.0);
            }
            
            
        }
        Price = std::exp(-Model.GetR() * T) * H;
        delta = std::exp(-Model.GetR() * T) * (Heps - H) / (epsilon*Model.GetS0());   //delta change 
        return Price;
    }

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = S[0].size();
        Vector one(d);
        for (int i = 0; i < d; i++) one[i] = 1.0;
        for (int k = 0; k < m; k++)
        {
            Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
        }
        if (Ave < K) return 0.0;
        return Ave - K;
    }

}
