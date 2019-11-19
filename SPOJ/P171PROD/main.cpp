#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int ans = 0;
int n, d[maxn];
pair <int, int> a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    int start = a[1].first, finish = a[1].second;
    for (int i = 2; i <= n; i++)
        if (a[i].first >= start)
            if (a[i].second < finish)
                ans ++;
            else {
                start = a[i].first;
                finish = a[i].second;
            }
    cout << ans;
    return 0;
}
