#include <bits/stdc++.h>
#define maxn 400

using namespace std;

int n, a[maxn];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
        cin >> a[i];
    for (int i = 1; i <= 2*n; i++)
        for (int j = i+2; j <= 2*n; j++)
            if (a[j] == a[i])
        {
            ans += j-i-1;
            for (int k = j; k > i; k--)
                swap(a[k], a[k-1]);
            break;
        }
    cout << ans;
    return 0;
}
