#include<bits/stdc++.h>
using namespace std;

int MOD = 97654321;
int dp[52][251][251] = {};
map<char, vector<char>> next_chars = {};

int get_index(char c){
    if (65 <= c && 90 >= c)
        return c - 39;
    else
        return c - 97;
}

int find(char c, int u, int l){ // NOLINT(misc-no-recursion)
    if (u < 0 || l < 0)
        return 0;
    else if (u + l == 0)
        return 1;
    else if (dp[get_index(c)][u][l] != -1)
        return dp[get_index(c)][u][l];

    int cnt = 0;
    for (char i : next_chars[c]) {
        cnt = (cnt + find(i, u - (isupper(i)?1:0), l - (islower(i)?1:0))) % MOD;
    }

    dp[get_index(c)][u][l] = cnt;
    return cnt;
}

int main() {
    int u, l, p;
    cin >> u >> l >> p;

    for (int i = 0; i < p; i++){
        char a, b;
        cin >> a >> b;
        if (next_chars.count(a) == 1)
            next_chars[a].push_back(b);
        else
            next_chars[a] = {b};
    }

    for (int i = 0; i < 52; i++){ // NOLINT(modernize-loop-convert)
        for (int j = 0; j < u+1; j++){
            for (int k = 0; k < l+1; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    int cnt = 0;
    for (pair<char, vector<char>> x: next_chars)
        cnt = (cnt + find(x.first, u-(isupper(x.first)?1:0), l-(islower(x.first)?1:0))) % MOD;
    cout << cnt << endl;

    return 0;
}