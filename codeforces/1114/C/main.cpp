#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;
long long n, b;
vector <pair <long long, long long> > v;
long long p[maxn];
const long long maxc = 1e18+2;
void init()
{
    long long k = sqrt(b)+1;
    for (long long i = 2; i <= k; i++)
        if (b%i == 0)
        {
            long long cnt = 0;
            while (b%i == 0)
                b /= i, cnt++;
            v.push_back({i, cnt});
        }
    if (b != 1)
        v.push_back({b, 1});
}


long long calc(long long x, long long y)
{
    long long ans = 0;
    while (x != 0)
        x /= y, ans += x;
    return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    init();
    for (int i = 0; i < v.size(); i++)
    {
        long long h = v[i].first;
        p[i] = calc(n, h)/((long long)v[i].second);
    }
    long long ans = maxc;
    for (int i = 0; i < v.size(); i++)
        ans = min(ans, p[i]);
    cout << ans;
    return 0;
}
