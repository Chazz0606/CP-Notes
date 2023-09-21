#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

vector<int> add_hp(const vector<int>& a, const vector<int>& b) {
  if (b.size() > a.size()) return add_hp(b, a);
  vector<int> c;
  int r = 0;
  for (int i = 0; i < static_cast<int>(b.size()); i++) {
    int x = a[i] + b[i] + r;
    c.push_back(x % 10);
    r = x / 10;
  }
  for (int i = static_cast<int>(b.size()); i < static_cast<int>(a.size());
       i++) {
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

vector<int> shift_hp(vector<int> a, int n) {
  if (a.size() == 1 && a[0] == 0) return a;
  if (n > 0) {
    vector<int> b(n, 0);
    b.insert(b.end(), a.begin(), a.end());
    return b;
  } else {
    vector<int> b(a.begin() - n, a.end());
    return b;
  }
}

string hp_convert_str(vector<int> a) {
  if (a.empty()) return "0";
  string res;
  for (int i = static_cast<int>(a.size() - 1); i >= 0; i--) {
    char x = a[i] + '0';
    res += x;
  }
  return res;
}

vector<int> multiply_hp(const vector<int>& a, const vector<int>& b) {
  vector<int> c = {0};
  for (int i = 0; i < static_cast<int>(b.size()); i++) {
    c = add_hp(c, shift_hp(multiply_int_hp(a, b[i]), i));
  }
  return c;
}

vector<int> str_convert_hp(string a) {
  vector<int> res = {};
  for (int i = static_cast<int>(a.length()) - 1; i >= 0; i--) {
    res.push_back(a[i] - '0');
  }
  if (res.empty()) return {0};
  return res;
}

void print_hp(const vector<int>& a) {
  for (int i = static_cast<int>(a.size() - 1); i >= 0; i--) cout << a[i];
  cout << endl;
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

vector<int> int_convert_hp(int a) {
  vector<int> res = {};
  while (a > 0) {
    res.push_back(a % 10);
    a /= 10;
  }
  if (res.empty()) res.push_back(0);
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  cin.get();
  string nums = {};
  getline(cin, nums);
  vector<int> dp[42][9] = {};
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = {0};
    }
  }

  for (int i = 0; i < n; i++) {
    dp[i][0] = str_convert_hp(nums.substr(0, i + 1));
    for (int j = 1; j <= k; j++) {
      vector<int> max = {0};
      for (int h = 0; h < i; h++) {
        vector<int> slice = str_convert_hp(nums.substr(h + 1, i - h));
        max = max_hp(max, multiply_hp(dp[h][j - 1], slice));
      }
      dp[i][j] = max;
      // for (int l = 0; l < n; l++) {
      // for (int r = 0; r <= k; r++) {
      // cerr << hp_convert_str(dp[l][r]) << ' ';
      // }
      // cerr << endl;
      // }
      // cerr << endl;
    }
  }

  print_hp(dp[n - 1][k]);
  return 0;
}