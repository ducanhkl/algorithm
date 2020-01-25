#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100, maxc = 1e5+100;

int n, k;
long long ans = 0, a[maxn], p[maxn];
map <long long, int> cnt;

void init()
{
    for (int i = 1; i < maxn; i++)
    {
        p[i] = 1;
        for (int j = 1; j <= k; j++)
        {
            if (p[i] > 1e18/j)
            {
                p[i] = -1;
                break;
            }
            p[i] = p[i] *i;
        }
    }
}

vector <int> pf(int num)
{
    vector <int> res;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i)
            continue;
        res.push_back(i);
        while (num % i == 0)
            num /= i;
    }
    if (num != 1)
        res.push_back(num);
    return res;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int it = 2;
        while (a[i] >= p[it])
        {
            if (p[it] == -1)
                break;
            while (a[i] % p[it] == 0)
                a[i] /= p[it];
            it ++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vector <int> v = pf(a[i]);
        long long val = 1;
        for (auto num : v)
        {
            if (p[num] == -1)
                {
                    val = -1;
                    break;
                }
            val *= p[num];
        }
        val = val/a[i];
        ans += cnt[val];
        cnt[a[i]] ++;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    solve();
    cout << ans;
    return 0;
}
