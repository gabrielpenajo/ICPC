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
	int n, dist;
    cin >> n >> dist;
    int cont = 1;
    int max = 1;
    int prev = -1;
    forn (i, n)
    {
        int altitude;
        cin >> altitude;
        if (altitude - prev <= dist && prev != -1)
        {
            cont++;
            if (cont > max)
            {
                max = cont;
            }
        }
        else
            cont = 1;
        
        prev = altitude;
    }

    cout << max << endl;
    
	return 0;
}