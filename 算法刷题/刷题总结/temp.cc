#include <bits/stdc++.h>

using namespace std;

#define CIN1(a) (scanf("%d", &a))
#define CIN2(a, b) (scanf("%d%d", &a, &b))
#define CIN3(a, b, c) (scanf("%d%d", &a, &b, &c))

// ~scanf("%d", &a)

#define COUT(a) (printf("%d\n", a));

const int MAX_N = 5005;

int g_flags[MAX_N];

int a;

int main() {
    ios::sync_with_stdio(false);

    memset(g_flags, 0xff, sizeof(g_flags));
    CIN1(a);
    COUT(a);
    return 0;
}