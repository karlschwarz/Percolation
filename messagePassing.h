//---------------------------------------------------------------
//Copyright (C) 2017 Erdong Guo
//---------------------------------------------------------------
//===============================================================
//Erdong Guo - Created: 5th May 2017
//
//
//
//===============================================================
void initializeInitvec(int edges, double *initvec);
void mesgePassing(int *order, int *ptr, double **H, int **nn, double **probMtrx, int NN);
void creatNBMatrx(int **NB, int **nn, int *order, int *ptr, int NN, int edges);
void creatTAPMatrx(double **TAP, int **nn, int *order, int *ptr, int NN, int edges, double **probMtrx);
double percoFraction(int NN, double **H, int **nn, int *order);
double powerMethod(int **A, double *initvec, double *eigvec, int NN);
double powerMethod(double **A, double *initvec, double *eigvec, int NN);
double powerIteration(int **A, double *initvec, double *eigvec, double *dif, double thres, int NN);
double powerIteration(double **A, double *initvec, double *eigvec, double *dif, double thres, int NN);
