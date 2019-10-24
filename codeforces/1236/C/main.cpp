#include <bits/stdc++.h>

using namespace std;


int n;

const int maxn = 400;
vector <int> g[maxn];


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int j = 1;
    for (int i = 1; i <= n*n; i++)
    {
        g[j].push_back(i);
        if (i%n == 0)
            continue;
        if ((i/n)%2)
            j--;
        else
            j++;
    }
    for (int i = 1; i <= n; i++, cout << endl)
    {
        for (auto x : g[i])
        {
            cout << x << " ";
        }
    }
    return 0;
}
