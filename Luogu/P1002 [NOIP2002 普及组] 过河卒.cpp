#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    long long dp[21][21] = {{1}};

    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++){
            if (i == 0 && j == 0)
                continue;
            if ((abs(i-a) == 2 && abs(j-b) == 1) || (abs(i-a) == 1 && abs(j-b) == 2) || (i == a && j == b)) {
                dp[i][j] = 0;
            } else {
                long long left = (j != 0) ? dp[i][j-1] : 0;
                long long up = (i != 0) ? dp[i-1][j] : 0;
                dp[i][j] = left + up;
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}