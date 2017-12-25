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
#include "percolation.h"
#define N (200)
#define EMPTY (-N - 1)
using namespace std;

//std::default_random_engine random(time(NULL));
//std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);

void initializeInitvec(int edges, double *initvec) {
    std::default_random_engine random(time(NULL));
    std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
    for (int i = 0; i < edges; i++) {
        initvec[i] = uniDistrb(random);
    }
}

double powerMethod(int **A, double *initvec, double *eigvec, int NN) {
    double maxeig = 0;
    for (int i = 0; i < NN; i++) {
        double sum = 0;
        for (int j = 0; j < NN; j++) {
            sum += (A[i][j] * initvec[j]);
        }
        eigvec[i] = sum;
        if (fabs(sum) > maxeig) {
            maxeig = fabs(sum);
        }
    }
    //cout << norm << endl;
    for (int i = 0; i < NN; i++) {
        eigvec[i] /= maxeig;
    }
    return maxeig;
}

double powerMethod(double **A, double *initvec, double *eigvec, int NN) {
    double maxeig = 0;
    for (int i = 0; i < NN; i++) {
        double sum = 0;
        for (int j = 0; j < NN; j++) {
            sum += (A[i][j] * initvec[j]);
        }
        eigvec[i] = sum;
        if (fabs(sum) > maxeig) {
            maxeig = fabs(sum);
        }
    }
    //cout << norm << endl;
    for (int i = 0; i < NN; i++) {
        eigvec[i] /= maxeig;
    }
    return maxeig;
}

double powerIteration(int **A, double *initvec, double *eigvec, double *dif, double thres, int NN) {
    double maxcpt = 0;
    double maxeig;
    do {
            maxcpt = 0;
            maxeig = powerMethod(A, initvec, eigvec, NN);
            //cout << maxeig << endl;
            for (int i = 0; i < NN; i++) {
                dif[i] = fabs(fabs(eigvec[i]) - fabs(initvec[i]));
                //cout << fabs(dif[i]) << endl;
                if (dif[i] > maxcpt) {
                    maxcpt = dif[i];
                }
                initvec[i] = eigvec[i];
            }
    } while (maxcpt > thres);
    return maxeig;
}

double powerIteration(double **A, double *initvec, double *eigvec, double *dif, double thres, int NN) {
    double maxcpt = 0;
    double maxeig;
    do {
            maxcpt = 0;
            maxeig = powerMethod(A, initvec, eigvec, NN);
            //cout << maxeig << endl;
            for (int i = 0; i < NN; i++) {
                dif[i] = fabs(fabs(eigvec[i]) - fabs(initvec[i]));
                //cout << fabs(dif[i]) << endl;
                if (dif[i] > maxcpt) {
                    maxcpt = dif[i];
                }
                initvec[i] = eigvec[i];
            }
    } while (maxcpt > thres);
    return maxeig;
}

void mesgePassing(int *order, int *ptr, double **H, int **nn, double **probMtrx, int NN) {
    for (int i = 0; i < NN; i++) {
            int s1 = order[i];
            int r1 = ptr[i];
            if (r1 != EMPTY) {
                for (int j = 0; j < NN - 1; j++) {
                    int s2 = nn[s1][j];
                    if (s2 != EMPTY) {
                    int r2 = ptr[s2];
                    if (r2 != EMPTY) {
                        double prod = 1;
                        for (int k = 0; k < NN - 1; k++) {
                            int s3 = nn[s2][k];
                            if (s3 != EMPTY) {
                            int r3 = ptr[s3];
                            if (r3 != EMPTY && s3 != s1) {
                                prod *= H[s2][s3];
                            }
                        }
                        }
                    //cout << prod << endl;
                    H[s1][s2] = 1 - probMtrx[s1][s2] + probMtrx[s1][s2] * prod;
                    //cout << probMtrx[s1][s2] << endl;
                    }
                    }
                }
            }
    }
}

/*inline void mesgePassing(int *order, int *ptr, double **H, int **nn, double **probMtrx, int NN) {
    for (int i = 0; i < NN; i++) {
            int s1 = order[i];
            int r1 = ptr[i];
            if (r1 != EMPTY) {
                for (int j = 0; j < NN - 1; j++) {
                    int s2 = nn[s1][j];
                    if (s2 != EMPTY) {
                    int r2 = ptr[s2];
                    if (r2 != EMPTY) {
                        double prod = 1;
                        for (int k = 0; k < NN - 1; k++) {
                            int s3 = nn[s2][k];
                            if (s3 != EMPTY) {
                            int r3 = ptr[s3];
                            if (r3 != EMPTY && s3 != s1) {
                                prod *= (1 - probMtrx[s2][s3] + probMtrx[s2][s3] * H[s2][s3]);
                            }
                        }
                        }
                    //cout << prod << endl;
                    H[s1][s2] = prod;
                    }
                    }
                }
            }
    }
}*/

