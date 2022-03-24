#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;
typedef long long ll;

int N;

// 枚举腰长
ll fun1(int N) {
    ll ans = 0;
    int low = N/2/2;
    // 两腰长之和，要大于总变数一半
    if(low+low <= N/2) ++low;
    // 特殊情况处理
    if(N%3 == 0) {
        ans += N/3;
        ++low;
    }
    int high = N/2;
    if(N%2 == 0) --high;
    ans += (ll)(high-low+1)*N;
    return ans;
}

long long fun2(int N) {
    double deg = 360 * 1.0 / N;
    ll low = ceil(90.000001 * 1.0 / deg);
    ll up = floor(179.999999 * 1.0 / deg);
    if (low > up) {
        return 0;
    } else {
        if (N % 3 == 0) {
            return ((up - low) * (ll)N + (ll)(N / 3));
        } else {
            return (up - low + 1) * (ll)N;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // cin >> N;
    for(int N = 3; N < 1000000; ++N) {
        ll n1 = fun1(N);
        ll n2 = fun2(N);
        cout << N << ": " << n1 << " " << n2 << endl;
        assert(n1 == n2);
    }
    return 0;
}