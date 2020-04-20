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

// dp[stacks][blocks]
ll dp[MAX][MAX];
ll cont;
ll arranjos(int s, int b)
{
	if (s <= 0 || b < 0)
		return 0;
	if (b == 0 || s == 1)
		return 1;
	if (dp[s][b] != -1)
    {
        return dp[s][b];
    }

	ll ans = arranjos(s, b-s) + 2*arranjos(s-1, b) - arranjos(s-2, b);
	ans %= MOD;
    if (ans < 0)
        ans += MOD;
	dp[s][b] = ans;
	
	return ans;
}

int main() 
{
	cont = 0;
	int s, b;
	cin >> s >> b;
	memset(dp, -1, sizeof(dp));
	cout << arranjos(s, b-s) << endl;

	return 0;
}