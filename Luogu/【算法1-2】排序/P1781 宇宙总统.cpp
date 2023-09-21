#include<bits/stdc++.h>

using namespace std;

bool str_comp(string& a, string& b){
    if (a.length() > b.length())
        return true;
    else if (a.length() < b.length())
        return false;
    else
        return (a > b);
}

int main() {
    int n;
    cin >> n;
    vector<string> votes = {};
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        votes.push_back(temp);
    }

    int max_index = 0;
    for (int i = 0; i < static_cast<int>(votes.size()); i++){
        if (str_comp(votes[i], votes[max_index]))
            max_index = i;
    }

    cout << max_index + 1 << endl;
    cout << votes[max_index] << endl;

    return 0;
}