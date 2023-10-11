#include<bits/stdc++.h>

using namespace std;

struct person{
    int number;
    int score;
};

bool comp_person(person a, person b){
    if (a.score == b.score)
        return (a.number < b.number);
    else
        return (a.score > b.score);
}

int main() {
    int n; int m;
    cin >> n >> m;
    vector<person> people = {};
    for (int i = 0; i < n; i++) {
        person temp{};
        cin >> temp.number >> temp.score;
        people.push_back(temp);
    }

    sort(people.begin(), people.end(), comp_person);
    int last = m * 3 / 2;
    while (last < n && (people[last].score == people[m*3/2-1].score)){
        last++;
    }
    vector<person> passed (people.begin(), people.begin()+last);
    cout << people[m*3/2-1].score << ' ' << passed.size() << endl;

    for (person p: passed)
        cout << p.number << ' ' << p.score << endl;

    return 0;
}