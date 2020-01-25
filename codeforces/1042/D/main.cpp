#include <bits/stdc++.h>
#define maxn 200003
using namespace std;

long long tree[2*maxn], ans = 0;
long long a[maxn], b[2*maxn], t;
int n;

long long get1(int x)
{
    long long res = 0;
    for (; x < 2*maxn; x += (x&(-x)))
        res += tree[x];
    return res;
}

long long update(int x)
{
    for (; x; x -= (x&(-x)))
        tree[x] ++;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i-1];
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    for (int i = n+1; i <= 2*n; i++)
        b[i] = a[i-n]-t;
    sort(b+1, b+2*n+1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b+1, b+2*n+1, a[i]-t) - b;
        int pos2 = lower_bound(b+1, b+2*n+1, a[i-1]) - b;
        update(pos2);
        ans += get1(pos+1);
    }
    cout << ans;
    return 0;
}
