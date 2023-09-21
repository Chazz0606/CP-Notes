#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 0;
    int last = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (current > last)
            s += current-last;
        last = current;
    }
    cout << s;

    return 0;
}