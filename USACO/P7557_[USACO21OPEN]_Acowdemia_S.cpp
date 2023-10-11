#include<bits/stdc++.h>
using namespace std;

int n, k, l;
vector<int> c;

bool cmp(int a, int b){
    return a > b;
}

bool check(int h){
    long long sum = 0;
    for (int i = 0; i <= h; i++){
        if (h > c[i]) {
            sum += h - c[i];
            if (sum > k * l || h - c[i] > k)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> k >> l;

    for (int i = 0; i < n; i++) {
        c.emplace_back();
        cin >> c[i];
    }
    sort(c.begin(), c.end(), cmp);

    int a = 0, b = n - 1;
    while (a < b){
        int h = (a + b + 1)/2;
        if (check(h + 1))
            a = h;
        else
            b = h - 1;
    }
    cout << a + 1 << endl;

    return 0;
}