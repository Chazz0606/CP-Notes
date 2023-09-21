#include<bits/stdc++.h>

using namespace std;

vector<int> high_precision_add(vector<int> a, vector<int> b){ // NOLINT(misc-no-recursion)
    if (a.size() < b.size())
        return high_precision_add(b, a);
    int sum = 0;
    for (int i = 0; i < static_cast<int>(a.size()); i++){
        sum += a[i];
        if (i < b.size())
            sum += b[i];
        a[i] = sum % 10;
        sum /= 10;
        if (!sum && i >= b.size())
            break;
    }
    if (sum)
        a.push_back(sum);
    return a;
}

vector<int> unit_high_precision_multiply(vector<int>& a, int b){
    vector<int> c = {};
    for (int i = 0; i < static_cast<int>(a.size()); i++){
        int prod_num = a[i] * b;
        vector<int> product = {prod_num % 10};
        if (prod_num / 10)
            product.push_back(prod_num / 10);
        product.insert(product.begin(), i, 0);
        c = high_precision_add(c, product);
    }
    return c;
}

vector<int> high_precision_multiply(vector<int> a, vector<int> b){ // NOLINT(misc-no-recursion)
    if (a.size() < b.size())
        return high_precision_multiply(b, a);
    vector<int> c = {};
    for (int i = 0; i < static_cast<int>(b.size()); i++){
        vector<int> unit_product = unit_high_precision_multiply(a, b[i]);
        unit_product.insert(unit_product.begin(), i, 0);
        c = high_precision_add(c, unit_product);
    }
    return c;
}

int main() {
    string str_a; string str_b;
    cin >> str_a >> str_b;

    vector<int> a = {};
    vector<int> b = {};
    for (int i = static_cast<int>(str_a.length())-1; i >= 0; i--)
        a.push_back(str_a[i] - '0');
    for (int i = static_cast<int>(str_b.length())-1; i >= 0; i--)
        b.push_back(str_b[i] - '0');

    vector<int> c = high_precision_multiply(a, b);
    string str_c;
    for (int i = static_cast<int>(c.size())-1; i >= 0; i--)
        str_c += to_string(c[i]);

    cout << str_c << endl;

    return 0;
}