#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int n;
int a[maxn];
long long dp[maxn];
deque <int> q1, q2;

int getpos1(int vt, long long &val)
{
    while (!q1.empty() && a[q1.back()] <= a[vt])
    {
        int pos1 = q1.back();
        q1.pop_back();
        if (q1.empty())
            continue;
        int pos2 = q1.back();
        if (a[pos1] < a[vt])
            val = min(val, dp[pos2]+1);

    }
    int ans = 0;
    if (!q1.empty())
        ans = q1.back();
    q1.push_back(vt);
    return ans;
}


int getpos2(int vt, long long &val)
{
    while (!q2.empty() && a[q2.back()] >= a[vt])
    {
        int pos1 = q2.back();
        q2.pop_back();
        if (q2.empty())
            continue;
        int pos2 = q2.back();
        if (a[pos1] > a[vt])
            val = min(val, dp[pos2]+1);
    }
    int ans = 0;
    if (!q2.empty())
        ans = q2.back();
    q2.push_back(vt);
    return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = INT_MAX;
    dp[1] = 0;
    q1.push_back(1), q2.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (i == 4)
        {
            n++;
            n --;
        }
        dp[i] = dp[i-1] + 1;
        getpos1(i, dp[i]);
        getpos2(i, dp[i]);
    }
    cout << dp[n];
    return 0;
}
