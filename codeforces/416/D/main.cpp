#include <bits/stdc++.h>
#define maxn 400006

using namespace std;

int n;
long long a[maxn];
int ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int k = 1;
    while (k <= n)
    {
        ans ++;
        int i, j;
        for (i = k; a[i] == -1;)
            i++;
        for (j = i+1; a[j] == -1;)
            j++;
        if (j > n)
            break;
        long long d = (a[j] - a[i])/(j-i);
        if ((a[j]-a[i])%(j-i) || a[j] - (j-k)*d <= 0)
        {
            k = j;
            continue;
        }
        k = j+1;
        for (; k <= n && a[j] + (k-j)*d > 0 && (a[k] == -1 || a[k] == a[j]+(k-j)*d);)
            k++;
    }
    cout << ans;
    return 0;
}
