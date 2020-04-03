#include <bits/stdc++.h>

#define x first
#define y second
#define pll pair<long long, long long>

using namespace std;

bool esq(pll A, pll B, pll ponto)
{
    return (ponto.y - A.y) * (B.x - A.x) -
        (ponto.x - A.x) * (B.y - A.y) > 0;
}

int main()
{
    int comp, larg, sold;
    cin >> comp >> larg >> sold;
    
    pll A(0, 0);
    pll B(comp, larg);
    
    long long cima, baixo;
    cima = baixo = 0;

    while (sold--)
    {
        pll aux;
        long long hab;
        cin >> aux.x >> aux.y >> hab;
        if (esq(A, B, aux))
            cima += hab;
        else
            baixo += hab;
    }

    cout << cima << " " << baixo << endl;
    return 0;
}