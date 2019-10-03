#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int a[5*maxn];
int n;
set <long long> s;
long long sum = 0;
int cnt = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1;  i <= n; i++)
    {
        a[i] = ++cnt;
        a[i+n] = ++cnt;
        if (i%2 == 0)
            swap(a[i], a[i+n]);
    }
    for (int i = 1; i <= 2*n; i++)
        a[i+2*n] = a[i];
    for (int i = 1; i <= n; i++)
        sum += a[i];
    s.insert(sum);
    for (int i = 2;  i <= 2*n; i++)
    {
        sum -= a[i-1];
        sum += a[i+n-1];
        s.insert(sum);
        if (s.size() > 2)
            return cout << "NO", 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 2*n; i++)
        cout << a[i] << " ";
    return 0;
}
