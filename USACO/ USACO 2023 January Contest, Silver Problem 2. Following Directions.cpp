#include<bits/stdc++.h>
using namespace std;

int n = 0;
vector<vector<char>> grid = {};
vector<vector<int>> pass = {};
vector<int> vertical_vat = {};
vector<int> horizontal_vat = {};

void change(int i, int j, int val){ // NOLINT(misc-no-recursion)
    pass[i][j] += val;
    if (i < n && j < n) {
        if (grid[i][j] == 'R')
            change(i, j + 1, val);
        else
            change(i + 1, j, val);
    }
}

long long find_cost(){
    long long cost = 0;
    for (int i = 0; i < n; i++)
        cost += pass[i][n] * vertical_vat[i];
    for (int i = 0; i < n; i++)
        cost += pass[n][i] * horizontal_vat[i];
    return cost;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        grid.emplace_back();
        pass.emplace_back();
        for (int j = 0; j < n; j++) {
            grid[i].emplace_back();
            pass[i].emplace_back();
            cin >> grid[i][j];
            pass[i][j] = 1;
        }
        vertical_vat.emplace_back();
        cin >> vertical_vat[i];
        pass[i].emplace_back();
        pass[i][n] = 0;
    }
    pass.emplace_back();
    for (int i = 0; i < n; i++) {
        horizontal_vat.emplace_back();
        cin >> horizontal_vat[i];
        pass[n].emplace_back();
        pass[n][i] = 0;
    }
    pass[n].emplace_back();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'R')
                pass[i][j+1] += pass[i][j];
            else
                pass[i+1][j] += pass[i][j];
        }
    }

    cout << find_cost() << endl;
    int q;
    cin >> q;
    for (int x = 0; x < q; x++){
        int i, j;
        cin >> i >> j;
        i--; j--;
        if (grid[i][j] == 'R'){
            change(i, j+1, -pass[i][j]);
            change(i+1, j, pass[i][j]);
            grid[i][j] = 'D';
        } else {
            change(i+1, j, -pass[i][j]);
            change(i, j+1, pass[i][j]);
            grid[i][j] = 'R';
        }
        cout << find_cost() << endl;
    }

    return 0;
}