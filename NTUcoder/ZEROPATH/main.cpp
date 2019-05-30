#include <bits/stdc++.h>

using namespace std;

long long n;
map <long long, int> m;

void dfs(long long x)
{
    if (x == 0)
        return;
    m[x] = 1;
    for (long long i = 1; i <= sqrt(x); i++)
        if (x%i == 0)
            if (m[(i-1)*(x/i + 1)] == 0)
                dfs((i-1)*(x/i + 1));
}
int main()w
{
    cin >> n;
    dfs(n);
    cout << m.size()-1 << endl;
    for (map<long long, int>::iterator it = m.begin(); it != m.end(); it++)
        if (it->first != n)
            cout << it->first << " ";
}
