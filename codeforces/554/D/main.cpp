/*#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];

bool check ()
{
    int b[20], cnt = 0, dd[20];
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
        {
            int t = a[i];
            while (dd[t] == 0)
                b[++cnt] = t, dd[t] = 1, t = a[t];
        }
    for (int i = 1; i <= n; i++)
        if (b[i] != a[i])
            return false;
    return true;
}

int main()
{
    int dem = 0;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        if (check())
            {
                dem++;
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << endl;
            }
    } while (next_permutation(a+1, a+n+1));
    cout << dem;
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long k, f[100];
int ans[100];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n+1; i++)
        f[i] = f[i-1]+f[i-2];
    int id = 1;
    while (id <= n)
    {
        if (k <= f[n-id+1])
        {
            ans[id] = id;
            id++;
        } else
        {
            k -= f[n-id+1];
            ans[id] = id+1;
            ans[id+1] = id;
            id += 2;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
