#include <bits/stdc++.h>

using namespace std;

string s;
long long ans = 0, dem = 0;
const long long mod = 1e9+7;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res%mod)*x)%mod;
    return res*res%mod;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a')
            dem++;
        else ans = (ans + fast_pow(2, dem)-1+mod)%mod;
    cout << ans;
    return 0;
}
