#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int dp[10005] = {};
    for (int i = 0; i < n; i++){
        int id, time; cin >> id >> time;
        vector<int> pre = {};
        int temp = -1;
        do {
            cin >> temp;
            pre.push_back(temp);
        } while (temp);

        int maxt = 0;
        for (int x: pre)
            maxt = max(maxt, dp[x]);
        dp[id] = maxt+time;
    }
    int maxt = 0;
    for (int i = 0; i <= n; i++)
        maxt = max(maxt, dp[i]);
    cout << maxt << endl;

    return 0;
}