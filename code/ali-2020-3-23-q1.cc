#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int solve(int n) {
    // n*2^(n-1)
    if(n == 0) return 0;
    int m = n-1;
    int tmp = 2;
    int ans = 1;
    while(m) {
        if(m&1) {
            ans = ((ll)ans * tmp) % MOD;
        }
        tmp = ((ll)tmp * tmp) % MOD;
        m >>= 1;
    }
    return ((ll)n * ans) % MOD;
}

int solve2(int n) {
    // n * (2^(n - 1))
    if(n == 0) return 0;
    int mi = n - 1;
    int ans = 1; int tmp = 2;
    while (mi) {
        if (mi & 1) {
            ans = ((ll)ans * (ll)tmp) % MOD;
        }
        tmp = ((ll)tmp * (ll)tmp) % MOD;
        mi >>= 1;
    }
    return (int)(((ll)n * (ll)ans) % MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        int ans1 = solve(i);
        int ans2 = solve2(i);
        assert(ans1 == ans2);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
