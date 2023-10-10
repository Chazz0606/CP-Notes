#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005

int main() {
  int t;
  cin >> t;
  for (int h = 0; h < t; h++) {
    int n;
    cin >> n;
    int a[N] = {};
    for (int i = 0; i < n; i++) cin >> a[i];
    // int b[N] = {};
    // copy(begin(a), begin(a) + n, begin(b));
    // sort(b, b + n);
    // int minn = 0;
    // bool exist = false;
    // for (int i = 0; i < n; i++) {
    // if (minn < b[i]) {
    // if (b[i] == minn + 1) exist = true;
    // break;
    // } else {
    // minn = b[i] + 1;
    // }
    // }
    int minn = 0;
    bool exist = false;
    set<int> check = {};
    for (int i = 0; i < n; i++) check.insert(a[i]);
    for (int i = 0; i < static_cast<int>(check.size()); i++) {
      if (!check.count(i)) {
        if (check.count(i + 1)) exist = true;
        minn = i;
        break;
      }
    }
    // cerr << minn << ' ' << exist << endl;

    if (!exist) {
      set<int> dict = {};
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (!dict.insert(a[i]).second) {
          found = true;
          break;
        }
      }
      cout << (found ? "Yes" : "No") << endl;

    } else {
      int mini = -1;
      int maxi = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == minn + 1) {
          if (mini == -1) mini = i;
          maxi = i;
        }
      }
      set<int> dict = {};
      for (int i = 0; i < mini; i++) dict.insert(a[i]);
      for (int i = maxi + 1; i < n; i++) dict.insert(a[i]);
      int flag = true;
      for (int i = 0; i < minn; i++) {
        if (!dict.count(i)) {
          flag = false;
          break;
        }
      }
      cout << (flag ? "Yes" : "No") << endl;
    }
  }
  return 0;
}