#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int grid[2][N] = {};
    grid[0][0] = 2 * n;
    grid[1][n - 1] = 2 * n - 1;
    int x = 2 * n - 2;
    int y = 1;
    for (int i = 1; i < n - 1; i++) {
      grid[y][i] = x--;
      y ^= 1;
    }
    // y = 1;
    for (int i = 0; i < n; i++) {
      grid[y][i] = x--;
      y ^= 1;
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cout << grid[i][j] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}