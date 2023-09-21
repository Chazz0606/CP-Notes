#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

vector<int> add_hp(const vector<int>& a,
                   const vector<int>& b) {  // NOLINT(misc-no-recursion)
  if (b.size() > a.size()) return add_hp(b, a);
  vector<int> c;
  int r = 0;
  for (int i = 0; i < b.size(); i++) {
    int x = a[i] + b[i] + r;
    c.push_back(x % 10);
    r = x / 10;
  }
  for (int i = static_cast<int>(b.size()); i < a.size(); i++) {
    int x = a[i] + r;
    c.push_back(x % 10);
    r = x / 10;
  }
  if (r > 0) c.push_back(r);
  return c;
}

vector<int> multiply_int_hp(const vector<int>& a, const int b) {
  vector<int> c;
  int r = 0;
  for (int i : a) {
    int x = i * b + r;
    c.push_back(x % 10);
    r = x / 10;
  }
  while (r > 0) {
    c.push_back(r % 10);
    r /= 10;
  }
  return c;
}

void print_hp(const vector<int>& a) {
  for (int i = static_cast<int>(a.size() - 1); i >= 0; i--) cout << a[i];
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> sum = {0};
  vector<int> current = {1};
  for (int i = 1; i <= n; i++) {
    current = multiply_int_hp(current, i);
    sum = add_hp(current, sum);
  }
  print_hp(sum);
  return 0;
}