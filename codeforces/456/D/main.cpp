#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;

int n, k, cnt = 0;
int nxt[maxn][40];
int win[maxn], lost[maxn];

void add(string s)
{
    int now = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        if (nxt[now][c] == 0)
        {
            nxt[now][c] = ++ cnt;
        }
        now = nxt[now][c];
    }
}


void solve(int pos)
{
    int cnt = 0;
    for  (int i = 0; i < 30; i++)
    {
        int new_p = nxt[pos][i];
        if (new_p)
        {
            cnt++;
            solve(new_p);
            win[pos] |= !win[new_p];
            lost[pos] |= !lost[new_p];
        }
    }
    if (cnt == 0)
    {
        win[pos] = 0;
        lost[pos] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        add(s);
    }
    solve(0);
    if (win[0] && lost[0])
    {
        cout << "First";
    } else
    {
        if (win[0])
        {
            if (k%2)
            {
                cout << "First";
            } else {
                cout << "Second";
            }
        } else {
            cout << "Second";
        }
    }
    return 0;
}
