#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000004

using namespace std;

int n, a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    while(cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        for (int i = n; i >= 1; i--)
        {
            int check = true;
            for (int j = 1; j <= n; j++)
                if (i != j && __gcd(a[i], a[j]) > 1)
            {
                check = false;
                break;
            }
            if (check)
            {
                cout << a[i] << endl;
                break;
            }
        }
    }
    return 0;
}
