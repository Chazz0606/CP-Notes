#include<bits/stdc++.h>

using namespace std;

struct character{
    int facing = 0;
    string name;
};

int mod(int a, int b){
    while (a < 0)
        a += b;
    return a % b;
}

int main() {
    int temp1; int temp2;
    cin >> temp1 >> temp2;
    const int n = temp1; const int m = temp2;
    character people[n];
    for (character& person: people) {
        cin >> person.facing >> person.name;
        person.facing ^= 1;
        if (!person.facing)
            person.facing = -1;
    }

    int instructions[m];
    for (int i = 0; i < m; i++) {
        int direction;
        cin >> direction >> instructions[i];
        if (!direction)
            instructions[i] *= -1;
    }

    int current = 0;
    for (int instruction: instructions){
        current = mod((current + instruction * people[current].facing), n);
    }
    cout << people[current].name;

    return 0;
}