#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

int n, a[maxn], tree[maxn], b[maxn];
int ans = INT_MIN;

int get(int x)
{
    int res = 0;
    for(; x >0; x -= (x&(-x)))
        res = max(res, tree[x]);
    return res;
}
void update(int x, int y)
{
    for (; x < maxn; x+=(x&(-x)))
        tree[x] = max(tree[x], y);
}
int main()
{
   // freopen("inp.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b+1, b+n+1, a[i])-b;
    for (int i = 1; i <= n; i++)
    {
        int k = get(a[i]-1) + 1;
        update(a[i], k);
        ans = max(ans, k);
    }
    cout << ans;
    return 0;
}
