#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 1007
#define MAXM 1007
#define MAXNM 1000007

using namespace std;

int N, M, Q;
int A[MAXN][MAXM];
double G[MAXNM][5]; // 注意要用浮点数
int gidx = 0;
bool valid[4] = {true, true, true, true};
double ans[4];

void Gauss_Em(int cols) {
    for (int j = 0; j < cols - 1; ++j) {
        if (j != 0) {
            // 寻找该列最大绝对值所在位置
            int max_idx = j;
            for (int i = j; i < gidx; ++i) {
                if (fabs(G[i][j]) > fabs(G[max_idx][j])) {
                    max_idx = i;
                }
            }
            // 交换到j行
            if (max_idx != j) {
                for (int i = 0; i < cols; ++i) {
                    swap(G[max_idx][i], G[j][i]);
                }
            }
        }
        // if(gidx <= j) break; // 行数不够，无法相消
        // 相消
        if (G[j][j] != 0) {  // 行数不够时，G[j][j]为0 直接跳过
            for (int row = 0; row < gidx; ++row) { // 行
                if (row != j) {
                    double rate = G[row][j] / G[j][j];
                    for (int k = 0; k < cols; ++k) { // 列
                        G[row][k] -= G[j][k] * rate;
                    }
                }
            }
        }
    }
}

// A_00 r0 c0 t
// 则A_ij =
// A_00 + j*r0 + i*c0 + ij*t
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> Q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            if (A[i][j] != 0) {
                G[gidx][0] = 1;
                G[gidx][1] = j;
                G[gidx][2] = i;
                G[gidx][3] = i * j;
                G[gidx][4] = A[i][j];
                gidx++;
            }
        }
    }

    Gauss_Em(5);
    for(int row = 0; row < gidx; ++row) {
        for(int col = 0; col < 5; ++col) {
            printf("%4.2lf ", G[row][col]);
        }
        printf("\n");
    }
    // 这里默认有解，没有判断第5行之后相冲突的情况
    for (int i = 0; i < 5; ++i) {
        if (i < gidx) {
            for (int j = i + 1; j < 4; ++j) { // 确保改等式只有一个未知数
                if (G[i][j]) {
                    valid[i] = false;
                    break;
                }
            }
            // if(G[i][i] == 0) valid[i] = false;
            if (valid[i])
                ans[i] = G[i][4] / G[i][i];
        } else {
            valid[i] = false;
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        double a1, a2, a3, a4;
        if (!valid[0]) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        a1 = ans[0];
        if (y && !valid[1]) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        a2 = (y == 0) ? 0 : (y * ans[1]);
        if (x && !valid[2]) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        a3 = (x == 0) ? 0 : (x * ans[2]);
        if (x && y && !valid[3]) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        a4 = (x == 0 || y == 0) ? 0 : (x * y * ans[3]);
        cout << (a1 + a2 + a3 + a4) << endl;
    }
    return 0;
}

/*
3 3 9
1 2 0
3 0 0
0 0 0
1 1
1
1 2
2
1 3
3
2 1
3
2 2
UNKNOWN
2 3
UNKNOWN
3 1
5
3 2
UNKNOWN
3 3
UNKNOWN
*/