#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, s[10001], dp[10001] = {0};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int maximum = s[i];
        int group_max = 0;
        for (int j = i; j >= max(i + 1 - k, 1); j--){
            group_max = max(group_max, s[j]);
            maximum = max(maximum, dp[j-1]+group_max*(i-j+1));
        }
        dp[i] = maximum;
    }

    cout << dp[n] << endl;

    return 0;
}