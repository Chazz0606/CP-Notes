#include<bits/stdc++.h>
using namespace std;

struct path{
    vector<int> path = {};
    int score = 0;
};

bool cmp(const path& a, const path& b){
    return a.score < b.score;
}

int main() {
    int n; cin >> n;
    int bomb[25] = {};
    for (int i = 1; i <= n; i++)
        cin >> bomb[i];

    path maxp;
    path dp[25] = {};
    for (int i = 1; i <= n; i++){
        dp[i].path.push_back(i);
        dp[i].score += bomb[i];
        maxp = max(maxp, dp[i], cmp);
        for (int j = i + 1; j <= n; j++){
            int x; cin >> x;
            if (x)
                dp[j] = max(dp[j], dp[i], cmp);
        }
    }
    for (int i: maxp.path)
        cout << i << ' ';
    cout << endl;
    cout << maxp.score << endl;

    return 0;
}