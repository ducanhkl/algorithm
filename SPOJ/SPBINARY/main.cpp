#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1001

using namespace std;
unsigned long long dd1[maxn], dd0[maxn];
ll n, k;

int main()
{
    memset(dd1, 0, sizeof(dd1));
    memset(dd0, 0, sizeof(dd0));
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    dd1[1] = dd1[0] = 1;
    dd0[1] = dd0[0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = i-1; j >= 0 && i-j <= k; j--)
        {
            dd1[i] += dd0[j];
            dd0[i] += dd1[j];
        }
    cout << dd1[n] + dd0[n];
    return 0;
}
