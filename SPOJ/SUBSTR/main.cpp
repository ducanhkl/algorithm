#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define mod 500000
#define maxn 10000006
#define M 100000007

using namespace std;

int64_t da[maxn], db[maxn], h[maxn];
string a, b;
int n, m;

int64_t gethash(int i)
{
    ll k = (da[i+m-1]-da[i-1]*h[m]%M + 1LL*M*M)%M;
    return k;
}
int main()
{
    memset(da, 0, sizeof(da));
    memset(db, 0, sizeof(db));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a >> b;
    n = a.length();
    m = b.length();
    a = " " + a;
    b = " " + b;
    h[0] = 1;
    for (int i = 1; i <= m; i++)
        db[i] = ((db[i-1]+b[i])*mod)%M, h[i] = (h[i-1]*mod)%M;
    for (int i = 1; i <= n; i++)
        da[i] = ((da[i-1]+a[i])*mod)%M;
    for (int i = 1; i <= n-m+1; i++)
        if (gethash(i) == db[m])
            cout << i << " ";
    return 0;
}
