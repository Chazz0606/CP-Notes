#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 0;

    vector<int> a = {};
    vector<int> b = {};
    vector<int> d = {0};
    for (int i = 0; i < n; i++) {
        a.emplace_back();
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        b.emplace_back();
        cin >> b[i];
    }

    vector<int> add_zero = {};
    for (int i = 0; i < n; i++) {
        d.push_back(b[i]-a[i]);
    }

    for (int i = 1; i < n+1; i++){
        if (d[i] > 0 && d[i-1] < 0)
            s += d[i];
        else if (d[i] < 0 && d[i-1] > 0)
            s += -d[i];
        else if (d[i] > 0 && d[i] > d[i-1])
            s += d[i] - d[i-1];
        else if (d[i] < 0 && d[i-1] > d[i])
            s += d[i-1] - d[i];
    }

    cout << s;

    return 0;
}