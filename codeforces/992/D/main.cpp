#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

struct data{
    string f;
    long long h, s;
    data () {}
};
data a[maxn];
int n;
long long ans = 0;

bool cmp(data x, data y)
{
    return x.s*y.h > y.s*x.h;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].f;
        for (int j = 0; j < a[i].f.length(); j++)
            if (a[i].f[j] == 'h')
                a[i].h++;
            else a[i].s++;
    }
    sort(a+1, a+n+1, cmp);
    long long s = 0, h = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a[i].f.length(); j++)
        {
            if (a[i].f[j] == 'h')
                ans += s, h++;
            else s++;
        }
    cout << ans;
    return 0;
}
