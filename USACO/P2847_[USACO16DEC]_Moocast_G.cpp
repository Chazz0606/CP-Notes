#include<bits/stdc++.h>
using namespace std;

int n, x[1001], y[1001], f[1001], d[1001][1001];

int find(int a){ // NOLINT(misc-no-recursion)
    if (f[a] == a)
        return a;
    else
        return f[a] = find(f[a]);
}

int check(int k){
    for (int i = 0; i < n; i++)
        f[i] = i;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (d[i][j] <= k)
                f[find(i)] = find(j);
        }
    }

    for (int i = 1; i < n; i++){
        if (find(i) != find(i-1))
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2); // NOLINT(cppcoreguidelines-narrowing-conversions)
        }
    }

    int l = 0, r = 1e9;
    while (l < r){
        int mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid+1;
    }
    cout << l << endl;

    return 0;
}