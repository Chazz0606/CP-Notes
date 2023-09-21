#include <bits/stdc++.h>
using namespace std;

vector<int> add_int_hp(vector<int> a, int b) {
  for (int i = 0; i < a.size(); i++) {  // NOLINT(modernize-loop-convert)
    int x = a[i] + b % 10;
    b /= 10;
    a[i] = x % 10;
    b += x / 10;
  }
  while (b > 0) {
    a.push_back(b % 10);
    b /= 10;
  }
  return a;
}

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

vector<int> multiply_hp(const vector<int>& a, const int b) {
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

vector<int> convert_hp(int a) {
  vector<int> res = {};
  while (a > 0) {
    res.push_back(a % 10);
    a /= 10;
  }
  if (res.empty()) res.push_back(0);
  return res;
}

vector<int> max_hp(const vector<int>& a, const vector<int>& b) {
  if (a.size() > b.size()) {
    return a;
  } else if (b.size() > a.size()) {
    return b;
  } else {
    for (int i = static_cast<int>(a.size() - 1); i >= 0; i--) {
      if (a[i] > b[i])
        return a;
      else if (b[i] > a[i])
        return b;
    }
    return a;
  }
}

int main() {
  const int N = 81;
  int n, m;
  cin >> n >> m;
  vector<int> sum = {0};
  for (int i = 0; i < n; i++) {
    int nums[N] = {};
    for (int j = 0; j < m; j++) cin >> nums[j];
    vector<int> dp[N][N] = {};
    for (int j = m - 1; j >= 0; j--) {
      dp[j][j] = multiply_hp(convert_hp(nums[j]), 2);
      for (int k = j + 1; k < m; k++)
        dp[j][k] = multiply_hp(max_hp(add_int_hp(dp[j + 1][k], nums[j]),
                                      add_int_hp(dp[j][k - 1], nums[k])),
                               2);
    }
    sum = add_hp(sum, dp[0][m - 1]);
  }
  print_hp(sum);

  return 0;
}