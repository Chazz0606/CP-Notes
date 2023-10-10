#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 100005

void process(int n, bool r[N], int size) {
    int a = 0, b = 0;
    for (int i = 0; i < size; i++) {
        a += r[i];
        b += !r[i];
        if ((a >= n || b >= n) && abs(a - b) >= 2) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        }
    }
    cout << a << ":" << b << endl;
}

int main() {
    char t;
    bool result[N] = {};

    int i = 0;
    while (true) {
        cin >> t;

        if (t == 'W')
            result[i++] = 1;
        else if (t == 'L')
            result[i++] = 0;
        else if (t == 'E')
            break;
    }
    process(11, result, i);
    cout << endl;
    process(21, result, i);

    return 0;
}