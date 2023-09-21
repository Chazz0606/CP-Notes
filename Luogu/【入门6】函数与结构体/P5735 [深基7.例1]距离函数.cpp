#include <bits/stdc++.h>

using namespace std;

struct point
{
    double x;
    double y;
};

double distance(point a, point b)
{
    return pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
}

int main()
{
    point coordinates[3] = {};
    for (point &coordinate : coordinates)
        cin >> coordinate.x >> coordinate.y;

    double dis = 0;
    for (int i = 0; i < 3; i++)
    {
        dis += distance(coordinates[i], coordinates[(i + 1) % 3]);
    }

    printf("%.2lf", dis);

    return 0;
}
