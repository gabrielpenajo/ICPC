#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int sizeMall, nStore;
    while (cin >> sizeMall >> nStore)
    {
        pair<int, int> pos(sizeMall/2, sizeMall/2);
        int currentStore = 1;

        // Rotation: 0 = 0 deg; 1 = 90 deg; 2 = 180 deg; 3 = 270 deg.
        // All clockwise, relative to vector v = (1, 0)
        int rotation = 0;
        int walk = 1;
        while (currentStore != nStore)
        {
            int floor = sqrt(currentStore);
            if (floor%2)
            {
                if (currentStore == pow(floor, 2) + 1)
                {
                    rotation = 1;
                }
                else if (currentStore == pow(floor + 1, 2) - floor)
                {
                    rotation = 2;
                    walk++;
                }
            }
            else
            {
                if (currentStore == pow(floor, 2) + 1)
                {
                    rotation = 3;
                }
                else if (currentStore == pow(floor, 2) + floor + 1)
                {
                    rotation = 0;
                    walk++;
                }
            }
            if (walk + currentStore > nStore)
                walk = nStore - currentStore;

            switch (rotation)
            {
                case 0:
                    pos.first += walk;
                    break;
                case 1:
                    pos.second += walk;
                    break;
                case 2:
                    pos.first -= walk;
                    break;
                case 3:
                    pos.second -= walk;
            }
            currentStore += walk;
        }

        cout << pos.second << " " << pos.first << endl;
    }
}