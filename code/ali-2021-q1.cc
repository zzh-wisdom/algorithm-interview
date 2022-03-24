// #include <iostream>
// #include <string>
// #include <map>
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> map_stoi = {
    {'E', 0},
    {'W', 1},
    {'S', 2},
    {'N', 3}
};

int directions[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m, n, k;
    cin >> m >> n >> k;
    int x, y;
    vector<vector<char> > matrix(m, vector<char>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            if(matrix[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }
    string tmp;
    for(int i = 0; i < k; ++i) {
        cin >> tmp;
        int d = map_stoi[tmp[0]];
        x += directions[d][0];
        y += directions[d][1];
        while(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == '.') {
            x += directions[d][0];
            y += directions[d][1];
        }
        x -= directions[d][0];
        y -= directions[d][1];
        cout << i << ": " << x << " " << y << endl;
    }
    cout << x+1 << " " << y+1 << endl;
    return 0;
}

/**
3 4 4
@...
.#..
...#
EAST
SOUTH
WEST
NORTH
 */