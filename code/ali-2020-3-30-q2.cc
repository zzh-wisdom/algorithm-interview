#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1000006;
double dp[N];//dp[i]表示前i个数（以第i个数结尾）中的最大值期望
int main(){
    int n,t;
    scanf("%d",&n);
    ll c = (ll)n * (n + 1) / 2;
    dp[0] = 0;//无意义
    stack<PII> m;
    double res = 0;
    for(int i = 0;i < n; i++){
        scanf("%d",&t);
        while(!m.empty() && m.top().first <= t){
            m.pop();
        }
        int d = m.empty()?i + 1 : i-m.top().second;
        dp[i + 1] = 1.0 * t *d / c + dp[i + 1 - d];
        res += dp[i + 1];
        m.emplace(t,i);
    }
    printf("%.6f\n",res);
}