void creatNBMatrx(int **NB, int **nn, int *order, int *ptr, int NN, int edges) {
    int arr = 0;
    int col = 0;
    for (int i = 0; i < NN; i++) {
            int s1 = order[i];
            int r1 = ptr[s1];
            if (r1 != EMPTY) {
                for (int j = 0; j < NN - 1; j++) {
                    int s2 = nn[s1][j];
                    if (s2 != EMPTY) {
                        int r2 = ptr[s2];
                        if (r2 != EMPTY) {
                            for (int ii = 0; ii < NN; ii++) {
                                int ss1 = order[ii];
                                int rr1 = ptr[ss1];
                                    if (rr1 != EMPTY) {
                                        for (int jj = 0; jj < NN - 1; jj++) {
                                            int ss2 = nn[ss1][jj];
                                            if (ss2 != EMPTY) {
                                                int rr2 = ptr[ss2];
                                                    if (rr2 != EMPTY) {
                                                        if ((s2 == ss1) && (s1 != ss2)) {
                                                            NB[arr][col] = 1;
                                                        } else {
                                                            NB[arr][col] = 0;
                                                            }
                                                        col += 1;
                                                        //cout << col << endl;
                                                    }
                                            }
                                        }
                                    }
                            }
                        col = 0;
                        arr += 1;
                        }
                    }
                }
            }
    }
    /*if ((0 == col) && (edges == arr)) {
        cout << "The dimension of the NB matrix is mached with the number of edges" << endl;
    }*/
}

/*void creatTAPMatrx(double **TAP, int **nn, int *order, int *ptr, int NN, int edges, double **probMtrx) {
    int arr = 0;
    int col = 0;
    for (int i = 0; i < NN; i++) {
            int s1 = order[i];
            int r1 = ptr[s1];
            if (r1 != EMPTY) {
                for (int j = 0; j < NN - 1; j++) {
                    int s2 = nn[s1][j];
                    if (s2 != EMPTY) {
                        int r2 = ptr[s2];
                        if (r2 != EMPTY) {
                            for (int ii = 0; ii < NN; ii++) {
                                int ss1 = order[ii];
                                int rr1 = ptr[ss1];
                                    if (rr1 != EMPTY) {
                                        for (int jj = 0; jj < NN - 1; jj++) {
                                            int ss2 = nn[ss1][jj];
                                            if (ss2 != EMPTY) {
                                                int rr2 = ptr[ss2];
                                                    if (rr2 != EMPTY) {
                                                            if (arr == col) {
                                                                double sum = 0;
                                                                for (int sss1 = 0; sss1 < NN - 1; sss1++) {
                                                                    if (nn[s1][sss1] != EMPTY) {
                                                                        sum -= pow(probMtrx[s1][sss1], 2);
                                                                        }
                                                                }
                                                                TAP[arr][col] = sum;
                                                            } else {
                                                                TAP[arr][col] = probMtrx[ss1][ss2];
                                                            }
                                                    col += 1;
                                                    }
                                                    //cout << col << endl;
                                            }
                                        }
                                    }
                                    }
                            }
                        col = 0;
                        arr += 1;
                        }
                    }
                }
            }
if ((0 == col) && (edges == arr)) {
    cout << "The dimension of the TAP matrix is mached with the number of edges" << endl;
    }
}*/

void creatTAPMatrx(double **TAP, int **nn, int *order, int *ptr, int NN, int edges, double **probMtrx) {
    for (int i = 0; i < NN; i++) {
        for (int j = 0; j < NN; j++) {
                if (i == j) {
                    int sum = 0;
                    for(int k = 0; k < NN; k++) {
                        sum -= pow(probMtrx[i][k], 2);
                    }
                    TAP[i][j] = sum;
                } else {
                    TAP[i][j] = probMtrx[i][j];
                }

        }
    }
}

double percoFraction(int NN, double **H, int **nn, int *order) {
    double S = 0;
    double SS = 0;
    for (int i = 0; i < NN; i++) {
        int s1 = order[i];
        double HH = 1;
        for (int j = 0; j < NN - 1; j++) {
            if (nn[s1][j] != EMPTY) {
                int s2 = nn[s1][j];
                HH *= H[s1][s2];
            }
        }
        //cout << HH << endl;
        SS += HH;
    }
    S = 1 - SS / NN;
    return S;
}

