#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 100];
long long k, t;
int main() {
	int i;
	scanf("%d%lld", &n, &k);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	std :: sort(a, a + n), --k;
	for (i = 0; i < n; i += t) {
		for (t = 1; a[i] == a[i + t]; ++t);
		if (t * n > k)
			break;
		k -= t * n;
	}
	printf("(%d,%d)\n",a[i],a[k/t]);
}