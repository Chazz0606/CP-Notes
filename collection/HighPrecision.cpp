#include <bits/stdc++.h>
using namespace std;

class HighPrecision {
  private:
    vector<int> digits;

    size_t size() {
        return digits.size();
    }

    void testZero() {
        if (digits.empty()) digits.push_back(0);
    }

    HighPrecision emptyHP() {
        HighPrecision a;
        a.digits = {};
        return a;
    }

  public:
    HighPrecision() {
        digits = {0};
    }

    HighPrecision(string s) {
        for (int i = s.size() - 1; i >= 0; i--)
            digits.push_back(s[i] - '0');
        testZero();
    }

    HighPrecision(vector<int> x) {
        digits = x;
    }

    HighPrecision(long long x) {
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        testZero();
    }

    HighPrecision copy() {
        return HighPrecision(digits);
    }

    operator string() {
        string res;
        for (int i = size() - 1; i >= 0; i--) {
            char x = digits[i] + '0';
            res += x;
        }
        return res;
    }

    HighPrecision operator+(long long a) {
        HighPrecision b = emptyHP();
        for (int i = 0; i < static_cast<int>(size()); i++) {
            a += digits[i];
            b.digits.push_back(a % 10);
            a /= 10;
        }
        for (; a > 0; a /= 10) b.digits.push_back(a % 10);
        b.testZero();
        return b;
    }

    HighPrecision operator+(HighPrecision a) {
        if (a.size() > size()) return a + *this;
        HighPrecision b = emptyHP();
        int r = 0;
        int thisSize = size();
        int aSize = a.size();
        for (int i = 0; i < aSize; i++) {
            r += digits[i] + a.digits[i];
            b.digits.push_back(r % 10);
            r /= 10;
        }
        for (int i = aSize; i < thisSize; i++) {
            r += digits[i];
            b.digits.push_back(r % 10);
            r /= 10;
        }
        for (; r > 0; r /= 10) b.digits.push_back(r % 10);
        b.testZero();
        return b;
    }

    HighPrecision operator*(long long a) {
        if (*this == 0 || a == 0) return HighPrecision(0);
        HighPrecision b = emptyHP();
        int r = 0;
        for (int i : digits) {
            r += i * a;
            b.digits.push_back(r % 10);
            r /= 10;
        }
        for (; r > 0; r /= 10) b.digits.push_back(r % 10);
        b.testZero();
        return b;
    }

    HighPrecision operator*(HighPrecision a) {
        if (*this == 0 || a == 0) return HighPrecision(0);
        HighPrecision b = emptyHP();
        int thisSize = size();
        int aSize = a.size();
        for (int i = 0; i < thisSize; i++) {
            int r = 0;
            for (int j = 0; j < aSize; j++) {
                if (i + j < b.size()) {
                    r += b.digits[i + j] + digits[i] * a.digits[j];
                    b.digits[i + j] = r % 10;
                } else {
                    r += digits[i] * a.digits[j];
                    b.digits.push_back(r % 10);
                }
                r /= 10;
            }
            for (int k = aSize; r > 0; r /= 10, k++) {
                if (i + k < b.size()) b.digits[i + k] = r % 10;
                else b.digits.push_back(r % 10);
            }
        }
        b.testZero();
        return b;
    }

    bool operator>(HighPrecision a) {
        if (size() > a.size()) {
            return true;
        } else if (size() < a.size()) {
            return false;
        } else {
            for (int i = size() - 1; i >= 0; i--) {
                if (digits[i] > a.digits[i])
                    return true;
                else if (digits[i] < a.digits[i])
                    return false;
            }
            return false;
        }
    }

    bool operator<(HighPrecision a) {
        if (size() < a.size()) {
            return true;
        } else if (size() > a.size()) {
            return false;
        } else {
            for (int i = size() - 1; i >= 0; i--) {
                if (digits[i] < a.digits[i])
                    return true;
                else if (digits[i] > a.digits[i])
                    return false;
            }
            return false;
        }
    }

    bool operator==(HighPrecision a) {
        if (size() == a.size()) {
            for (int i = size() - 1; i >= 0; i--) {
                if (digits[i] != a.digits[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    bool operator>=(HighPrecision a) {
        if (size() > a.size()) {
            return true;
        } else if (size() < a.size()) {
            return false;
        } else {
            for (int i = size() - 1; i >= 0; i--) {
                if (digits[i] > a.digits[i])
                    return true;
                else if (digits[i] < a.digits[i])
                    return false;
            }
            return true;
        }
    }

    bool operator<=(HighPrecision a) {
        if (size() < a.size()) {
            return true;
        } else if (size() > a.size()) {
            return false;
        } else {
            for (int i = size() - 1; i >= 0; i--) {
                if (digits[i] < a.digits[i])
                    return true;
                else if (digits[i] > a.digits[i])
                    return false;
            }
            return true;
        }
    }

    void operator+=(int a) {
        *this = *this + a;
    }

    void operator+=(HighPrecision a) {
        *this = *this + a;
    }

    void operator*=(int a) {
        *this = *this * a;
    }

    void operator*=(HighPrecision a) {
        *this = *this * a;
    }

    friend ostream &operator<<(ostream &o, HighPrecision a) {
        o << (string) a;
        return o;
    }

    friend istream &operator>>(istream &i, HighPrecision &a) {
        string s;
        i >> s;
        a = HighPrecision(s);
        return i;
    }

    friend HighPrecision max(HighPrecision a, HighPrecision b) {
        return (a > b) ? a : b;
    }

    friend HighPrecision min(HighPrecision a, HighPrecision b) {
        return (a < b) ? a : b;
    }
};
