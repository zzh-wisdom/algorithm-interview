#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

int N;

int main() {
    // 180 - 2*x < 90
    // x < 180
    // x > 90
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    double deg = 360 * 1.0 / N;
    ll low = ceil(90.000001 * 1.0 / deg);
    ll up = floor(179.999999 * 1.0 / deg);
    if (low > up) {
        cout << "0" << endl;
    } else {
        if (N % 3 == 0) {
            cout << ((up - low) * (ll)N + (ll)(N / 3)) << endl;
        } else {
            cout << (up - low + 1) * (ll)N << endl;
        }
    }
    return 0;
}