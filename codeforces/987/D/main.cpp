#include <bits/stdc++.h>

using namespace std;

int dfs(int x)
{
    if (x == 1e5+1)
        return 0;
    dfs(x+1);
}
int main()
{
    dfs(1);
    cout << "no problem";
    return 0;
}
