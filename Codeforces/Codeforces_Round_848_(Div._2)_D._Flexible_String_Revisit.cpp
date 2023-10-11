#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define MOD 998244353

char a[N];

ll quickModPow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

ll fractionMod(ll p, ll q) {
    return (p * quickModPow(q, MOD - 2)) % MOD;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            // char temp = ' ';
            // cin >> temp;
            // a[j] = temp-'0';
            cin >> a[j];
        }

        int b = 0;
        for (int j = 0; j < n; j++) {
            char temp = ' ';
            cin >> temp;
            b += a[j] != temp;
        }
        // cerr << b << "/" << n << endl;

        vector<ll> f(n + 5, 0);
        f[n] = 1;
        for (int j = n - 1; j > 0; j--) {
            // ll pq = ;
            // cerr << 1 + (pq * f[j + 1]) % MOD << " " << (1 - pq) % MOD << endl;
            f[j] = fractionMod(1 + (fractionMod(n - j, n) * f[j + 1]) % MOD, fractionMod(j, n));
        }
        // cerr << b << "/" << n << endl;
        // for (int j = 0; j <= n; j++) cerr << f[j] << " ";
        // cerr << endl;
        for (int j = 1; j <= b; j++) f[j] = (f[j] + f[j - 1]) % MOD;
        cout << f[b] << endl;
    }

    return 0;
}
