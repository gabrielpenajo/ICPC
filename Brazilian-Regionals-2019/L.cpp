#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

typedef long long ll;
#define forn(i, n) for(long long i = 0; i < n; i++)

using namespace std;


int main() {
    ll res = 0, in;
    cin >> in;
    while (in > 0) {
        res += in%2;
        in /= 2;
    }
    cout << fixed << setprecision(0) << pow(2, res) << endl;
    return 0;
}