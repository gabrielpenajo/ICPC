#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double distance(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) +
        pow(a.second - b.second, 2));
}

int main()
{
    int nInstr, maxDist;
    pair<int, int> target, current(0, 0);
    cin >> nInstr >> maxDist >> target.first >> target.second;
    int i = 1;
    while (i <= nInstr && distance(target, current) < maxDist)
    {
        char instr;
        cin >> instr;
        switch (instr)
        {
            case 'C':
                current.second++;
                break;
            case 'E':
                current.first--;
                break;
            case 'B':
                current.second--;
                break;
            case 'D':
                current.first++;
                break;
        }
        i++;
    }
    if (target == current)
        cout << "Sucesso" << endl;
    else
    {
        if (i > nInstr)
            i = nInstr;
        cout << "Trap " << i << endl;
    }
}