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
        if (h.size() > 2 && h[1] > h[2]){
            long long d = h[1] - h[2];
            cnt += 2*d;
            h[0] -= d;
            h[1] -= d;
            if (h[0] < 0 || h[1] < 0)
                flag = false;
        }
        for (int i = 1; i < n; i++){
            if (!flag)
                break;

            long long d = h[i]-h[i-1];
            if (i == n-1) {
                if (d)
                    flag = false;
                break;
            }

            if (d >= 0){
                cnt += 2*d;
                h[i] -= d;
                h[i+1] -= d;
                if (h[i] < 0 || h[i+1] < 0)
                    flag = false;
            } else {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
