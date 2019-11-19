#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, k;
long long a[maxn], f[maxn], ans = 0;
deque <int> q;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
            f[i] = a[i];
        else f[i] = f[q.front()]+a[i];
        while(!q.empty() && f[i] <= f[q.back()])
            q.pop_back();
        q.push_back(i);
        if (q.back() - q.front()>=k)
            q.pop_front();
    }
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans-f[q.front()];
    return 0;
}
