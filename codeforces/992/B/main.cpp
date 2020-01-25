#include <iostream>

using namespace std;

int n, ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
    {
        int t = i^j;
        if (t > j && t <= n && i + j > t && j+t > i && t+i > j)
            ans ++;
    }
    cout << ans;
    return 0;
}
