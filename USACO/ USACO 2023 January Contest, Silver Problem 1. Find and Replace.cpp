#include<bits/stdc++.h>
using namespace std;

void remove(char val, vector<char>& v){
    int size = static_cast<int>(v.size());
    for (int i = 0; i < size; i++){
        if (v[i] == val)
            v.erase(v.begin()+i);
    }
}

int check(char val, set<char>& group, map<char, char>& change, vector<char>& check_loop){ // NOLINT(misc-no-recursion)
    if (change.count(change[val])) {
        if (group.insert(change[val]).second) {
            if (find(check_loop.begin(), check_loop.end(), change[val]) != check_loop.end())
                return check(change[val], group, change, check_loop);
            else
                return 0;
        } else {
            for (char alpha: check_loop){
                if (change[alpha] == change[val] && alpha != val)
                    return 0;
            }
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    int t;
    cin >> t;

    for (int x = 0; x < t; x++){
        string c1, c2;
        cin >> c1 >> c2;
        int length = static_cast<int>(c1.length());

        map<char, char> change = {};
        bool flag = true;
        for (int i = 0; i < length; i++){
            if (change.count(c1[i])) {
                if (c2[i] != change[c1[i]]) {
                    flag = false;
                    break;
                }
            } else {
                change[c1[i]] = c2[i];
            }

        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }

        map<char, char> temp = change;
        for (pair<char, char> alpha: change){
            if (alpha.first == alpha.second)
                temp.erase(alpha.first);
        }
        change = temp;

        int sum = 0;
        vector<char> check_loop = {};
        for (pair<char, char> alpha: change)
            check_loop.push_back(alpha.first);

        while (!check_loop.empty()){

//            if (check_loop[0] == 'E'){
//                cout << 'a' << endl;
//            }

            set<char> group = {check_loop[0]};
            sum += check(check_loop[0], group, change, check_loop);
            for (char alpha: group)
                remove(alpha, check_loop);
        }

        cout << change.size()+sum << endl;

    }

    return 0;
}