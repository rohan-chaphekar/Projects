**Asian Options**

Aim: Price Arithmetic Average Asian Call and Delta in C++ with plain Monte Carlo and Monte Carlo with a geometric Asian control variate

Entry Point: Main04.cpp - Sets up option and computes price, error and delta both ways (S0=100, K=100, r=3%, vol=20%, T=1 month, 30 fixings, 30,000 paths)
Quick summary on files:
MCModel.cpp: Price Path Simulator
PathDepOption.cpp: Pricer, plain Monte Carlo and control variate Monte Carlo, arithmetic Asian payoff
GmtrAsianCall.cpp: Geometric Asian payoff and closed-form price, used as the control variate
EurCall.cpp: Black-Scholes price, delta and vega

needs g++ and make on Linux, macOS or WSL
Result: price about 1.426, delta about 0.52; control variate cuts standard error from 0.012 to 0.00014 (about 87x)
