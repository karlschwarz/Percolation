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
#include <fstream>
#include "percolation.h"
#include "messagePassing.h"
#include "numExp.h"
#include "matrixGenerator.h"
#define N (200)
#define EMPTY (-N - 1)
using namespace std;

//std::default_random_engine random(time(NULL));
//std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
//std::exponential_distribution<double> expDistrb(1.0);

/*inline int **arr2D(int ROW, int COL) {
    int **arr2D = new int *[ROW];
    for (int i = 0; i < ROW; i++) {
        arr2D[i] = new int[COL];
    }
    return arr2D;
}

inline double **arr2Dd(int ROW, int COL) {
    double **arr2D = new double *[ROW];
    for (int i = 0; i < ROW; i++) {
        arr2D[i] = new double[COL];
    }
    return arr2D;
}

inline int *arr1D(int ROW) {
    int *arr1D = new int [ROW];
    return arr1D;
}

double *arr1Dd(int ROW) {
    double *arr1Dd = new double [ROW];
    return arr1Dd;
}

inline void del2D(int **arr2D, int ROW) {
    for (int i = 0; i < ROW; i++) {
        delete []arr2D[i];
    }
    delete []arr2D;
}

inline void del2D(double **arr2D, int ROW) {
    for (int i = 0; i < ROW; i++) {
        delete []arr2D[i];
    }
    delete []arr2D;
}

inline void del1D(int *arr1D) {
    delete []arr1D;
}

inline void del1D(double *arr1D) {
    delete []arr1D;
}*/

inline void vertices(int *ptr) {
    for (int i = 0; i < N; i++) {
        if (ptr[i] == -N - 1) {
            cout << setw(8) << "EMPTY";
        } else {
            cout << setw(8) << ptr[i];
        }
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

void printOut(double **p, int ARR, int COL) {
    for (int i = 0; i < ARR; i++) {
        for (int j = 0; j < COL; j++) {
            cout << setw(10) << p[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int *ptr;
    int *order;
    int **nn;
    double **H;
    double **probMtrx;
    int **A;
    //int **NB;
    double **TAP;
    int big;
    double S;
    double maxeig;
    double maxeignb;
    double maxeigtap;
    double thres = 0.001;
    double *eigvec;
    double *initvec;
    double *dif;
    /*double *eigvecnb;
    double *initvecnb;
    double *difnb;*/
    double *eigvectap;
    double *initvectap;
    double *diftap;
    int edges;
    double avedegrees;
    //double prob = 0.1;
//Here we initialize the networks by defining some parameters of the networks.
    ptr = arr1D(N);
    order = arr1D(N);
    nn = arr2D(N, N - 1);
//Here we initialize the probabilities the edges are occupied.
    probMtrx = arr2Dd(N, N);
    A = arr2D(N, N);
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(10) << probMtrx[i][j];
        }
        cout << endl;
    }
    cout << endl;*/
    //creatMtrx(N, probMtrx, prob);
    /*do {
        avedegrees = 2 * adjacentMtrx(probMtrx, A, N) / N;
        cout << avedegrees << endl;
    }while(avedegrees != 5);*/
    //edges = 2 * adjacentMtrx(probMtrx, A, N);
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;*/
    //cout << edges << endl;
//Here we abstract the information of the networks.
    //boundaries(nn, A, N);
    //permutation(order, N);
    /*for (int i = 0; i < N; i++) {
        cout << order[i] << endl;
    }*/
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(8) << nn[i][j];
        }
        cout << endl;
    }
    cout << endl;*/
//Here we simulate the percolation process and find out the biggest component.
    //big = percolate(ptr, order, nn, N);
    //cout << "The Largest Component Cluster's size is: " << setw(4) << big << '.' << endl;
//Here we find the prominent eigenvalue of the adjacent matrix.
    eigvec = arr1Dd(N);
    initvec = arr1Dd(N);
    initializeInitvec(N, eigvec);
    dif = arr1Dd(N);
    //maxeig = powerIteration(A, initvec, eigvec, dif, thres, N);
    //cout << "The average degrees calculated by adjacent matrix is " << maxeig << '.' << endl;
//Here we find the prominent eigenvalue of the Non-Backtracking matrix.
    //NB = arr2D(edges, edges);
    //creatNBMatrx(NB, nn, order, ptr, N, edges);
    /*for (int i = 0; i < edges; i++) {
        for (int j = 0; j < edges; j++) {
            cout << setw(8) << NB[i][j];
        }
        cout << endl;
    }*/
    /*eigvecnb = arr1Dd(edges);
    initvecnb = arr1Dd(edges);
    initializeInitvec(edges, eigvecnb);
    difnb = arr1Dd(edges); This period of code should be used if you want to do some tests*/
    //maxeignb = powerIteration(NB, initvecnb, eigvecnb, difnb, thres, edges);
    //cout << "The average degrees calculated by NB matrix is " << maxeignb << endl;
    //vertices(ptr);
//Here we find the prominent eigenvalue of the TAP matrix.
    TAP = arr2Dd(N, N);
    //creatTAPMatrx(TAP, nn, order, ptr, N, edges, probMtrx);
    eigvectap = arr1Dd(N);
    initvectap = arr1Dd(N);
    initializeInitvec(N, eigvectap);
    diftap = arr1Dd(N);
    numExp(probMtrx, A, nn, order, ptr, initvec, eigvec, dif, thres, TAP, initvectap, eigvectap, diftap);
    //maxeigtap = powerIteration(TAP, initvectap, eigvectap, diftap, thres, N);
    //cout << "The average degrees calculated by TAP matrix is" << maxeigtap << endl;
//Here we using the message passing algorithm to calculate the fraction of the networks percolated.
    //H = arr2Dd(N, N);
    //creatH(N, H, ptr);
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(15) << H[i][j];
        }
        cout << endl;
    }*/
    //int num_iter = 1000;
    /*for (int i = 0; i < num_iter; i++) {
        mesgePassing(order, ptr, H, nn, probMtrx, N);
    }
    S = percoFraction(N, H, nn, order);*/
   // cout << "The predicted LCC by message passing algorithm is " << S << endl;
    //printOut(H, N, N);

    del1D(ptr);
    del1D(order);
    del2D(nn, N);
    del2D(A, N);
    del2D(probMtrx, N);
    //del2D(NB, edges);
    del1D(eigvec);
    del1D(initvec);
    del1D(dif);
    /*del1D(initvecnb);
    del1D(eigvecnb);
    del1D(difnb);*/
    del2D(TAP, N);
    del1D(diftap);
    del1D(initvectap);
    del1D(eigvectap);
    //del2D(H, N);

    return 0;
}

