**Basket Options**

Aim: Price Arithmetic Average Call, Delta on a three stock basket in C++ with Monte Carlo

Entry Point: Main05.cpp - Sets up basket and computes price and delta (S0 = 40/60/100, K=200, r=3%, T=1 month, 30 fixings, 3,000 paths, volatility matrix C)
Quick summary on files: 
MCModel02.cpp: Price Path Simulator
PathDepOption02.cpp: Pricer, averages basket value from each path, computes payoff
Matrix.cpp: Helpers for vectors

needs g++ and make on Linux, macOS or WSL
Result: basket call price about 2.22, with deltas of about 0.51, 0.52 and 0.53 for the three stocks.
