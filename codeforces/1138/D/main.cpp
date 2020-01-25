#include <bits/stdc++.h>

using namespace std;


const int maxn = 5e5+100;
string s, t;
int a[maxn], b[maxn], nxt[maxn];
int n, m, sl1 = 0, sl0 = 0;

void kmp()
{
    int j = 0;
    nxt[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        while (j && b[i] != b[j+1])
            j = nxt[j];
        if (b[i] == b[j+1])
            j++;
        nxt[i] = j;
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    n = s.length(), m = t.length();
    for (int i = 0; i < n; i++)
        a[i+1] = s[i]-'0', sl1 += (a[i+1] == 1), sl0 += (a[i+1] == 0);
    for (int i = 0; i < m; i++)
        b[i+1] = t[i]-'0';
    kmp();
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (j == m)
            j = nxt[j];
        j++;
        if (b[j] == 1 && sl1 == 0)
            break;
        if (b[j] == 0 && sl0 == 0)
            break;
        if (b[j] == 1)
            sl1 --;
        else
            sl0--;
        cout << b[j];
    }
    while (sl1--)
        cout << 1;
    while (sl0--)
        cout << 0;
    return 0;
}
