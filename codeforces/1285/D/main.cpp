#include <bits/stdc++.h>

using namespace std;

vector <long long> a;
int n;

long long solve(vector <long long> v, int p)
{
    if (p == -1)
    {
        return 0;
    }
    vector <long long> on, off;
    for (int i = 0; i < (int)v.size();  i++)
    {
        if ((v[i] >> p)&1)
            on.push_back(v[i]);
        else
            off.push_back(v[i]);
    }
    if (off.size() == 0)
        return solve(on, p-1);
    if (on.size() == 0)
        return solve(off, p-1);
    long long res1 = solve(on, p-1);
    long long res2 = solve(off, p-1);
    //cout << res1 << " " << res2 << endl;
    return min(res1, res2) + (1LL<<p);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i-1];
    cout << solve(a, 32);
    return 0;
}
