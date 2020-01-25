#include <bits/stdc++.h>

using namespace std;

int n;
char a[100];

int ans = INT_MAX;

int dis(int x, int y)
{
    x -= 'A'; y -= 'A';
    if (x > y) swap(x, y);
    int num = 'Z'-'A';
    return min(abs(x-y), x+num-y+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n-3; i++)
    {
        int res = dis('A', a[i]) + dis('C', a[i+1]) + dis('T', a[i+2]) + dis('G', a[i+3]);
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
