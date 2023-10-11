#include<bits/stdc++.h>

using namespace std;

enum direction {x, y};  // 路径方向
enum heap {none, heap}; // 点位状态

int find_paths(vector<vector<int>>& points, int start_y, int start_x, int step_limit, int dir){ // NOLINT(misc-no-recursion)
    bool flag = true;
    int size = static_cast<int>(points.size());
    if (start_y == size-1 && start_x == size-1)
        return 1;
    if (!step_limit){   // 没有转向步数了，只查直线
        if (start_y == size-1 && !dir){ // 在最下面且方向为x
            for (int i = start_x; i < size; i++) {  // 确定路径上没有障碍
                if (points[size - 1][i]) {    // 点位有障碍
                    flag = false;
                    break;
                }
            }
            if (flag) return 1;
        }
        else if (start_x == size-1 && dir){ // 在最右边且方向为y
            for (int i = start_y; i < size; i++){
                if (points[i][size-1]){
                    flag = false;
                    break;
                }
            }
            if (flag) return 1;
        }
        return 0;   // 不在两个边，或边路径上有障碍
    }
    int cnt = 0;
    if (dir) {
        for (int i = start_y+1; i < size; i++) {
            if (points[i][start_x]) // 遇到障碍停止迭代
                break;
            cnt += find_paths(points, i, start_x, step_limit-1, x); // 添加此点转向后的可行步
        }
    } else {
        for (int i = start_x+1; i < size; i++) {
            if (points[start_y][i])
                break;
            cnt += find_paths(points, start_y, i, step_limit-1, y);
        }
    }
    return cnt;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n; int k;
        cin >> n >> k;
        vector<vector<int>> points = {};
        for (int a = 0; a < n; a++) {
            points.emplace_back();
            string temp;
            cin >> temp;
            for (int b = 0; b < n; b++)
                points[a].emplace_back((temp[b] == '.') ? none: heap);
        }
//        if (n == 4 && k == 3)
//            cout << 'a' << endl;
        int cnt = 0;
        cnt += find_paths(points, 0, 0, k, y); // 开局往下
        cnt += find_paths(points, 0, 0, k, x); // 开局往右
        cout << cnt << endl;
    }

    return 0;
}