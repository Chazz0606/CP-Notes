#include <bits/stdc++.h>
using namespace std;

string get(int x) {
  if (x == 0)
    return "0";
  else if (x == 2)
    return "2";
  vector<string> v = {};
  int r = 0;
  while (x > 0) {
    int p = pow(2, r);
    if (p * (x & 1)) {
      if (r != 1) {
        v.push_back("2(" + get(r) + ")");
      } else {
        v.push_back("2");
      }
    }
    x = x >> 1;
    r += 1;
  }
  string res = v[0];
  for (int i = 1; i < v.size(); i++) res = v[i] + "+" + res;
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << get(n) << endl;
  return 0;
}