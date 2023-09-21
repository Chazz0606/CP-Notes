#include<bits/stdc++.h>

using namespace std;

bool test_lie(vector<vector<int>> inputs, vector<int> outputs, int n, int m){ // NOLINT(misc-no-recursion)
    if (n == 0 || m == 0) {
        return true;
    }

    for (int i = 0; i < n; i++){    // 遍历每排
        map<int, int> keys = {{0, -1}, {1, -1}};
        map<int, bool> reject = {{0, false}, {1, false}};
        map<int, vector<int>> same = {{0, {}}, {1, {}}};
        for (int j = 0; j < m; j++){    // 遍历每行
            int current_input = inputs[j][i];
            if (keys[current_input] == -1) {
                keys[current_input] = outputs[j];
                same[current_input].push_back(j);
            } else {
                if (outputs[j] != keys[current_input])
                    reject[current_input] = true;
                else
                    same[current_input].push_back(j);
            }
        }

        vector<int> same_rows = {};
        if (!(reject[0]) && keys[0] != -1)
            same_rows = same[0];
        else if (!(reject[1]) && keys[1] != -1)
            same_rows = same[1];

        if ((!(reject[0]) && keys[0] != -1) || (!(reject[1]) && keys[1] != -1)) {
            for (int j = 0; j < m; j++) // 把if检测的行删掉，
                inputs[j].erase(inputs[j].begin()+i);
            for (int j = static_cast<int>(same_rows.size())-1; j >= 0; j--) {
                inputs.erase(inputs.begin() + same_rows[j]);
                outputs.erase(outputs.begin() + same_rows[j]);
            }
            return test_lie(inputs, outputs, n-1, m-static_cast<int>(same_rows.size()));
        }
    }
    return false;
}

int main() {
    int t = 0;
    cin >> t;
    for (int x = 0; x < t; x++){
        int n = 0; int m = 0;
        cin >> n >> m;
        vector<vector<int>> inputs = {};
        vector<int> outputs = {};
        for (int i = 0; i < m; i++){
            inputs.emplace_back();
            for (int j = 0; j < n; j++){
                char temp = '0';
                cin >> temp;
                inputs[i].push_back(temp-'0');
            }
            outputs.emplace_back();
            cin >> outputs[i];
        }

        if (test_lie(inputs, outputs, n, m))
            cout << "OK" << endl;
        else
            cout << "LIE" << endl;
    }


    return 0;
}