#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long long ans = 0;
vector <int> a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    for (int i = 2; i <= n; i++)
        ans = ans + min(abs(a[i][0] - a[i-1][0]) + abs(a[i][1] - a[i-1][1]), abs(a[i][0] - a[i-1][1]) + abs(a[i][1] - a[i-1][0]));
    cout << ans+2*(min(a[1][0], a[1][1])-1) + abs(a[1][0] - a[1][1]);
    return 0;
}
