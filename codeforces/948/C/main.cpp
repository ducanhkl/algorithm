#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long a[maxn], b[maxn], res[maxn], ans[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i] += b[i-1];
    memset(ans, 0, sizeof(ans));
    memset(res, 0, sizeof(res));
    for (int i = 1; i<= n; i++)
    {
        long long h = a[i] + b[i-1];
        int pos = lower_bound(b+i, b+n+1, h)-b;
        if (pos > n || pos < i)
            continue;
        if (b[pos] != h)
            ans[pos] --, res[pos] += max(0LL,a[i] - (b[pos-1]-b[i-1]));
        else ans[pos+1] --;
    }
    for (int i = 1; i <= n; i++)
        ans[i] += ans[i-1];
    for (int i = 1; i <= n; i++)
        cout << (i+ans[i])*(b[i]-b[i-1]) + res[i] << " ";
    return 0;
}
