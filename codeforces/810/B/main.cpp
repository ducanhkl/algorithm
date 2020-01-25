#include <bits/stdc++.h>
#define maxn 100001
#define maxc 1e9+7

using namespace std;

int n, k;
long long t = 0;
struct data
{
    int f, s;
};
data a[maxn];
bool cmp(data d1, data d2)
{
    return min(d1.f *2, d1.s) - min(d1.f, d1.s) > min(d2.f * 2, d2.s) - min(d2.f, d2.s);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1;  i <= n; i++)
        cin >> a[i].f >> a[i].s;
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= k; i++)
        t += min(a[i].f*2, a[i].s);
    for (int i = k+1; i <= n; i++)
        t += min(a[i].f, a[i].s);
    cout << t;
    return 0;
}
