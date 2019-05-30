#include <bits/stdc++.h>
using namespace std;

long long countA, countB, maxA, maxB;
long long calc()
{
    if (maxA == 0)
        return min(countB, maxB);
    if (maxB == 0)
        return min(countA, maxA);
    if (countA == countB)
        return countA*2;
    if (countA > countB)
        return countB*2 + 1 + min((maxA - 1)*(countB+1), countA - countB-1);
    return countA*2 + 1 + min((maxB-1)*(countA+1), countB-countA-1);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> countA >> countB >> maxA >> maxB;
        cout << calc() << endl;
    }
    return 0;
}
