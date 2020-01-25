#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;

long long ans = 0;
int ma[maxn], mi[maxn], a[maxn], check[maxn];
long long tree[maxn];
int n;

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return  res;
}

long long update(int x)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] += 1;
    return 0;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l;
        check[i] = 0;
        cin >> l;
        mi[i] = INT_MAX;
        ma[i] = INT_MIN;
        for (int j = 1; j <=l; j ++)
        {
            cin >> a[j];
            a[j] ++;
            mi[i] = min(mi[i], a[j]);
            ma[i] = max(ma[i], a[j]);
            if (a[j] > mi[i])
                check[i] = 1;
        }
        if (check[i])
            ans += 2*(n-1);
        if (mi[i] != ma[i])
            ans++;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += check[i];
    }
    ans -= cnt*(cnt-1);
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            continue;
        ans += get(ma[i]-1);
        update(mi[i]);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--)
    {
        if (check[i])
            continue;
        ans += get(ma[i]-1);
        update(mi[i]);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    input();
    solve();
    cout << ans;
    return 0;
}
