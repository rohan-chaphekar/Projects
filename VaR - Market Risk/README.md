**VaR - Market Risk**

Aim: Compute VaR and Expected Shortfall in Python for a simulated $10MM five-stock portfolio (Historical, Parametric, Monte Carlo Student-t), then backtest and stress test

Entry Point: var_market_risk_analysis_project.ipynb - Single notebook, inputs in the Section 1 configuration cell
Quick summary on sections:
1. Configuration & Data: Portfolio, assumptions, simulated correlated prices
2. VaR & ES: Three methods at 95% and 99%
3. Backtesting: Rolling VaR, Kupiec test, Basel traffic-light zones
4. Stress Testing: 2008, COVID-2020, +100bp rate shock, correlation breakdown

needs Python with numpy, pandas, scipy, matplotlib and jupyter
Result: parametric VaR understates fat-tail risk; 6 breaches in 505 days at 99% (Kupiec p = 0.68, Basel Green); correlation breakdown raises 99% VaR by about 37%
