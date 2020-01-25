#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n;
long long a[maxn], b[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        long long alice = 0, bob = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 1; j <= n; j++)
            cin >> b[j];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        for (int i = 1; i < n; i++)
            alice += a[i], bob += b[i];
        if (alice == bob)
            cout << "Draw"; else
        if (alice < bob)
            cout << "Alice";
        else cout << "Bob";
        cout << endl;
    }
    return 0;
}
