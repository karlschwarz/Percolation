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

void boundaries(int **nn, int **A, int NN) {
    for (int i = 0; i < NN; i++) {
        for (int j = 0; j < NN - 1; j++) {
            nn[i][j] = EMPTY;
            }
        }
    for (int i = 0; i < NN; i++) {
            int *p = nn[i];
        for (int j = 0; j < NN; j++) {
            if (A[i][j] != 0) {
                *p = j;
                p++;
            }
        }
    }
}

/*void boundaries(int **nn, int **A) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      nn[i][j] = j;
    }
    for (int j = i + 1; j < N; j++) {
      nn[i][j - 1] = j;
    }
  }
}
*/

void permutation(int *order, int NN) {
    std::default_random_engine random(time(NULL));
    std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
    for (int i = 0; i < NN; i++) {
        order[i] = i;
    }
    for (int i = 0; i < NN; i++) {
        int j, temp;
        j = i + (NN - i) * uniDistrb(random);
        temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}

int findroot(int *ptr, int i) {
  if (ptr[i] < 0) {return i;}
  return ptr[i] = findroot(ptr, ptr[i]);
}

int percolate(int *ptr, int *order, int **nn, int NN) {
  int s1, r1;
  int s2, r2;
  int big = 0;
  for (int i = 0; i < NN; i++) {ptr[i] = EMPTY;}
  for (int i = 0; i < NN; i++) {
    r1 = s1 = order[i];
    ptr[s1] = -1;
    for (int j = 0; j < NN - 1; j++) {
        if (nn[s1][j] != EMPTY) {
      s2 = nn[s1][j];
      if (ptr[s2] != EMPTY) {
        r2 = findroot(ptr, s2);
        if (r2 != r1) {
          if (ptr[r1] > ptr[r2]) {
            ptr[r2] += ptr[r1];
            ptr[r1] = r2;
            r1 = r2;
          } else {
              ptr[r1] += ptr[r2];
              ptr[r2] = r1;
            }
        if (-ptr[r1] > big) big = -ptr[r1];
        //cout << ptr[r1] << endl;
      }
      }
    }
  }
  //cout << ptr[r1] << endl;
  //cout << big << ' ' << i + 1 << endl;
}
    return big;
   // cout << big << endl;
  //  cout << endl;

//for (int i = 0; i < N; i++) {
 //   cout << ptr[i] << endl;
//}
}

void creatH(int NN, double **H, int *ptr) {
    std::default_random_engine random(time(NULL));
    std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
    for (int i = 0; i < NN; i++) {
        for (int j = 0; j < NN; j++) {
            H[i][j] = 0;
        }
    }
    for (int i = 0; i < NN; i++) {
            if (ptr[i] != EMPTY) {
                for (int j = i + 1; j < NN; j++) {
                        if (ptr[j] != EMPTY) {
                            H[i][j] = uniDistrb(random);
                            H[j][i] = uniDistrb(random);
                        }
                }
            }
    }
}

int adjacentMtrx(double **probMtrx, int **A, int NN) {
    std::default_random_engine random(time(NULL));
    std::uniform_real_distribution<double> uniDistrb(0.0, 1.0);
    int sum = 0;
    double adg;
    for (int i = 0; i < NN; i++) {
        A[i][i] = 0;
        for (int j = i + 1; j < NN; j++) {
            double p = uniDistrb(random);
            double pp = probMtrx[i][j];
            if (p < pp) {
                A[i][j] = 1;
                A[j][i] = 1;
                sum += 1;
            } else {
                A[i][j] = 0;
                A[j][i] = 0;
                }
        }
    }
    adg = 2 * sum / NN;
    cout << "The average degree is " << adg << '.' << endl;
    return sum;
}

void creatMtrx(int NN, double **probMtrx, double prob) {
    for (int i = 0; i < NN; i++) {
            probMtrx[i][i] = 0;
        for (int j = i + 1; j < NN; j++) {
            probMtrx[i][j] = prob;
            probMtrx[j][i] = probMtrx[i][j];
        }
    }
}

/*void creatMtrx(int NN, double **probMtrx) {
    for (int i = 0; i < NN; i++) {
            probMtrx[i][i] = 0;
        for (int j = i + 1; j < NN; j++) {
            probMtrx[i][j] = uniDistrb(random);
            probMtrx[j][i] = probMtrx[i][j];
        }

    }
}*/



