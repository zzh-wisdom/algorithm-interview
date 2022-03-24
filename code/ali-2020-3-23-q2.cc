#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#define MAXN 507
#define MAXM 507

using namespace std;

int N, M;
string G[MAXN];

struct Node {
    int x; int y; int pw;
};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// int main() {
//     int dis[6][MAXN][MAXM];
//     ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cin >> N >> M;
//     memset(dis, 0xff, sizeof(dis));

//     queue<Node> q;
//     for (int i = 0; i < N; ++i) {
//         cin >> G[i];
//         for (int j = 0; j < G[i].size(); ++j) {
//             if (G[i][j] == 'S') {
//                 q.push({i, j, 5});
//                 dis[5][i][j] = 0;
//             }
//         }
//     }

//     while (!q.empty()) {
//         auto cur = q.front();
//         q.pop();
//         for (int i = 0; i < 4; ++i) {
//             int nx = cur.x + dir[i][0];
//             int ny = cur.y + dir[i][1];
//             if (nx < 0 || nx >= N) continue;
//             if (ny < 0 || ny >= M) continue;
//             if (dis[cur.pw][nx][ny] != -1) continue;
//             if (G[nx][ny] == '#') continue;

//             if (G[nx][ny] == 'E') {
//                 cout << dis[cur.pw][cur.x][cur.y] + 1 << endl;
//                 return 0;
//             }
//             dis[cur.pw][nx][ny] = dis[cur.pw][cur.x][cur.y] + 1;
//             q.push({nx, ny, cur.pw});
//         }
//         if (cur.pw) {
//             int nx = N - 1 - cur.x;
//             int ny = M - 1 - cur.y;
//             if (G[nx][ny] != '#' && dis[cur.pw - 1][nx][ny] == -1) {
//                 if (G[nx][ny] == 'E') {
//                     cout << dis[cur.pw][cur.x][cur.y] + 1 << endl;
//                     return 0;
//                 }
//                 dis[cur.pw - 1][nx][ny] = dis[cur.pw][cur.x][cur.y] + 1;
//                 q.push({nx, ny, cur.pw - 1});
//             }
//         }
//     }
//     cout << -1 << endl;
//     return 0;
// }

/**

4 4
#S..
E#..
....
....

 */

// 方法二，不维护三维信息
int main() {
    int dis[MAXN][MAXM];
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    memset(dis, 0xff, sizeof(dis));

    queue<Node> q;
    for (int i = 0; i < N; ++i) {
        cin >> G[i];
        for (int j = 0; j < G[i].size(); ++j) {
            if (G[i][j] == 'S') {
                q.push({i, j, 5});
                dis[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (dis[nx][ny] != -1) continue;
            if (G[nx][ny] == '#') continue;

            if (G[nx][ny] == 'E') {
                cout << dis[cur.x][cur.y] + 1 << endl;
                return 0;
            }
            dis[nx][ny] = dis[cur.x][cur.y] + 1;
            q.push({nx, ny, cur.pw});
        }
        if (cur.pw) {
            int nx = N - 1 - cur.x;
            int ny = M - 1 - cur.y;
            if (G[nx][ny] != '#' && dis[nx][ny] == -1) {
                if (G[nx][ny] == 'E') {
                    cout << dis[cur.x][cur.y] + 1 << endl;
                    return 0;
                }
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
                q.push({nx, ny, cur.pw - 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}