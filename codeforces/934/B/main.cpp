#include <bits/stdc++.h>

using namespace std;

int k;
string s = "";
unsigned long long n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> k;
    if (k == 1)
        return cout << 4, 0;
    if (k/2 > 18)
        return cout << -1, 0;
    for (int i = 1; i <= k/2; i++)
        n = n*10+8;
    if (k%2 == 1)
        n = n*10;
    if (n > 1e18)
        cout << -1;
    else cout << n;
    return 0;
}

