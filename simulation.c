#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"

unsigned hash(unsigned a) {
    a = (a ^ 61) ^ (a >> 16);
    a += (a << 3);
    a ^= (a >> 4);
    a *= 0x27d4eb2d;
    a ^= (a >> 15);
    return a;
}

int summary(THost hosts[], int m) {
    int S_n = 0, I_n = 0, R_n = 0;
    for (int i = 0; i < m; i++) {
        if (hosts[i].type == S) S_n++;
        else if (hosts[i].type == I) I_n++;
        else if (hosts[i].type == R) R_n++;
    }

    if (I_n == 0) {
        printf("    S        I        R\n");
        printf("%lf %lf %lf\n", (double)S_n / m, (double)I_n / m, (double)R_n / m);
    }
    return I_n > 0;
}

int one_round(THost *hosts, int m, node **p_arr, int n_arr, int k, int T) {
    for (int i = 0; i < m; i++) {
        if (hosts[i].type == S) {
            int index = hash(idx(hosts[i].x, hosts[i].y, k)) % n_arr;
            if (location_match(p_arr[index], hosts[i])) {
                hosts[i].type = I;
                hosts[i].t = 0;
            }
        } else if (hosts[i].type == I) {
            hosts[i].t++;
            if (hosts[i].t == T)
                hosts[i].type = R;
        }
    }

    for (int i = 0; i < n_arr; i++) {
        remove_all(&p_arr[i]);
    }

    for (int i = 0; i < m; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0: hosts[i].y = (hosts[i].y + k + 1) % (2 * k + 1) - k; break;
            case 1: hosts[i].x = (hosts[i].x + k + 1) % (2 * k + 1) - k; break;
            case 2: hosts[i].y = (hosts[i].y - 1 + 2 * k + 1) % (2 * k + 1) - k; break;
            case 3: hosts[i].x = (hosts[i].x - 1 + 2 * k + 1) % (2 * k + 1) - k; break;
        }

        if (hosts[i].type == I) {
            node *n = create_node(hosts[i]);
            int index = hash(idx(hosts[i].x, hosts[i].y, k)) % n_arr;
            add_first(&p_arr[index], n);
        }
    }

    return summary(hosts, m);
}
