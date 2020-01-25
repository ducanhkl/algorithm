
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const long long oo = 123456789123456789;

int n, m;
long long d[N];
long long k;
vector<int> e[N];
queue<int> qu;
void bfs(int s)
{
    for (int i = 1; i <= n; ++i) {
        d[i] = -1;
    }
    d[s] = 0;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v : e[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
}

bool check(long long t)
{
    long long cnt = 0;
    for (int i = 2; i <= n; ++i) {
        cnt += t/d[i];
        if (cnt >= k) return true;
    }
    return cnt >= k;
}

long long bsearch(long long l, long long r)
{
    for (int i = 1; i <= 200; ++i) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    return l;
}

int main()
{
    freopen("TRANS.INP", "r", stdin);
    freopen("TRANS.OUT", "w", stdout);
    scanf("%d %d %lld", &n, &m, &k);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(1);
    printf("%lld", bsearch(0, 1000000000000000000));
    return 0;
}