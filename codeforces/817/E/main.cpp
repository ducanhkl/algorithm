#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6+100;
int cnt[maxn], tr[maxn][2];
int n, ed = 1;

int getans(int p, int l, int now, int pos)
{
    if (now == 0 || pos < 0)
        return 0;
    int b = (p>>pos)&1;
    if ((l>>pos)&1)
        return cnt[tr[now][b]] + getans(p, l, tr[now][b^1], pos-1);
    return getans(p, l, tr[now][b], pos-1);
}

int upd(int num, int val)
{
    int now = 1;
    for (int i = 30; i >= 0; i--)
    {
            int  ck = (num>>i)&1;
            if (!tr[now][ck])
                tr[now][ck] = ++ed;
            cnt[now] += val;
            now = tr[now][ck];
    }
    cnt[now]+=val;
    return 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int q, p;
        cin >> q >> p;
        if (q <= 2)
        {
            if (q == 1)
                upd(p, 1);
            else
                upd(p, -1);
            continue;
        }
        int l;
        cin >> l;
        cout << getans(p, l, 1, 30) << endl;
    }
    return 0;
}
