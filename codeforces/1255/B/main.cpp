#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int maxn = 1e3+100;

int n,m;
ii a[maxn];
long long ans;

void solve()
{
    ans = 0;
    sort(a + 1,a + n + 1);
    if (m < n || n == 2)
    {
        cout << -1 << endl;
        return;
    }
    a[n + 1] = a[1];
    for(int i = 1; i <= n; i++)
        ans = (ans + a[i].second + a[i + 1].second);
    for(int i = 1; i <= m - n; i++)
        ans = (ans + a[1].second + a[2].second);
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i].first << " " << a[i + 1].first << endl;
    for(int i = 1; i <= m - n; i++)
        cout << a[1].first << " " << a[2].first << endl;;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].second;
            a[i].first = i;;
        }
        solve();
    }
}
