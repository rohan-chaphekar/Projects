#pragma once

#include "MCModel02.h"

namespace fre {
    class PathDepOption
    {
    protected:
        double Price;
        double T;
        double K;
        int m;
        Vector delta;
    public:
        PathDepOption(double T_, double K_, int m_, Vector delta_ ) : Price(0.0), T(T_), K(K_), m(m_), delta(delta_) {}       // delta expanding change 
        double PriceByMC(MCModel& Model, long N, double epsilon);              //delta change
        virtual ~PathDepOption() {}
        virtual double Payoff(const SamplePath& S) const = 0;
        Vector GetDelta() const { return delta;}                              // delta change
    };

    class ArthmAsianCall : public PathDepOption
    {
    public:
        ArthmAsianCall(double T_, double K_, int m_, Vector delta_) : PathDepOption(T_, K_, m_, delta_ ) {}
        double Payoff(const SamplePath& S) const;
    };
}

