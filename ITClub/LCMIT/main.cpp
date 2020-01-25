#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;

int n, k, a[1000005];
int dd[maxn];

bool kt(int x)
{
    int g = x;
    int check = true;
        for (int i = 1; i <= n; i++)
        {
            int t = a[i]/g;
            if (abs(t*g - a[i]) > k)
                {
                    check = false;
                    break;
                }
        }
    return check;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    int r = *max_element(a+1, a+n+1), l = 1, g = (l+r)/2;
    while(l < r)
    {
        g = (l+r)/2;
        int check = true;
        for (int i = 1; i <= n; i++)
        {
            int t = a[i]/g;
            if (abs(t*g - a[i]) > k)
                {
                    check = false;
                    break;
                }
        }
        if (check)
            l = g+1;
        else r = g-1;
    }
    g = (l+r)/2;
    if (kt(g+1))
        cout << g+1;
    else
        if (kt(g))
        cout << g;
    else cout << g-1;
	return 0;
}
