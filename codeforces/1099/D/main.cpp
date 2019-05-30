/*#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n;
int a[maxn], s[maxn];
long long ans = 0;
vector <int> e[maxn];

void dfs(int u, int p)
{
    if (e[u].size() == 0 && s[u] == -1)
    {
        s[u] = s[p];
        a[u] = 0;
        return;
    }
    if (s[u] == -1)
        {
            int res = INT_MAX;
            for (int i = 0; i < (int)e[u].size(); i++)
            {
                int v = e[u][i];
                res = min(res, s[v] - s[p]);
            }
            if (res < 0)
            {
                cout << -1;
                exit(0);
            }
            a[u] = res;
            s[u] = s[p] + res;
        }
    else
        a[u] = s[u] - s[p];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v, u);
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            e[x].push_back(i);
        }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans;
    return 0;
}
*/


#include <bits/stdc++.h>

using namespace std;

typedef pair <double, double> pii;
// đĩnh nghĩa 1 kiểu mới là pii, từ kiểu dữ liệu cặp ghép
pii a[20];
double w;
int n;
double fopt = INT_MIN, fnow = 0;
int xopt[20], res[20];

//fopt là đáp án tối ưu, xopt là tập giá trị tối ưu
// fnow là đáp án hiện thời, res là tâp giá trị hiện thời

bool cmp(pii x, pii b)
{
    // hàm này để sắp xếp sao cho v[i]/b[i] theo thứ tự tăng dần thoả mãn đa thức tham lam
    return (x.second/x.first) > (b.second/x.first);
}

void update()
{
    if (fnow < fopt)
        return;
    fopt = fnow;
    for (int i = 1; i <= n; i++)
        xopt[i] = res[i];
}
////
int ll;
void findans(int x)
{
    for (int i = (int)(w/a[x].first); i >= 0; i--)
    {
        fnow += a[x].second*i;
        w -= a[x].first*i;
        res[x] = i;
        if (x == n) // nếu x == n thì ta đã tìm được phương án tối ưu mới
            update();
        else
            if (fnow+w*(a[x+1].second/a[x+1].first) >= fopt) // thuật toán tham lam cho thấy còn có thể tìm được phương án tốt hơn phương án hiện tại
                findans(x+1); // tiếp tục tìm kiếm
        fnow -= a[x].second*i;
        w += a[x].first*i;
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    // a[i].first tương ứng với g[i];
    // a[i].second tương ứng với v[i];
    sort(a+1, a+n+1, cmp); // sắp xếp để có được phương án tối ưu
    findans(1); // tìm kết quả
    cout << fopt << endl; // xuất kết quả
    for (int i = 1; i <= n; i++)
        printf("%f %f %d \n", a[i].first, a[i].second, xopt[i]); // đáp án của bài toán
}
