#ifndef HOST_H
#define HOST_H

typedef enum TYPE { S, I, R } TYPE;

typedef struct Host {
    int id;
    int x, y;
    int t;
    TYPE type;
} THost;

int idx(int x, int y, int k);

#endif // HOST_H
