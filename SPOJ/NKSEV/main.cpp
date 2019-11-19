#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

const long long maxn = 3000100, mod = 1337377;

struct node
{
    int next[40], finish = 0;
} tree[maxn];

string s;
int n;
long long f[maxn];


void add (string t)
{
    int now = 0;
    for (int i = t.size()-1; i >= 0; i--)
    {
        if (tree[now].next[t[i] - 'a'] == 0)
            tree[now].next[t[i]-'a'] = ++cnt;
        now = tree[now].next[t[i]-'a'];
    }
    tree[now].finish = 1;
}

void solve()
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        int now = 0;
        for (int j = i; j >= 0 && tree[now].next[s[j]-'a']; j--)
        {
            now = tree[now].next[s[j]-'a'];
            if (tree[now].finish == 1)
            {
                if (j-1 < 0)
                    f[i] ++;
                else
                    f[i] = (f[j-1] + f[i])%mod;
            }
        }
    }
    cout << f[len-1]%mod;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        add(t);
    }
    solve();
    return 0;
}
