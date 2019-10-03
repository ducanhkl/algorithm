#include <bits/stdc++.h>

using namespace std;

priority_queue <int> q;
int n, t;
int ans = 0;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && q.top() >= t-i)
            q.pop();
        int x;
        cin >> x;
        if (max(x, i) < t)
            q.push(x-i);
        ans = max(ans, (int)q.size());
    }
    cout << ans;
}
