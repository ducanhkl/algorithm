#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int a[maxn];
int n;
long long c;

void process() {
    cin >> n >> c;
    long long number_of_odd = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            number_of_odd ++;
        }
    }
    long long number_of_even = n - number_of_odd;

    long long ans = (c+2) * (c+1) / 2;
    for (int i = 1; i <= n; i++) {
        ans -= (long long)a[i]/2 + 1;
        ans -=  c - (long long)a[i] + 1;
    }

    ans += number_of_odd * (number_of_odd + 1) / 2;
    ans += number_of_even * (number_of_even + 1) / 2;
    cout << ans << endl;
}

int main() {
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        process();
    }
    return 0;
}
