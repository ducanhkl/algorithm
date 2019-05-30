#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m;
int root[maxn], cnt[maxn];
vector <int> e[maxn];
long long ans = 0;

int getroot(int u)
{
    if (root[u] == u)
        return u;
    else return root[u] =getroot(root[u]);
}

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);

    return 0;
}
