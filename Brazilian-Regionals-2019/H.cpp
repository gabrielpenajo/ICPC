#include <bits/stdc++.h>

#define forn(i, j) for (int i = 0; i < j; i++)
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int voltas, placas;
    cin >> voltas >> placas;
    // placas = placas por volta

    int total = voltas * placas;
    vi placasPorc;
    for (int i = 1; i < 10; i++)
    {
        int dist = ceil(total * i * 0.1);
        cout << dist;
        (i < 9) ? cout << " " : cout << '\n';
    }
    return 0;
}