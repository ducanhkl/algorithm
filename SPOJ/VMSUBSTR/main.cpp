#include <bits/stdc++.h>
#define maxn 1000006
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

int l, q;
int a[maxn], b[maxn], sl[maxn];
int f[256][256];

int main()
{
    reset(a), reset(b), reset(sl);
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> l;
    for (int i = 1; i <= l; i++)
    {
        char x;
        cin >> x;
        a[i] = (int)(x-'A');
    }
    sl[a[1]] ++;
    for (int i = 2; i <= l; i++)
        f[a[i]][a[i-1]] ++, sl[a[i]] ++;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        memset(b, 0, sizeof(b));
        string _b;
        cin >> _b;
        int  s = _b.length(), res = 0, sum = 0;
        for (int i = 0; i < _b.size(); i++)
            b[i+1] = (int)(_b[i]-'A');
        for (int j = 1; j <= s; j++)
        {
            res += sl[b[j]];
            for (int k = 1; k <= s; k++)
                sum += f[b[j]][b[k]];
        }
        cout << res - sum << endl;
    }
    return 0;
}
