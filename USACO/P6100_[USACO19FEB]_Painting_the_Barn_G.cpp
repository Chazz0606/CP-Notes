#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10

int n, k;
int grid[N + 2][N + 2] = {};

// int hGreatestMatrixSum(int lLim, int rLim) {
    // int maxs = 0;
    // for (int u = 0; u <= N; u++) {
        // for (int d = u; d <= N; d++) {
            // int dp[N + 2] = {};
            // dp[lLim] = max(0, (u == 0) ? grid[d][lLim] : grid[d][lLim] - grid[u - 1][lLim]);
            // int maxa = dp[0];
            // for (int x = lLim + 1; x <= rLim; x++) {
                // int ysum = (u == 0) ? grid[d][x] : grid[d][x] - grid[u - 1][x];
                // dp[x] = max(dp[x - 1] + ysum, ysum);
                // maxa = max(maxa, dp[x]);
            // }
            // maxs = max(maxs, maxa);
        // }
    // }
    // return maxs;
// }
// 
// int vGreatestMatrixSum(int uLim, int dLim) {
    // int maxs = 0;
    // for (int u = uLim; u <= dLim; u++) {
        // for (int d = u; d <= dLim; d++) {
            // int dp[N + 2] = {};
            // dp[0] = max(0, (u == 0) ? grid[d][0] : grid[d][0] - grid[u - 1][0]);
            // int maxa = dp[0];
            // for (int x = 1; x <= N; x++) {
                // int ysum = (u == 0) ? grid[d][x] : grid[d][x] - grid[u - 1][x];
                // dp[x] = max(dp[x - 1] + ysum, ysum);
                // maxa = max(maxa, dp[x]);
            // }
            // maxs = max(maxs, maxa);
        // }
    // }
    // return maxs;
// }

int main() {
    cin >> n >> k;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        grid[y1][x1]++;
        grid[y2][x1]--;
        grid[y1][x2]--;
        grid[y2][x2]++;
    }
    for (int y = 1; y <= N; y++) grid[y][0] += grid[y - 1][0];
    for (int x = 1; x <= N; x++) grid[0][x] += grid[0][x - 1];

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            grid[y][x] += grid[y - 1][x] + grid[y][x - 1] - grid[y - 1][x - 1];
        }
    }

    for (int y = 0; y <= N; y++) {
        for (int x = 0; x <= N; x++) {
            cerr << grid[y][x] << " ";
        }
        cerr << "\n";
    }
    cerr << "\n";

    int s = 0;
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            if (k - grid[y][x] == 1) {
                grid[y][x] = 1;
            } else if (k - grid[y][x] == 0) {
                grid[y][x] = -1;
                s++;
            } else {
                grid[y][x] = 0;
            }
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 0; x <= N; x++) {
            grid[y][x] += grid[y - 1][x];
        }
    }
    
    int drdp[N+2][N+2] = {};
    for (int u = 0; u <= N; u++) {
        for (int d = u; d <= N; d++) {
            int dp[N + 2] = {};
            drdp[0][0] = max(0, (u == 0) ? grid[d][0] : grid[d][0] - grid[u - 1][0]);
            int maxa = dp[0];
            for (int x = 1; x <= N; x++) {
                int ysum = (u == 0) ? grid[d][x] : grid[d][x] - grid[u - 1][x];
                dp[x] = max(dp[x - 1] + ysum, ysum);
                maxa = max(maxa, dp[x]);
            }
            maxs = max(maxs, maxa);
        }
    }
    int uldp[N+2][N+2] = {};
    cout << maxs + s << endl;

    return 0;
}
