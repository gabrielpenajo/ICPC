#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back

using namespace std;


vector<vi> arvore;
// Vetor para armazenar os caminhos
// encontrados durante a DFS
vi caminhos;

int DFS(int v)
{
    if (arvore[v].size() == 0) 
    {
        return 1;
    }

    int max = 0;
    for (auto i : arvore[v]) 
    {
        int delacoes = DFS(i);
        if (delacoes >= max)
        {
            if (max > 0)
            {
                caminhos.pb(max);
            }
            max = delacoes;
        }
        else caminhos.pb(delacoes);
    }
    return ++max;
}

bool maior(int i, int j) { return i > j; }

int main() {
    int num, consultas;
    cin >> num >> consultas;
    arvore = vector<vi>(num);

    // Monta a arvore
    for (int i = 1; i < num; i++)
    {
        int pai;
        cin >> pai;
        arvore[--pai].pb(i);
    }

    // Monta o vetor de delacoes
    caminhos.pb(DFS(0));
    sort(caminhos.begin(), caminhos.end(), maior);
    
    int resp = 0;
    for (int i = 0; i < consultas; i++)
    {
        if (i >= caminhos.size()) break;
        resp += caminhos[i];
    }

    cout << resp << endl;

    return 0;
}