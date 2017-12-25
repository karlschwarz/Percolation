//---------------------------------------------------------------
//Copyright (c) 2017 Erdong Guo
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
#include <fstream>
#include "percolation.h"
#include "messagePassing.h"
#include "numExp.h"
#define N (200)
#define EMPTY (-N - 1)
using namespace std;

int **arr2D(int ROW, int COL) {
    int **arr2D = new int *[ROW];
    for (int i = 0; i < ROW; i++) {
        arr2D[i] = new int[COL];
    }
    return arr2D;
}

double **arr2Dd(int ROW, int COL) {
    double **arr2D = new double *[ROW];
    for (int i = 0; i < ROW; i++) {
        arr2D[i] = new double[COL];
    }
    return arr2D;
}

int *arr1D(int ROW) {
    int *arr1D = new int [ROW];
    return arr1D;
}

double *arr1Dd(int ROW) {
    double *arr1Dd = new double [ROW];
    return arr1Dd;
}

void del2D(int **arr2D, int ROW) {
    for (int i = 0; i < ROW; i++) {
        delete []arr2D[i];
    }
    delete []arr2D;
}

void del2D(double **arr2D, int ROW) {
    for (int i = 0; i < ROW; i++) {
        delete []arr2D[i];
    }
    delete []arr2D;
}

void del1D(int *arr1D) {
    delete []arr1D;
}

void del1D(double *arr1D) {
    delete []arr1D;
}
