#include <bits/stdc++.h>
using namespace std;

int ZeroOnePack(vector<int>& v, int start, int end) {
    int n = v.size();
    int V = n/3;
    vector<vector<int> > dp(n+1, vector<int>(V+1));
    for(int i = start; i <= end; ++i) {
        for(int j = 1; j <= V; ++j) {
            dp[i][j] = max(dp[i-1][j], (i >= 2 ? dp[i-2][j-1] : 0) + v[i-1]);
        }
    }
    return dp[end][V];
}

/**

6
1 2 3 4 5 6

 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << max(ZeroOnePack(v, 1, n-1), ZeroOnePack(v, 2, n)) << endl;

    return 0;
}
