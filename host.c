#include "host.h"

int idx(int x, int y, int k) {
    return x + k + (y + k) * (2 * k + 1);
}
