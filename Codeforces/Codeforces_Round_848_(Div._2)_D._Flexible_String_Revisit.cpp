#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define MOD 998244353

char a[N];
ll f[N];

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
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 0;
        char b;
        for (int i = 0; i < n; i++) {
            cin >> b;
            s += a[i] != b;
        }

        f[n] = 1;
        for (int i = n - 1; i > 0; i--) {
            f[i] = fractionMod(n + ((n - i) * f[i + 1]) % MOD, i);
        }

        for (int i = 1; i <= s; i++) f[i] = (f[i] + f[i - 1]) % MOD;
        cout << f[s] << endl;
    }

    return 0;
}
