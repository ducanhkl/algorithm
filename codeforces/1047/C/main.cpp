#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, a[maxn], g = 0, ans = INT_MAX, dem = 0;
int dd[15000008];
int check[15000008];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], g = __gcd(a[i], g), dd[a[i]]++;
    for (int i = g+1; i < 15000008; i++)
    {
        int res = 0;
        for (int j = i; j < 15000008; j += i)
                res += dd[j];
        swap(check[i], res);
    }
    //cout << dem << endl;
    for (int i = 0; i < 15000008; i++)
        if (check[i] != 0)
            ans = min(ans, n-check[i]);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}
