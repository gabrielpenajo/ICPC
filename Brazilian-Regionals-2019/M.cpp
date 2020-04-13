#include <bits/stdc++.h>

#define forn(i, j) for (int i = 0; i < j; i++)
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;

// Retorna o se eh possivel comer todos os sacos de pipoca tempo dado
bool check(vi sacos, int comps, int pipSeg, int tempo)
{
    ll max = pipSeg * tempo;
    ll minComps = 1;
    ll restante = max;
    for (auto i : sacos)
    {
        if (restante >= i)
            restante -= i;
        else
        {
            restante = max - i;
            if (restante < 0)
                return false;
            minComps++;
        }
    }
    return comps >= minComps;
}

int main()
{
    int numS, comps, pipSeg;
    cin >> numS >> comps >> pipSeg;
    vi sacos;
    int maior = 0;
    forn (i, numS)
    {
        int pipocas;
        cin >> pipocas;
        sacos.pb(pipocas);
        if (pipocas > maior)
            maior = pipocas;
    }

    // Limite maximo de tempo: supondo um pior caso, onde todos os
    // sacos de pipoca tem o valor maximo estipulado pelo problema
    // A seguinte formula pode ser testada:
    // t(max) = ceil(nroSacos/nroCompetidores) * ceil(qtdPipocas/tempoNecessario)
    ll l = 0, r = ceil(numS * 1.0/comps) * ceil(maior * 1.0/pipSeg);

    // Realizar busca binaria para ver se eh possivel comer todos
    // os sacos de pipoca no intervalo de tempo dado
    while (l < r)
    {
        ll mid = (l+r) / 2;
        if (check(sacos, comps, pipSeg, mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << fixed << l << endl;
    return 0;
}