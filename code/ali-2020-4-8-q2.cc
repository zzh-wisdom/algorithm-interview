#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAXN 1007

using namespace std;

int T;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int N; int K;
int G[MAXN][MAXN];
int dp[MAXN][MAXN];

struct Node {
    int x; int y;
};
struct cmp {
    bool operator() (const Node& n1, const Node& n2) {
        // 取最小的能量值，保证，每次遍历后，之后就不可能再遍历到
        return G[n1.x][n1.y] > G[n2.x][n2.y];
    }
};

/**
1
4 4
10 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
10

1
4 2
0 5 37 17
55 10 66 19
12 12 9 18
34 12 21 16
219
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> G[i][j];
            }
        }
        memset(dp, 0xff, sizeof(dp));
        priority_queue<Node, vector<Node>, cmp > pq;
        dp[0][0] = 0;
        // dp[0][0] = G[0][0];
        pq.push({0, 0});
        int ans = -1;
        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            ans = max(ans, dp[cur.x][cur.y] + G[cur.x][cur.y]);
            // ans = max(ans, dp[cur.x][cur.y]);
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x; int ny = cur.y;
                for (int j = 0; j < K; ++j) {
                    nx += dir[i][0]; ny += dir[i][1];
                    if (nx < 0 || nx >= N) break;
                    if (ny < 0 || ny >= N) break;
                    bool visited = (dp[nx][ny] != -1);
                    if (G[nx][ny] > G[cur.x][cur.y]) {
                        dp[nx][ny] = max(dp[nx][ny],
                                         dp[cur.x][cur.y] + G[cur.x][cur.y]);
                        // dp[nx][ny] = max(dp[nx][ny],
                        //                  dp[cur.x][cur.y] + G[nx][ny]);
                        if (!visited) {
                            pq.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
