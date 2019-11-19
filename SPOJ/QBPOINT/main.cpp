#include <bits/stdc++.h>
#define maxn 2001

using namespace std;

typedef pair <long double, long double> point;

point a[maxn];
int n;
long long ans = 0;
long long calc(int k)
{
    long long res = 0;
    vector <long double> v;
    for (int i = k-1; i >= 1; i--)
    {
        long double h = a[k].second - a[i].second;
        if (h != 0)
            v.push_back((a[k].first-a[i].first)/h);
        else v.push_back(INT_MAX);
    }
    sort(v.begin(), v.end());
    int sl = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i-1])
        {
            res += sl*(sl-1)/2;
            sl = 0;
        }
        sl ++;
    }
    res += sl*(sl-1)/2;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 3; i <= n; i++)
        ans += calc(i);
    cout << ans;
    return 0;
}
