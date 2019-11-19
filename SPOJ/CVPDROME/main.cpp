#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, nht = 0;
string s;
long long h[maxn], ht[maxn], hs[200], cnt[maxn], ans = 0;

void add(long long x)
{
    int pos = lower_bound(ht+1, ht+nht+1, x)-ht;
    if(ht[pos] == x)
        cnt[pos] ++;
}

long long get(long long x)
{
    int pos = lower_bound(ht+1, ht+nht+1, x)-ht;
    if (ht[pos] != x)
        return 0;
    return cnt[pos];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 'a'; i <= 'z'; i++)
        hs[i] = i - 'a';
    for (int i = 'A'; i <= 'Z'; i++)
        hs[i] = i-'A'+26;
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        {
            h[i] = h[i-1]^(1LL<<hs[s[i-1]]);
            ht[++nht] = h[i];
        }
    ht[++nht] = 0;
    sort(ht+1, ht+nht+1);
    add(0);
    for (int i = 1; i <=n ; i++)
    {
        ans += get(h[i]);
        for (int j = 0; j < 64; j++)
                ans += get(h[i]^(1LL<<j));
        add(h[i]);
    }
    cout << ans;
}
