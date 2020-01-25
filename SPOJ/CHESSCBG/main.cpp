#include <bits/stdc++.h>

using namespace std;

int key[2], mark[131072];
int dx[4] = {-1,0,1, 0};
int dy[4] = { 0,1,0,-1};
int power[70];
int state[30];

void convertint2matrix(int value)
{
    for(int i = 0; i < 16; i++)
    {
        int _c = i % 4;
        int _r = (i - _c) / 4;
        if((1 << i) & value) state[15 - i] = 1;
        else state[15 - i] = 0;
    }
}
int bfs(int x)
{
    queue <int> t;
    t.push(x);
    while(!t.empty())
    {
        int u = t.front();
        t.pop();
        convertint2matrix(u);
        for (int i = 0; i < 16; i++)
            if (state[i] == 1)
        {
            int _c = i%4;
            int _r = (i - _c)/4;
            for (int j = 0; j < 4; j++)
            {
                int r = _r + dx[j];
                int c = _c + dy[j];
                if(r >= 0 && r < 4 && c >= 0 && c < 4 && state[r*4+c] == 0)
                    {
                        int value = u + power[r*4+c] - power[_r*4+_c];
                        if(mark[value] == INT_MAX || mark[value] > mark[u] + 1)
                        {
                            mark[value] = mark[u] + 1;
                            t.push(value);
                        }
                    }
            }
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    for (int i = 0; i < 131072; i++)
        mark[i] = INT_MAX;
    power[15] = 1;
    for (int i = 14; i >= 0;i--)
        power[i] = power[i+1]*2;
    key[1] = key[2] = 0;
    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++)
            key[0] = key[0]*2 + (int)(s[j] - '0');
    }
    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++)
            key[1] = key[1]*2 + (int)(s[j]-'0');
    }
    mark[key[0]] = 0;
    bfs(key[0]);
    cout << mark[key[1]];
    return 0;
}
