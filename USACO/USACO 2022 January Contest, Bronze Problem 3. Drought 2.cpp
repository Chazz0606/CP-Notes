#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n = 0;
        cin >> n;
        vector<long long> h = {};
        for (int i = 0; i < n; i++) {
            h.emplace_back();
            cin >> h[i];
        }
        long long cnt = 0;
        bool flag = true;
        for (int i = 1; i < n-1; i++){
            if (h[i] < 0 || h[i+1] < 0){
                flag = false;
                break;
            }
            long long d = h[i]-h[i-1];
            if (d >= 0){
                cnt += 2*d;
                h[i] -= d;
                h[i+1] -= d;
            }
        }
        for (int i = n-2; i > 0; i++){
            if (h[i-1] < 0 || h[i] < 0){
                flag = false;
                break;
            }
            long long d = h[i]-h[i+1];
            if (d >= 0){
                cnt += 2*d;
                h[i] -= d;
                h[i-1] -= d;
            }
        }
        if (flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}