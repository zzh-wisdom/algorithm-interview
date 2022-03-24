#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 10000;
int N, M, K;
#define MAXN 57

// 0: 有空碗
// 1: 无空碗
int dp1[MAXN][MAXN][2];

void prepare1() {
    int max_num = 50;
    // dp[i][j] i个物体放进j个碗
    dp1[0][0][0] = 1;
    dp1[0][0][1] = 1;
    for(int i = 1; i <= max_num; ++i) {
        dp1[0][i][0] = 1;
        dp1[0][i][1] = 0;
    }
    for(int i = 1; i <= max_num; ++i) {
        for(int j = 1; j <= max_num; ++j) {
            // 没有空碗
            if(i >= j) {
                dp1[i][j][1] = (dp1[i-j][j][0])%10000;
            }

            // 可以有空碗
            dp1[i][j][0] = (dp1[i][j-1][0] + dp1[i][j][1])%10000;
        }
    }
}

int dp_solve1() {
    int ans = 0;
    for(int kong_n = 0; kong_n <= K-2; ++kong_n) {
        int wan_n = K-kong_n;
        for(int m = 1; m < wan_n; ++m) {
            ans = ((ll)ans + ((ll)dp1[M][m][1] * dp1[N][wan_n-m][1])%10000)%10000;
        }
    }
    return ans;
}

int dp2[MAXN][MAXN];

void prepare2() {
    memset(dp2, 0, sizeof(dp2));
    for (int i = 0; i < 57; ++i) {
        dp2[0][i] = 1;
    }
    for (int i = 1; i < 57; ++i) {
        for (int j = 1; j < 57; ++j) {
            if (i >= j)
                dp2[i][j] += dp2[i - j][j];
            dp2[i][j] += dp2[i][j - 1];
        }
    }
}

int dp_solve2() {
    int ans = 0;
    for (int i = 1; i < K && i <= N; ++i) {
        for (int j = 1; j + i <= K && j <= M; ++j) {
            // 方法二牛逼，减去i，保证每个碗都必须有东西
            ans = ((ll)ans +
                    (((ll)dp2[N - i][i] * (ll)dp2[M - j][j]) % MOD)) % MOD;
        }
    }
    return ans;
}

// 方法二厉害
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    prepare1();
    prepare2();
    for(M = 1; M <= 50; ++M) {
        for(N = 1; N <= 50; ++N) {
            for(K = 2; K <= 50; ++K) {
                int ret1 = dp_solve1();
                int ret2 = dp_solve1();
                cout << "ret1: " << ret1 << ", ret2: " << ret2 << endl;
                assert(ret1 == ret2);
            }
        }
    }
    return 0;
}
