#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    const int MOD = 80112002;
    int dp[5005] = {};
    memset(dp+1, 0, n+1);
    int in[5005] = {};
    vector<int> out[5005] = {};

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        out[a].push_back(b);
        in[b]++;
    }

    queue<int> q = {};
    for(int i = 1; i <= n; i++) {
        if (!in[i]) {
            dp[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i: out[x]){
            dp[i] = (dp[i]+dp[x])%MOD;
            in[i]--;
            if (!in[i])
                q.push(i);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (out[i].empty()) cnt = (cnt+dp[i])%MOD;
    cout << cnt << endl;

    return 0;
}