#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int nGifts;
    while (cin >> nGifts)
    {
        if (nGifts > 0)
        {
            vector<int> gifts;
            for (int i = 0; i < 2*nGifts; i++)
            {
                int aux;
                cin >> aux;
                gifts.push_back(aux);
            }
            vector<int> pairGifts;
            for (int i = 0; i < nGifts; i++)
            {
                pairGifts.push_back(gifts[i] + gifts[2*nGifts-1-i]);
            }
            sort(pairGifts.begin(), pairGifts.end());

            cout << pairGifts[pairGifts.size()-1] << " " << pairGifts[0] << endl;
        }
    }
}