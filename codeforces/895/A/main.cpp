#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000005
using namespace std;

int a[maxn];
int t;
int n, ans = INT_MAX, k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], t += a[i], a[i] += a[i-1];
    for (int i = 0; i <= n; i++)
        for (int j = i+1; j <= n; j++)
    {
        k = t - (a[j] - a[i]);
        ans = min(ans, abs(k - (a[j] - a[i])));
    }
    cout << ans;
    return 0;
}
