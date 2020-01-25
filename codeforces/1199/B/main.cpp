#include <bits/stdc++.h>

using namespace std;

long double h, l;

int main()
{
    cin >> h >> l;
    cout << fixed << setprecision(10) << -(h*h-l*l)/(2.0*h);
    return 0;
}
