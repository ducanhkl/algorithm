#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int n, k;
int a[maxn];
map <int, int> cnt;
long long ans = 0;

long long calc(long long x)
{
    return x*(x-1)/2;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] ^= a[i-1];
        a[i] = min(a[i], (1<<k)-a[i]-1);
        cnt[a[i]]++;
    }
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    {
        long long len = it->second;
        ans += calc(len/2);
        ans += calc((len+1)/2);
    }
    cout << calc(n+1)-ans;
    return 0;
}
