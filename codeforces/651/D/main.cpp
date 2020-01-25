#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n, a, b;
long long t;
int c[maxn], sum = 0, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> t;
    for (int i = 1; i <= n; i ++)
    {
        char t;
        cin >> t;
        int val = (t=='w')*b + 1;
        sum += val;
        c[i] = c[n+i] = val;
    }
    sum -= c[1];
    int l = 2, r = n;
    while (l <= n+1 && r < 2*n)
    {
        sum += c[++r];
        while (r-l+1 > n || (r-l + min(n-l+1, r-n-1))*a+sum>t)
            sum -= c[l++];
        ans = max(ans, r-l+1);
    }
    cout << ans;
    return 0;
}
