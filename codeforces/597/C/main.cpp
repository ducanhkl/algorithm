#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, k, a[maxn];
long long ans = 0;
long long tree[12][maxn];

long long get(int vt, int num)
{
    long long res = 0;
    for (; num != 0; num -= (num&(-num)))
        res += tree[vt][num];
    return res;
}

void update(int num, int vt, long long val)
{
    for (; num < maxn; num += (num&(-num)))
        tree[vt][num] += val;
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    long long res[20];
    memset(res, 0, sizeof(res));
    memset(tree, 0, sizeof(tree));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k+1; j++)
            if (j == 1)
                res[j] = 1;
            else
                res[j]  = get(j, a[i]-1);
        ans += res[k+1];
        for (int j = 1; j <= k; j++)
            update(a[i], j+1, res[j]);
    }
    cout << ans;
    return 0;
}
