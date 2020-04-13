#include <bits/stdc++.h>

#define forn(i, j) for (int i = 0; i < j; i++)
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int inscricoes;
    cin >> inscricoes;

    bool flag = true;
    int bobo;
    cin >> bobo;
    forn (i, inscricoes-1)
    {
        int votos;
        cin >> votos;
        if (votos > bobo)
        {
            flag = false;
        }
    }
    (flag) ? cout << "S" << endl :
        cout << "N" << endl;
    return 0;
}