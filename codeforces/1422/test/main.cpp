#include <iostream>

using namespace std;


const long long mod = 1e9+7;
char s[100];

int main()
{
    freopen("inptest.txt", "r", stdin);
    int n;
    long long ans = 0;
    while(cin >> s[++n]){
        ans = ans*10 + (s[n] - '0');
        ans %= mod;
    };
    n --;
    ans = -ans;
    for (int i = 0; i  < (1<<n); i++)
    {
        long long res = 0;
        for (int j = 1; j <= n; j++)
        {
            if ((i >> (j-1)) & 1)
            {
                res = res*10%mod + s[j] - '0';
            }
        }
        ans += res;
        ans %= mod;
    }
    ans = ans + mod;
    cout << ans%mod;
    return 0;
}
