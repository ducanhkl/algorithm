#include <bits/stdc++.h>

using namespace std;

const long long maxn = 2e5+100, base = 211, mod = 1e9+7;

int n;
int cnt[maxn];
long long h[maxn][3], p[maxn];
char s[maxn];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        h[i][0] = h[i-1][0];
        h[i][1] = h[i-1][1];
        cnt[i] = cnt[i-1];
        if (s[i] == '0')
        {
            h[i][0] = (h[i-1][0] * base + '0' + i%2) % mod;
            h[i][1] = (h[i-1][1] * base + '0' + 1-i%2) % mod;
            cnt[i] ++;
        }
    }
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        p[i] = p[i-1]*base%mod;
    }
}

long long get_hash(int l, int r, int c)
{
    long long res = (h[r][c] - h[l-1][c]*p[cnt[r] - cnt[l-1]]%mod + mod) % mod;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n;  i++)
    {
        cin >> s[i];
    }
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int l1, l2, len;
        cin >> l1 >>  l2 >> len;
        long long res1 = get_hash(l1, l1+len-1, l1%2);
        long long res2 = get_hash(l2, l2+len-1, l2%2);
        if (res1 == res2)
        {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}
