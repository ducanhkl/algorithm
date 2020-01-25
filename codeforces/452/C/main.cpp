#include <bits/stdc++.h>

using namespace std;

long double n, m;

int main()
{
    cin >> n>> m;
    cout << fixed << setprecision(10) <<  1.0/n + (n-1)*(m-1)/n/(m*n-1);
    return 0;
}
