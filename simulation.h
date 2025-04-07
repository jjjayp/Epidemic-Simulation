#ifndef SIMULATION_H
#define SIMULATION_H

#include "host.h"
#include "linkedlist.h"

unsigned hash(unsigned a);
int summary(THost hosts[], int m);
int one_round(THost *hosts, int m, node **p_arr, int n_arr, int k, int T);

#endif // SIMULATION_H


// ===================== src/host.c =====================
#include "host.h"

int idx(int x, int y, int k) {
    return x + k + (y + k) * (2 * k + 1);
}