#include <cstdio>
#include <cstring>

const int MAX_T = 1001;
const int TEETH_COUNT = 8;

int d[MAX_T][TEETH_COUNT];
int chk[MAX_T];

void rotateGear(int gearIdx, int direction) {
    if (direction == 1) {
        int tmp = d[gearIdx][TEETH_COUNT - 1];
        for (int i = TEETH_COUNT - 1; i >= 1; --i) {
            d[gearIdx][i] = d[gearIdx][i - 1];
        }
        d[gearIdx][0] = tmp;
    } else if (direction == -1) {
        int tmp = d[gearIdx][0];
        for (int i = 0; i < TEETH_COUNT - 1; ++i) {
            d[gearIdx][i] = d[gearIdx][i + 1];
        }
        d[gearIdx][TEETH_COUNT - 1] = tmp;
    }
}

void rotateAdjacentGears(int idx, int direction) {
    chk[idx] = direction;
    for (int j = idx; j < MAX_T - 1; ++j) {
        if (d[j][2] != d[j + 1][6]) {
            chk[j + 1] = -chk[j];
        } else {
            break;
        }
    }
    for (int j = idx; j > 1; --j) {
        if (d[j][6] != d[j - 1][2]) {
            chk[j - 1] = -chk[j];
        } else {
            break;
        }
    }
}

void processGears(int t, int k) {
    for (int i = 0; i < k; ++i) {
        memset(chk, 0, sizeof(chk));
        int x, y;
        scanf("%d %d", &x, &y);
        rotateAdjacentGears(x, y);
        for (int j = 1; j <= t; ++j) {
            if (chk[j] != 0) {
                rotateGear(j, chk[j]);
            }
        }
    }
}

int countTeethInPositionOne(int t) {
    int ans = 0;
    for (int i = 1; i <= t; ++i) {
        if (d[i][0] == 1) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < TEETH_COUNT; ++j) {
            scanf("%1d", &d[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    processGears(t, k);

    printf("%d\n", countTeethInPositionOne(t));

    return 0;
}
