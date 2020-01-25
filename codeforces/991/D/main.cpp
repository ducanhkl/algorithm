/*#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin >> s1 >> s2;
    for (int i =1; i <= s1.length(); i++)
    {
        if (s1[i-1] == '0')
            a[1][i] = 0;
        else a[1][i] = 1;
        if (s2[i-1] == '0')
            a[2][i] = 0;
        else a[2][i] = 1;

    n = s1.length();
    for (int i = 2; i <= n; i++)
    {
        if (a[1][i] == 1 && a[2][i] == 0)
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        if (a[1][i] == 0 && a[2][i] == 1)
            dp[i][1] = (dp[i-1][0], max(dp[i-1][1], dp[i-1][2]))
        if (a[1][i] == 1 && a[2][i] == 0 && a[1][i-1] == 0 && a[2][i-1] == 0)
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int round_(double x){
    int y = x;
    if(x-y == 0) return y;
    return y+1;
}
int main(){
    int n;
    cin >> n;
    double sum = 0;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(&a[1], &a[n+1]);
    double cur = sum/n;
    if(cur >= 4.5){
        cout << 0;
        return 0;
    }
    double k = 1/(double)n;
    int delta = round_((4.5-cur)/k);
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < 5){
            count++;
            delta -= (5-a[i]);
            if(delta <= 0) break;
        }
    }
    cout << count;
    return 0;
}
