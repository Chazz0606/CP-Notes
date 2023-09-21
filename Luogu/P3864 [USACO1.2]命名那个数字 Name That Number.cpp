#include<bits/stdc++.h>

using namespace std;

int main() {
    string num;
    cin >> num;
    const string nums = "23456789";
    const char names[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'},
                        {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};
    vector<string> acceptable_names = {};
    for (int i = 0; i < 4167; i++) {
        string temp;
        cin >> temp;
        acceptable_names.push_back(temp);
    }

    vector<string> new_acceptable_names = {};
    for (string & acceptable_name : acceptable_names){
        if (acceptable_name.length() == num.length()){
            new_acceptable_names.push_back(acceptable_name);
        }
    }
    acceptable_names = new_acceptable_names;
    new_acceptable_names = {};

    for (int i = 0; i < static_cast<int>(num.length()); i++){
        for (string & acceptable_name : acceptable_names){
            bool flag = false;
            for (int j = 0; j < 3; j++){
                if (acceptable_name[i] == names[nums.find(num[i])][j]) {
                    flag = true;
                    break;
                }
            }
            if (flag){
                new_acceptable_names.push_back(acceptable_name);
            }
        }
        acceptable_names = new_acceptable_names;
        new_acceptable_names = {};
    }

    if (acceptable_names.empty()){
        cout << "NONE" << endl;
    }else{
        for (string & name: acceptable_names){
            cout << name << endl;
        }
    }

    return 0;
}