#include <bits/stdc++.h>

using namespace std;


typedef  pair <int, int> ii;
const int maxn = 6e3+100;

struct dt
{
    int x, y, pos;
} a[maxn];

int n, ans = 0;
int dd[maxn];

void solve()
{
    priority_queue < ii > q;
    for (int i = 1; i <= n; i++)
    {
        q.push({ a[i].y, i});
        if (i % 2)
        {
            ii t = q.top();
            q.pop();
            ans += t.first;
            dd[t.second] = 1;
        }
    }
    stack <int> s;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dd[i])
            s.push(i);
        else
        {
            cout << a[i].pos <<  " " << a[s.top()].pos << endl;
            s.pop();
        }
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        a[i].pos = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i].y;
    sort (a+1, a+n+1, [] (dt x, dt y)
    {
        return x.x < y.x;
    });
    solve();
    return 0;
}