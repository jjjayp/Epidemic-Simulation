#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "host.h"
#include "linkedlist.h"
#include "simulation.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s k m T N\n", argv[0]);
        return 0;
    }

    int k = atoi(argv[1]);
    int m = atoi(argv[2]);
    int T = atoi(argv[3]);
    int N = atoi(argv[4]);

    assert(k >= 0 && k <= 1000);
    assert(m >= 1 && m <= 100000);
    assert(T >= 1);
    assert(N > 0 && N <= 100000);
    srand(12345);

    THost *hosts = malloc(sizeof(THost) * m);
    hosts[0] = (THost){0, 0, 0, 0, I};

    for (int i = 1; i < m; i++) {
        hosts[i].id = i;
        hosts[i].x = rand() % (2 * k + 1) - k;
        hosts[i].y = rand() % (2 * k + 1) - k;
        hosts[i].t = 0;
        hosts[i].type = S;
    }

    node **p_arr = calloc(N, sizeof(node *));
    node *r = create_node(hosts[0]);
    int index = hash(idx(hosts[0].x, hosts[0].y, k)) % N;
    add_first(&p_arr[index], r);

    while (one_round(hosts, m, p_arr, N, k, T));

    for (int i = 0; i < N; i++) remove_all(&p_arr[i]);
    free(p_arr);
    free(hosts);
    return 0;
}