#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5;
int n;
long long a[maxn], b[maxn], cnt[100];

int main()
{
    memset(cnt, 0, sizeof(cnt));
    memset(b, 0, sizeof(b));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        long long t=a[i];
        while (t%2 == 0)
        {
            t /= 2;
            b[i]++;
        }
        cnt[b[i]]++;
    }
    int ma = 0;
    for (int i = 1; i <= 70; i++)
        if (cnt[ma] < cnt[i])
            ma = i;
    cout << n - cnt[ma] << endl;
    for (int i = 1; i <= n; i++)
        if (b[i] != ma)
        {
            cout << a[i]  << " ";
        }
    return 0;
}
