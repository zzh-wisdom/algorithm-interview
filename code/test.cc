#include <bits/stdc++.h>

int main() {
    int sum = 1;
    int n = 10;
    for(int i = 1; i < n; ++i) {
        sum += i;
    }
    printf("sum: %d\n", sum);
    return sum;
}