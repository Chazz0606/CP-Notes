# CF1778D Flexible String Revisit 题解

## 题目分析
题目给了两个二进制数字 $a$ 和 $b$ ，求每次随机翻一位的话把 $a$ 变成 $b$ 需要的期望是多少次

可以看出 $a$ 和 $b$ 里1和0的顺序不重要，重要的只有两个数字的总长度和有几位不同（设为 $s$），例如 $a=1001, b=1100$ 记为 $3/4$（$s=3, n=4$）

那么题目就变成了给定 $s$ 和 $n$ ，每次翻有 $\frac{s}{n}$ 概率 $s-1$ 和 $\frac{n-s}{n}$ 概率 $s+1$，当 $n=s$ 时必定 $s-1$，求期望多少步使 $s \to 0$

由于期望步数会出现分数，题目要求输出 $\mod{998244353}$，会涉及到分数取模，建议去查一下小费马定理

<!-- 这个题目我能想到的解法有两种： -->

<!-- ## 第一种解法 -->
## 题目解法
设 $d_i$ 为 $i/n \to (i-1)/n$ 需要的期望步数

从 $i/n$ 开始先走一步，有 $\frac{i}{n}$ 概率成功 $i-1$ 和 $\frac{n-i}{n}$ 概率 $i+1$，如果 $i+1$ 则需要 $d_{i+1}$ 步回到 $i/n$，然后再次进入循环。用公式表示：
$$ d_i = 1 + \frac{n-i}{n} (d_{i+1} + d_i) $$

解方程可得：
$$ \begin{cases}
d_i = \frac{n-(n-s)d_{i+1}}{s} & 0 < i < n\\
d_n = 1\\
d_0 = 0
\end{cases}$$

最终输出为 $i/n \to 0/n$ 需要的步数：$ \sum _{j=0}^{i} d_j $

## 代码
先 $(n-1) \to 1$ 跑一遍 dp 找 $d_i$，然后 $0 \to s$ 求和就能得到答案

```cpp
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
            f[i] = fractionMod((n + (n - i) * f[i + 1]) % MOD, i);
        }

        for (int i = 1; i <= s; i++) f[i] = (f[i] + f[i - 1]) % MOD;
        cout << f[s] << endl;
    }

    return 0;
}

```

<!-- ## 第二种解法
注：这个解法我没找出规律也列不出单项公式，只是作为记录和抛砖引玉写在这里，如果只是想找答案就用第一种

首先设 $f_i$ 为 $i/n \to 0/n$ 需要的步数：
$$ \begin{cases}
f_i = \frac{i}{n} f_{i-1} + \frac{n-i}{n} f_{i+1} + 1 & 0 < i < n\\
f_n = f_{n-1} + 1\\
f_0 = 0
\end{cases}$$

可以先试着用 $f_n$ 推出 $f_{n-1}$ 的单向公式，再去推 $f_{n-2}$，我推到了 $f_{n-4}$：
$$ \begin{aligned}
& f_n = f_{n-1} + 1 \\
& f_{n-1} = f_{n-2} + \frac{n+1}{n-1} = f_{n-2} + 1 + \frac{2}{n-1} \\
& f_{n-2} = f_{n-3} + \frac{n^2+n+2}{n^2-3n+2} = f_{n-2} + 1 + \frac{4n}{(n-1)(n-2)} \\
& f_{n-3} = f_{n-4} + \frac{n^3+5n+6}{n^3-6n^2+11n-6} = f_{n-3} + 1 + \frac{6n^2-6n+12}{(n-1)(n-2)(n-3)} \\
& f_{n-4} = f_{n-5} + \frac{n^4-2n^3+11n^2+14n+24}{n^4-10n^3+35n^2-50n+24} = f_{n-4} + 1 + \frac{8n^3-24n^2+64n}{(n-1)(n-2)(n-3)(n-4)} \\
\end{aligned} $$ -->