#include <bits/stdc++.h>

using namespace std;

int n, a[100001], dd[4];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int minn = *min_element(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        dd[a[i]-minn] ++;
    if (dd[2] == 0)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        return 0;
    }
    int x = min(dd[0], dd[2]);
    int ans1 = dd[0] + dd[1] + dd[2]-2*x;
    int ans2 = dd[0] + dd[2] + dd[1]%2;
    if (ans1 < ans2)
    {
        cout << ans1 << endl;
        for (int i = 1; i <= dd[0]-x; i++)
            cout << minn << " ";
        for (int i = 1; i <= dd[1]+2*x; i++)
            cout << minn+1 << " ";
        for (int i = 1; i <= dd[2]-x; i++)
            cout << minn+2 << " ";
        return 0;
    }
    cout << ans2 << endl;
    for (int i = 1; i <= dd[0] + dd[1]/2; i++)
        cout << minn << " ";
    for (int i = 1; i <= dd[1]%2; i++)
        cout << minn+1 << " ";
    for (int  i = 1; i <= dd[2]+dd[1]/2; i++)
        cout << minn+2 << " ";
    return 0;
}
