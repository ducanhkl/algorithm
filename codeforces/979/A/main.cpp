#include <bits/stdc++.h>

using namespace std;

long long n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 0)
        return cout << 0, 0;
    n++;
    if (n%2 == 0)
        return cout << n/2, 0;
    cout << n;
    return 0;
}
