#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e3+100;
int n;
char s[maxn];
int a[30], dp2[maxn];
long long dp1[maxn];
int len = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    dp1[0] = 1;
    dp2[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = 0;
        dp2[i] = n;
        for (int j = i-1; j >= 0; j--)
        {
            pos = max(pos, i-a[s[j+1]-'a']);
            if (pos > j)
                break;
            dp1[i] = (dp1[i] + dp1[j])%mod;
            dp2[i] = min(dp2[i], dp2[j]+1);
            len = max(len, i-j);
        }
    }
    n = n;
    cout << dp1[n] << endl << len << endl << dp2[n];
    return 0;
}
