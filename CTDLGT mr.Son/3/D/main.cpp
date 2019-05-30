#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;
int n;
int a[maxn];
priority_queue <long long> q;
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], q.push(-a[i]);
    while (q.size() > 1)
    {
        long long x = -q.top();
        q.pop();
        long long y = -q.top();
        q.pop();
        ans = (ans+x+y)%mod;
        q.push(-((x+y)%mod));
    }
    cout << ans;
    return 0;
}
