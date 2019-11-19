#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n, A, B, b[maxn], x[maxn], y[maxn], a[maxn], q;
long long ans = 0;
void push(int p,int w, int t)
{
    int u = x[p], v = y[p];
    int pos = lower_bound(b+u, b+v, w) - b;
    b[pos] = t;
    while (pos < v-1 && b[pos] > b[pos+1])
        swap(b[pos], b[pos+1]), pos ++;
    while (pos > u && b[pos-1] > b[pos])
        swap(b[pos-1], b[pos]), pos --;
    return;
}

long long Find(int x, int y, int w)
{
    long long res = 0;
    for (int i = x; i < y; i++)
        if (a[i] > w)
            res ++;
        else
            res --;
    return res;
}

long long cal(int x, int y, int w)
{
    int pos = upper_bound(b+x, b+y, w) - b - x;
    return x+y - 2*pos;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        b[i] = i, a[i] = i;
    int tttt = sqrt(n);
    int bl = min(n, tttt*5+2);
    for (int i = 1; i <= n; i += bl)
    {
        for (int j = i; j < min(i+bl, n+1); j++)
            x[j] = i, y[j] = min(i+bl, n+1);
    }
    for (;q;q--)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (u == v)
        {
            cout << ans << endl;
            continue;
        }
        int A = a[u], B = a[v];
        swap(a[u], a[v]);
        if (A < B)
            ans ++;
        else
            ans --;
        push(u, A, B);
        push(v, B, A);
        ans += Find(u+1, min(y[u+1], v), A);
        ans -= Find(u+1, min(y[u+1], v), B);
        u = min(y[u+1], v);
        if (u < v)
        {
            ans += Find(x[v], v, A);
            ans -= Find(x[v], v, B);
            v = x[v];
            while (u != v)
            {
                ans += cal(u, y[u], A);
                ans -= cal(u, y[u], B);
                u = y[u];
            }
        }
        cout << ans << endl;
    }
}
