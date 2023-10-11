#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; int m;
    cin >> n >> m;
    map<int, int> cnt = {};

    for (int i = 1; i <= n; i++)
        cnt[i] = 0;

    for (int i = 0; i < m; i++){
        int vote = 0;
        cin >> vote;
        cnt[vote]++;
    }

    for (int i = 1; i <= n; i++){
        while (cnt[i] > 0){
            cout << i << ' ';
            cnt[i]--;
        }
    }
    cout << endl;

    return 0;
}