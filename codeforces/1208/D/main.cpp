#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
long long tree[4*maxn], a[maxn], res[maxn], s[maxn], ans[maxn];

long long get(int x)
{
    long long res = 0;
    for (; x; x -= (x&(-x)))
        res += tree[x];
    return res;
}

void upd(int x, long long val)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] += val;
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        upd(i, i-1);
    for (int i = n; i >= 1; i--)
    {
        int mid, l = 1, r = n, res = 1;
        while (l <= r)
        {
            mid = (l+r)>>1;
            long long sum = get (mid);
            if (sum <= s[i])
                l = mid+1,res = mid;
            else
                r = mid-1;
        }
        upd(res+1, -res);
        ans[i] = res;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
