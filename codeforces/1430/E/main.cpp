#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e5+100;

int n;
char s[maxn];
queue <int> q[maxn];
long long tree[maxn];

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
    {
        res += tree[x];
    }
    return res;
}

void upd(int x)
{
    for (; x < maxn; x += (x&(-x)))
    {
        tree[x]++;
    }
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] -= 'a';
        // cout << (int)s[i] << endl;
        q[s[i]].push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int c = s[n-i+1];
        int x = q[c].front();
        int v1 = q[c].front();
        int v2 = get(x);
        ans += q[c].front() - get(q[c].front()) - 1;
        upd(q[c].front()+1);
        q[c].pop();
    }
    cout << ans;
    return 0;
}
