#include<bits/stdc++.h>
using namespace std;

const int N = 502;
long long a[N] = {};
long long s[N][N] = {};
set<long long> sums = {};

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        long long sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            s[i][j] = sum;
            sums.insert(sum);
        }
    }

    for (int i = 0; i < n; i++){
        long long change = 0;
        while ()
    }

    return 0;
}