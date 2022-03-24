#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long a, b;

int exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    scanf("%lld%lld", &a, &b);
    long long x = 0, y = 0;
    exgcd(a, b, x, y);
    printf("%lld\n", (x % b + b) % b);//这里防止出现负数
    return 0;
}

typedef long long ll;

// ax = 1 (mod b)
// x为逆元
ll x, y;
void inverse(ll a, ll b) {
    if (b == 0) {
        x = 1; y = 0;
    } else {
        inverse(b, a % b);
        ll tmp = x;
        x = y; y = tmp - (a / b) * y;
    }
}