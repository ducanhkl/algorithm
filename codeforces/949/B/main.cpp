#include <bits/stdc++.h>

using namespace std;

unsigned long long calc(unsigned long long x, unsigned long long n)
{
    if ((x+1)%2 == 0 && x <= 2*n+1)
        return (x+1)/2;
    if (n%2 == 1)
        return (n+1)/2LL-1+calc(x/2+1, n-(n+1)/2+1);
    else
        return (n+1)/2LL-1+calc(x/2+2, n-(n+1)/2+1);
}

unsigned long long xx, nn;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int q;
    ios_base::sync_with_stdio(false);
    cin >> nn >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> xx;
        cout << calc(xx, nn) << endl;
    }
    return 0;
}
