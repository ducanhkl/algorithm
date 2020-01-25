#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int a[maxn];
int n;
long long ans = 0;
vector <int> tree[maxn];

int get(int x, int val)
{
    int res = 0;
    for (;x < maxn; x += (x&(-x)))
    {
        res += upper_bound(tree[x].begin(), tree[x].end(), val) - tree[x].begin();
    }
    return res;
}

int update(int x, int val)
{
    for (; x ; x -= (x&(-x)))
        tree[x].push_back(val);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans += get(i, min(n, a[i]));
        update(min(n, a[i]), i);
    }
    cout << ans;
    return 0;
}
