#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 55

int main() {
  int m, n;
  cin >> m >> n;
  int grid[N][N] = {};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  // for (int i = 0; i < n; i++) {
  // for (int j = 0; j < n; j++) {
  // cout << grid[i][j] << ' ';
  // }
  // cout << endl;
  // }

  int dp[2 * N - 1][N][N] = {};
  for (int i = 1; i <= m + n - 2; i++) {
    for (int j = max(0, i - n - 1); j <= i && j < m; j++) {
      for (int k = j + 1; k <= i && k < m; k++) {
        int a = dp[i - 1][j][k];
        int b = (j > 0) ? dp[i - 1][j - 1][k] : 0;
        int c = (k > 0) ? dp[i - 1][j][k - 1] : 0;
        int d = (j > 0 && k > 0) ? dp[i - 1][j - 1][k - 1] : 0;
        dp[i][j][k] = max({a, b, c, d});
        if (j == k)
          dp[i][j][k] = 0;
        else
          dp[i][j][k] += grid[j][i - j] + grid[k][i - k];
      }
    }
  }

  // for (int i = 0; i < m + n - 1; i++) {
  // for (int j = 0; j < m; j++) {
  // for (int k = 0; k < m; k++) {
  // cerr << dp[i][j][k] << ' ';
  // }
  // cerr << endl;
  // }
  // cerr << endl;
  // }

  cout << dp[m + n - 2][m - 2][m - 1] << endl;

  return 0;
}