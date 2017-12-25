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
#include "matrixGenerator.h"
#define N (200)
#define EMPTY (-N - 1)
using namespace std;

void numExp(double **probMtrx, int **A, int **nn, int *order, int *ptr, double *initvec, double *eigvec, double *dif, double thres,
            double **TAP, double *initvectap, double *eigvectap, double *diftap) {
    double prob = 0.1;
    double maxeig;
    double maxeignb;
    double maxeigtap;
    int **NB;
    double *eigvecnb;
    double *initvecnb;
    double *difnb;
    int edges;
    double avedgs;


    ofstream foutavedg, foutadj, foutnb, fouttap, foutprob, foutcriprob;
    foutprob.open("prob.txt");
    foutavedg.open("avedgs.txt");
    foutadj.open("adjacent.txt");
    foutnb.open("nonbacktracking.txt");
    fouttap.open("tap.txt");
    foutcriprob.open("criprob.txt");

    do {
        creatMtrx(N, probMtrx, prob);
        edges = 2 * adjacentMtrx(probMtrx, A, N);
        avedgs = edges / N;
        boundaries(nn, A, N);
        permutation(order, N);
        NB = arr2D(edges, edges);
        eigvecnb = arr1Dd(edges);
        initvecnb = arr1Dd(edges);
        initializeInitvec(edges, eigvecnb);
        difnb = arr1Dd(edges);
        maxeig = powerIteration(A, initvec, eigvec, dif, thres, N);
        creatNBMatrx(NB, nn, order, ptr, N, edges);
        maxeignb = powerIteration(NB, initvecnb, eigvecnb, difnb, thres, edges);
        creatTAPMatrx(TAP, nn, order, ptr, N, edges, probMtrx);
        maxeigtap = powerIteration(TAP, initvectap, eigvectap, diftap, thres, N);
        foutavedg << avedgs << "\n";
        foutadj << 1 / maxeig << "\n";
        foutnb << 1 / maxeignb << "\n";
        fouttap << 1 / maxeigtap << "\n";
        foutprob << prob << "\n";
        foutcriprob << 1 / (avedgs - 1) << "\n";
        foutavedg << flush;
        foutadj << flush;
        foutnb << flush;
        fouttap << flush;
        foutprob << flush;
        foutcriprob << flush;
        del2D(NB, edges);
        del1D(initvecnb);
        del1D(eigvecnb);
        del1D(difnb);
        prob += 0.005;
    }while(prob < 1);
        foutavedg.close();
        foutadj.close();
        foutnb.close();
        fouttap.close();
        foutprob.close();
        foutcriprob.close();
}
