#include <bits/stdc++.h>

using namespace std;

long long a, b;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (long long i = 1; i < b*2LL; i++)
    {
        long long tu = a*i*(2LL*b - i);
        long long mau = b*b;
        if (tu % mau == 0)
            res ++;
    }
    cout << res;
    return 0;
}
