#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int hour, min;
    while (cin >> hour >> min)
    {
        hour /= 30;
        min /= 6;
        cout << setfill('0') << setw(2) << hour << ':'
             << setfill('0') << setw(2) << min << endl;
    }
}