#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

ll a[maxn], res[maxn];
int n, k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 1; i < maxn; i++)
        res[i] = INT_MIN;
    a[0] = 0;
    res[0] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >>  a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i-1; j >= i-k && j >= 0; j--)
            res[i] = max(res[i], res[j] + a[i]);
    cout << *max_element(res, res+n+1);
    return 0;
}
