#include <bits/stdc++.h>

using namespace std;

#define forn(i, j) for (int i = 0; i < j; i++)
#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAX 5000
#define MOD 1000000007

int main()
{
    string b;

    long long s;

    cin >> b >> s;

    long long eAnt = -1;
    long long eCont = 0;

    vector<long long> dists;

    long long len = b.size();

    for (long long i = 0; i < len * 2; i++)
	{
        if (b[i % len] == 'E')
		{
            if (eAnt >= 0)
                dists.push_back(i - eAnt);                
            eAnt = i;
            eCont++;

            if (i >= len)
                break;
        }
    }

    if (eCont > 0)
        eCont--;   

    long long total = ((s * s + s) / 2) * eCont;

    for (long long i : dists)
    {
        long long x = s - i;
        x > 0 && (total -= (x*x + x) / 2);
    }

    cout << total << endl;
}