**Russell 3000 Earnings Research C++**

Aim: Event study in C++ on ~2,180 Russell 3000 Q2-2022 earnings releases, split into Beat / Meet / Miss by EPS surprise, measuring abnormal returns vs the Russell 3000 ETF (IWV)

Entry Point: MenuMain.cpp - Interactive menu: fetch prices for a +/-N day window (N = 60-80), view one stock, view group stats, plot CAAR
Quick summary on files:
ReadLoadData.cpp: Reads earnings CSV, downloads daily prices from EOD Historical Data API
Stocks.cpp: Per-stock returns, abnormal returns, cumulative returns
Group.cpp: Sorts stocks into Beat / Meet / Miss by surprise %
bootstrap.cpp: Bootstrap (40 runs x 80 stocks) for AAR, CAAR and their standard deviations, gnuplot chart
Matrix.cpp: Helpers for vectors
Russell3000EarningsAnnouncements.csv: Input data

needs g++, make, libcurl and gnuplot on Linux or WSL, plus your own EOD Historical Data API key in ReadLoadData.cpp
Result: Results.png; Beat stocks jump about 2 points on announcement day and end near +11% CAAR, vs about +7% for Meet and +3% for Miss
