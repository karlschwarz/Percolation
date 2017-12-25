//---------------------------------------------------------------
//Copyright (C) 2017 Erdong Guo
//---------------------------------------------------------------
//===============================================================
//Erdong Guo - Created: 5th May 2017
//
//
//
//===============================================================
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#define N (100)
#define EMPTY (-N - 1)
using namespace std;

std::default_random_engine random(time(NULL));
std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
std::exponential_distribution<double> expDistrb(1.0);
