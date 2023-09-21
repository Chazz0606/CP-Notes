#include<bits/stdc++.h>

using namespace std;

int main() {
    int temp = 0;
    cin >> temp;
    const int n = temp;
    string names[n] = {};
    map<string, int> change = {};

    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        names[i] = name;
        change[name] = 0;
    }

    for (int i = 0; i < n; i++){
        string name;
        int money = 0;
        int g = 0;
        string receiver;
        cin >> name >> money >> g;
        if (money == 0 || g == 0){
            continue;
        }
        int each_money = money / g;
        change[name] -= each_money * g;
        for (int j = 0; j < g; j++){
            cin >> receiver;
            change[receiver] += each_money;
        }
    }

    for (string & name : names){
        cout << name << ' ' << change[name] << endl;
    }

    return 0;
}