#include<bits/stdc++.h>
using namespace std;

long long grid[1000][1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    long long horizontal_score = 0;
    for (int i = 0; i < n; i++){
        long long scores[2] = {0, 0};
        for (int j = 0; j < n; j++){
            scores[j % 2] += grid[j][i];
        }
        horizontal_score += max(scores[0], scores[1]);
    }

    long long vertical_score = 0;
    for (int i = 0; i < n; i++){
        long long scores[2] = {0, 0};
        for (int j = 0; j < n; j++){
            scores[j % 2] += grid[i][j];
        }
        vertical_score += max(scores[0], scores[1]);
    }

    cout << max(horizontal_score, vertical_score) << endl;

    return 0;
}