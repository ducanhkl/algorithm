#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n;
long long a[maxn], b[maxn], ans1 = 0, ans2 = 0;
priority_queue <long long> q1, q2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        q1.push(a[i]), q2.push(b[i]);
    for (int i = 1; i <= n; i++)
    {
        if ( (!q1.empty() && q1.top() > q2.top()) || q2.empty() )
        {
            ans1 += q1.top();
            q1.pop();
        }
            else q2.pop();
        if ( (!q2.empty() && q1.top() < q2.top()) || q1.empty() )
        {
            ans2 += q2.top();
            q2.pop();
        }
            else q1.pop();
    }
    cout << ans1 - ans2;
    return 0;
}
