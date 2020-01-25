#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long g;
        for (g = 1; g < 1e5; g++)
            if (g*(g+1)/2 > n)
                break;
        g --;
        cout << min(n-(g*(g+1)/2)+g, (g+2)*(g+1)/2-n+g+1) << endl;
    }
    return 0;
}
