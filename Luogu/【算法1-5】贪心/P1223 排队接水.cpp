#include<bits/stdc++.h>

using namespace std;

struct person;
bool person_comp(person a, person b);

struct person{
    int tag = 1;
    int time = 0;
};

bool person_comp(person a, person b){
    return a.time < b.time;
}

int main() {
    int n = 0;
    cin >> n;

    vector<person> people = {};
    for (int i = 0; i < n; i++){
        people.emplace_back();
        people[i].tag = i+1;
        cin >> people[i].time;
    }
    sort(people.begin(), people.end(), person_comp);

    long long total = 0;
    long long last_wait = 0;
    for (int i = 0; i < n; i++){
        total += last_wait;
        last_wait += people[i].time;
        cout << people[i].tag << ' ';
    }
    cout << endl;
    double avg = (double) total / (double) n;
    printf("%.2lf\n", avg);

    return 0;
}