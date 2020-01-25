#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000005;

struct dt
{
    int next[2],cnt;
} tr[6*maxn];

int n, cnt = 0, q;
int flip[100], a[maxn];

string tobin(int x)
{
    string t = "";
    for (int i = 0; i <= 31; i++)
    {
        t = t + (char)((int)((x >> (31-i))&1) + '0');
    }
    return t;
}

void push(string t)
{
    int now = 0;
    for (int i = 0; i < 32; i++)
    {
        int k = t[i] - '0';
        if (!tr[now].next[k])
            tr[now].next[k] = ++cnt;
        now = tr[now].next[k];
        tr[now].cnt++;
    }
    return ;
}

int update(int x)
{
    for (int i=32; i>=1; i--)
        flip[i]=(flip[i]+((x>>(i-1))&1))%2;
}


int get(int k)
{
    int res = 0;
    k = n-k+1;
    int now = 0;
    for (int i = 32; i >= 1; i--)
    {
        if (flip[i] == 0)
        {
            if (tr[tr[now].next[0]].cnt >= k)
            {
                now = tr[now].next[0];
                res = res*2;
            } else
            {
                k -= tr[tr[now].next[0]].cnt;
                now = tr[now].next[1];
                res = res*2+1;
            }
        } else
        {
            if (tr[tr[now].next[1]].cnt >= k)
            {
                now = tr[now].next[1];
                res = res*2;
            } else
            {
                k -= tr[tr[now].next[1]].cnt;
                now = tr[now].next[0];
                res = res*2+1;
            }
        }
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        string t = tobin(a[i]);
        //cout <<t << endl;
        push(t);
    }
    for (int i = 1; i <= q; i++)
    {
        string s;
        cin >> s;
        if (s == "FIND")
        {
            int x;
            cin >> x;
            cout << get(x) << endl;
        } else
        {
            int x;
            cin >> x;
            update(x);
        }
    }
    return 0;
}
