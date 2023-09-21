#include<bits/stdc++.h>

using namespace std;

struct student{
    int chinese = 0;
    int math = 0;
    int english = 0;
    int total = 0;
};

int compare_students(student a, student b){
    if (a.total < b.total)
        return 0;
    else if (a.total > b.total)
        return 1;
    else {
        if (a.chinese < b.chinese)
            return 0;
        else if (a.chinese > b.chinese)
            return 1;
        else
            return 2;
    }
}

int main() {
    int n;
    cin >> n;
    vector<student> students = {};
    for (int i = 0; i < n; i++){
        student current;
        cin >> current.chinese >> current.math >> current.english;
        current.total = current.chinese + current.math + current.english;
        students.push_back(current);
    }

    vector<vector<int>> first_five = {};
    for (int i = 0; i < n; i++) {
        vector<int> std = {i+1, students[i].total};
        first_five.push_back(std);
        for (int j = static_cast<int>(first_five.size())-1; j > 0; j--) {
            int winner = compare_students(students[first_five[j][0]-1], students[first_five[j-1][0]-1]);
            if (winner == 1 || (winner == 2 && first_five[j][0] < first_five[j-1][0]))
                swap(first_five[j], first_five[j-1]);
            else
                break;
        }
        if (static_cast<int>(first_five.size()) > 5)
            first_five.erase(first_five.end());
    }

    for (vector<int> std: first_five)
        cout << std[0] << ' ' << std[1] << endl;

    return 0;
}