#include <bits/stdc++.h>
#define maxn 50001
#define MOD 1000000007
#define BASE1 256
#define BASE2 257

using namespace std;

typedef pair <long long, long long> pii;
long long p1[maxn], p2[maxn], ha[maxn], hb[maxn], a[maxn], b[maxn], ha1[maxn], hb1[maxn];
int n;

pii get1(int i, int x)
{
    return {(ha[x+i-1] - ha[i-1]*p1[x]+MOD*MOD)%MOD, (ha1[x+i-1] - ha1[i-1]*p2[x]+MOD*MOD)%MOD};
}

pii get2(int i, int x)
{
    return {(hb[x+i-1] - hb[i-1]*p1[x]+MOD*MOD)%MOD, (hb1[x+i-1] - hb1[i-1]*p2[x]+MOD*MOD)%MOD};
}

bool check(int x)
{
    if (x > n)
        return false;

    for (int i = 1; i <= n-x+1; i++)
        if (get1(i, x) == get2(n-i-x+2, x))
            return true;

    return false;
}
int process(int x)
{
    int ans = 0, l = 0, r = maxn;

    while (l <= r)
    {
        int mid = (l+r)>>1;
        int m = mid;

        if (mid % 2 != x)
            mid++;

        if (check(mid))
            l = m+1, ans = mid;
        else r = m-1;
    }

    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = (int)(x - 'a');
        b[n-i+1] = (int)(x-'a');
    }

    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i < maxn; i++)
        p1[i] = (p1[i-1]*BASE1)%MOD;
    for (int i = 1; i < maxn; i++)
        p2[i] = (p2[i-1]*BASE2)%MOD;

    for (int i = 1; i <= n; i++)
        ha[i] = (ha[i-1]*BASE1+a[i])%MOD, hb[i] = (hb[i-1]*BASE1+b[i])%MOD;
    for (int i = 1; i <= n; i++)
        ha1[i] = (ha1[i-1]*BASE2+a[i])%MOD, hb1[i] = (hb1[i-1]*BASE2+b[i])%MOD;

    cout << max(process(1), process(0));

	return 0;
}

