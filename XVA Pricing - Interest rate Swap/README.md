**XVA Pricing - Interest Rate Swap**

Aim: Compute CVA, DVA, FVA and MVA in Python for a $50MM 10-year semi-annual interest rate swap (payer and receiver), uncollateralized vs fully margined

Entry Point: XVA_for_a_swap_position_project.ipynb - Single notebook, swap and model inputs near the top
Quick summary on sections:
Rate model: Two-factor Gaussian short-rate model, weekly grid, Monte Carlo paths
Exposure: Expected Exposure profiles with and without margin (2-week MPOR, 99% initial margin)
XVA: CVA / DVA from default intensities (client 4%, bank 2.5%, 40% recovery), FVA from 1.5% funding spread, MVA from initial margin
Results table: All four charges for each swap type

needs Python with numpy, pandas, scipy, matplotlib and jupyter
Result: margining cuts CVA by over 99% (receiver swap: about $1.04MM to about $0.4K) while adding an MVA cost of about $1.7K
