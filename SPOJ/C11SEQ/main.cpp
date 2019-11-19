#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int n, l, r, cnt = 0;
long long ans = 0, tree[5*maxn], a[maxn], b[5*maxn];

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return res;
}

void update(int x)
{
    for (; x < 5*maxn; x += (x&(-x)))
        tree[x] ++;
    return;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> r;
    a[0] = 0;
    b[++cnt] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
        b[++cnt] = a[i];
        b[++cnt] = a[i]-l;
        b[++cnt] = a[i]-r;
    }
    sort(b+1, b+cnt+1);
    for (int i = 0; i <= n; i++)
    {
        int pos = lower_bound(b+1, b+cnt+1, a[i]) - b;
        int pos1 = lower_bound(b+1, b+cnt+1, a[i]-l) - b;
        int pos2 = lower_bound(b+1, b+cnt+1, a[i]-r) - b;
        ans = ans + get(pos1) - get(pos2-1);
        update(pos);
    }
    cout << ans;
    return 0;
}
