#include <bits/stdc++.h>

using namespace std;


long long mod = 1e9+7;
long long ans = 1, res = 1;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans = (ans*(long long)i)%mod;
    for (int i = 1; i <= n-1; i++)
        res = (res*2LL)%mod;
    cout << (ans-res+mod)%mod;
    return 0;
}
