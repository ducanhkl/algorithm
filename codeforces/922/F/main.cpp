
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))
// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))


// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

// fucking time limit :)))

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5+10;
int n, k;
int dd[maxn+10], ans = 0;
vector <int> e[maxn+10];

bool dfs(int u, long long s)
{
    long long t = 0;
    if (u > n || s > k)
        return false;
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        t += dd[v];
    }
    if (s+t == k)
        return true;
    if (dfs(u+1, s+t))
        return true;
    dd[u] = 0;
    if (dfs(u+1, s))
        return true;
    return false;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    long long s = 0;
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 2*i; j <= n; j += i)
            e[j].push_back(i);
    for (int i = 1; i <= n; i++)
        s += e[i].size();
    if (s < k)
        return cout << "No", 0;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        ans += dd[i];
    cout << "Yes" << endl << ans << endl;
    for (int i = 1; i <= n; i++)
        if (dd[i])
            cout << i << " ";
    return 0;
}
// fucking time limit :)))
