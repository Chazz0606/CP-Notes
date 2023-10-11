#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000000

int main() {
  int n;
  cin >> n;
  int l = 1;
  int r = N;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    cout << mid << endl;
    cout << flush;
    int res;
    cin >> res;
    if (res == 0) {
      return 0;
    } else if (res == -1) {
      l = mid + 1;
    } else if (res == 1) {
      r = mid - 1;
    } else {
      return 0;
    }
  }

  return 0;
}