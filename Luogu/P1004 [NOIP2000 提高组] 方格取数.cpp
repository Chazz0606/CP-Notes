#include <bits/stdc++.h>
using namespace std;

int main() {
  const int N = 10;
  int n;
  cin >> n;
  int grid[N][N] = {};

  {
    int a, b, c;
    do {
      cin >> a >> b >> c;
      grid[a - 1][b - 1] = c;
    } while (!(a == 0 && b == 0 && c == 0));
  }

  // for (int i = 0; i < n; i++) {
  // for (int j = 0; j < n; j++) {
  // cout << grid[i][j] << ' ';
  // }
  // cout << endl;
  // }

  int dp[2 * N - 1][N][N] = {};
  dp[0][0][0] = grid[0][0];
  for (int i = 1; i <= 2 * n - 2; i++) {
    for (int j = max(0, i - n - 1); j <= i && j < n; j++) {
        for (int k = max(0, i - n - 1); k <= i && k < n; k++) {
            int a = dp[i - 1][j][k];
            int b = (j > 0) ? dp[i - 1][j - 1][k] : 0;
            int c = (k > 0) ? dp[i - 1][j][k - 1] : 0;
            int d = (j > 0 && k > 0) ? dp[i - 1][j - 1][k - 1] : 0;
            dp[i][j][k] = max({a, b, c, d});
            if (j == k)
                dp[i][j][k] += grid[j][i - j];
            else
                dp[i][j][k] += grid[j][i - j] + grid[k][i - k];
        }
    }
  }

  // for (int i = 0; i < 2 * n - 2; i++) {
  // for (int j = 0; j < n; j++) {
  // for (int k = 0; k < n; k++) {
  // cout << dp[i][j][k] << ' ';
  // }
  // cout << endl;
  // }
  // cout << endl;
  // }

  cout << dp[2 * n - 2][n - 1][n - 1] << endl;

  return 0;
}