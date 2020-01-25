#include <bits/stdc++.h>

using namespace std;


void solve()
{
    memset(ans, 0, sizeof(ans));
    a[n+1] = {-1, 0};
    n++;
    int sl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first == a[i-1].first)
            sl++, sum1 += (sl%2)*a[i].second, sum += a[i].second;
        else
        {
            ans[cnt][0] = a[i];
            ans[cnt][1] = ans[cnt][2] = maxc;
            if (abs(ans[cnt][0] - ans[cnt-1][0] > 1))
            {
                ans[cnt][1] = sum1 + min(ans[cnt-1][1], ans[cnt-1][2]);
                ans[cnt][2] = sum-sum1 + min(ans[cnt-1][1], ans[cnt-1][2]);
                if (sl%2 == 0)
                    swap(ans[cnt][1], ans[cnt][2]);
            } else
            {
                if (ans[cnt][0] > ans[cnt-1][0])
                {
                    ans[cnt][1] = sum1 + min(ans[cnt-1][1], ans[cnt-1][2]);
                    ans[cnt][2] = sum-sum1+ min(ans[cnt-1][1],ans[cnt-1][2]+min(a[i-sl].second, a[i-sl+1].second*2);
                    if (sl %2 ==0)
                        swap(ans[cnt][1], ans[cnt][2]);
                } else
                {
                    ans[cnt][1] = sum1 + min(ans[cnt-1][2], ans[cnt-1][1] + 2*min(a[i-sl].second, a[i-sl].second);
                    ans[cnt][2] = sum-sum1 + min(ans[cnt-1][1]+, ans[cnt-1][2])
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        solve();
    }
    return 0;
}
