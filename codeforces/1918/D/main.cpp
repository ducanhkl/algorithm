#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const long long MAXC = 1e18+1;
int n;
long long dp[maxn];
int a[maxn];

bool check(long long max_sum)
{
    for (int i = 1; i <= n; i++) {
        dp[i] = MAXC;
    }
    dp[n+1] = 0;
    set<pair<long long, int>> tracer;
    tracer.insert({0, n+1});
    long long sum = 0;
    int last_pos = n+1;
    for (int i = n; i >= 1; i --)
    {
        while (sum > max_sum)
        {
            sum -= a[last_pos-1];
            tracer.erase({dp[last_pos], last_pos});
            last_pos --;
        }
        dp[i] = (*tracer.begin()).first + a[i];
        tracer.insert({dp[i], i});
        sum += a[i];
    }
    // build done, lets check
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum <= max_sum && dp[i] <= max_sum)
        {
            return true;
        }
        sum += a[i];
    }
    return false;
}

void process()
{
    long long ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long l = 0, r = MAXC;
    while (l <= r)
    {
        long long mid = (l+r)/2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
};

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        process();
    }
    return 0;
}
