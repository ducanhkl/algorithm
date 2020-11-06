#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

int a[maxn];
int n;

void solve()
{
    sort(a+1, a+n+1);
    int pos = n;
    while (a[pos] == a[n])
        pos --;
    cout << pos/(a[n]-1)-1 << endl;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            {
                int k;
                cin >> k;
                a[k]++;
            }
        solve();
    }
    return 0;
}
