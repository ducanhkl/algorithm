#include <bits/stdc++.h>

using namespace std;

typedef  pair <int, int>  pii;

int ans = INT_MAX;
int f[20][20], p[20];
pii vt[20];

int dis(pii x, pii y)
{
    return  abs(x.first - y.first) + abs(x.second - y.second);
}

int check() {
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        vt[p[i]] = {i/3, i%3};
    }
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            res += dis(vt[i], vt[j])*f[i][j];
        }
    }
    return res;
}

int main() {
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        f[s[i] - '0'][s[i-1] - '0'] ++;
    }
    for (int i = 1; i <= 10; i++)
    {
        p[i] = i;
    }
    do {
        ans = min(ans,  check());
    } while (next_permutation(p, p+10));
    cout << ans;
    return 0;
}
