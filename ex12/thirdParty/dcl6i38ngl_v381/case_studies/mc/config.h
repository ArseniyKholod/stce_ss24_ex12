/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

const int N = 10;
const int M = 36;
//** for more realistic scenario use
// const int N=1000;     // number of MC paths
// const int M=360;      // number of Euler steps
const double S0 = 70.0; // asset
const double r = 0.07;  // interest
const double K = 40.0;  // strike
const double T = 1.0;   // maturity
