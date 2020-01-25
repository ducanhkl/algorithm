#include <bits/stdc++.h>
#define BASE1 256
#define BASE2 257
#define MOD 1000000007
#define maxn 100001

using namespace std;

int n, k;
string s[maxn];
long long p1[maxn], p2[maxn], h1[99][maxn], h2[99][maxn];


struct data {
    long long res1, res2, pos;
    data (long long _res1, long long _res2, long long _pos)
    {
        res1 = _res1;
        res2 = _res2;
        pos = _pos;
    }
};
bool cmp (data x, data y)
{
    if (x.res1 == y.res1)
    {
        if (x.res2 == y.res2)
            return x.pos < y.pos;
        return x.res2 < y.res2;
    }
    return x.res1 < y.res1;
}

bool calc (data x, data y)
{
    return (x.res1 == y.res1 && x.res2 == y.res2);
}

bool check(int x)
{
    vector <data> res;
    int dem = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= (int)s[i].length()-x+1; j++)
            {
                //cout << (int)s[i].length() - x + 1 << endl;
                long long res1 = (h1[i][j+x-1]-h1[i][j-1]*p1[x]+MOD*MOD)%MOD;
                long long res2 = (h2[i][j+x-1]-h2[i][j-1]*p2[x]+MOD*MOD)%MOD;
                res.push_back(data(res1, res2, i));
            }

    sort(res.begin(), res.end(), cmp);

    for (int i = 2; i < res.size(); i++)
        {
            if (calc(res[i], res[i-1]))
                if (res[i].pos == res[i-1].pos+1)
                    dem ++; else;
            else dem = 1;
            if (dem >= k)
                return true;
        }
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    p1[0] = p2[0] = 1;
    for (int i = 1; i < maxn; i++)
        p1[i] = (p1[i-1]*BASE1)%MOD;
    for (int i = 1; i < maxn; i++)
        p2[i] = (p2[i-1]*BASE2)%MOD;
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s[i].size(); j++)
                h1[i][j] = (h1[i][j-1]*BASE1+s[i][j-1])%MOD;
            for (int j = 1; j <= s[i].size(); j++)
                h2[i][j] = (h2[i][j-1]*BASE2+s[i][j-1])%MOD;
        }

    int l = 0, r = maxn, ans = 0;
    while (l <= r)
    {
        int mid = (l+r) >> 1;

        if (check(mid))
            l = mid + 1, ans = mid;
        else r = mid - 1;
    }

    cout << ans;
}
