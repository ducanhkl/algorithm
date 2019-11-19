#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector <long long> ans;
long long dem;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    long long sl = 1;
    while (n > 1)
    {
        for (dem  = 1; n > dem-1; dem *= 2)
            ans.push_back(k*sl);
        ans.pop_back();
        n -= dem/2 - 1;
        sl ++;
    }
    cout << ans.size() + 1 << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << k*(sl+1);
    return 0;
}
