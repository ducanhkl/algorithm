#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int a[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long t = 0;
    cout << n+1 << endl;
    for (int i = n; i >= 1; i--)
    {
        a[i] += t;
        a[i] = a[i]%n;
        cout << "1 " << i << " " <<  n-a[i] + i-1 << endl;
        t += n-a[i] + i-1;
        t %= n;
    }
    cout << "2 " << n << " " << n;
    return 0;
}
