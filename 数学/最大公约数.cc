#include <bits/stdc++.h>

// 这个优
// 辗转相除法
int gcd1(int a, int b) {
    if(!b) return a;
    return gcd1(b, a%b);
}

// 更相减损法
int gcd2(int a, int b) {
    if(a == b) return b;
    // return gcd2((b > a-b) ? b : a-b, (b > a-b) ? a-b : b);
    if(a > b) return gcd2(b, a-b);
    return gcd2(a, b-a);
}

// least common multiple
// 求出两个数的最大公约数后，若k是a和b的最大公约数，那么a和b的最小公倍数为ab/k。编写函数lcm
long long lcm(int a, int b) {
    int k = a > b ? gcd1(a, b) : gcd1(b, a);
    return (long long)a*b/k;
}

const int MAXN = 1e2;
int main() {
    for(int i = MAXN/2; i < MAXN; ++i) {
        for(int j = i; j <= MAXN; ++j) {
            int ret1 = gcd1(j,i);
            int ret2 = gcd2(j,i);
            long long mcm_m = lcm(j, i);
            printf("[%d, %d]: %d %d, mcm: %lld\n", j, i, ret1, ret2, mcm_m);
            assert(ret1 == ret2);
        }
    }
    return 0;
}