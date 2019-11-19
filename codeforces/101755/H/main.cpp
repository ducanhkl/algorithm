/*#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
const int maxc = 2e6+100, maxn = 1e3+10;
int n, m, d;int dd[maxn][maxn], d1[maxn][maxn];
pii bg , en;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    priority_queue <pair <int, pii> > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        if (x == 'S')
            bg = {i, j};
        if (x == 'F')
            en = {i, j};
        if (x == 'M')
            q.push({-d-1, {i, j}});
    }
    for (int i = 0; i <= n+1; i++)
        dd[i][0] = dd[m+1][0] = maxc;
    for (int i = 0; i <= m+1; i++)
        dd[0][i] = dd[n+1][i] = maxc;
    while (q.size())
    {
        pair <int, pii> u = q.top();
        q.pop();
        int l = -u.first;
        int x = u.second.first;
        int y = u.second.second;
        if (dd[x][y] > l)
            continue;
        dd[x][y] = l;
        if (l == 1)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (dd[xx][yy] < dd[x][y]-1)
            {
                dd[xx][yy] = dd[x][y]-1;
                q.push({-dd[xx][yy], {xx, yy}});
            }
        }
    }
    priority_queue <pair <int,pii> > q1;
    for (int i = 0;i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            d1[i][j] = INT_MAX;
    d1[bg.first][bg.second] = 0;
    q1.push({0, bg});
    while (q1.size())
    {
        pair <int, pii> u = q1.top();
        q1.pop();
        int l = -u.first;
        int x = u.second.first;
        int y = u.second.second;
        if (d1[x][y] < l || dd[x][y])
            continue;
        for (int i = 0; i < 4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if (d1[xx][yy] > d1[x][y]+1 && dd[xx][yy] == 0)
            {
                d1[xx][yy] = d1[x][y]+1;
                q1.push({-d1[xx][yy], {xx, yy}});
            }
        }
    }
    if (d1[en.first][en.second] == INT_MAX)
        return cout << -1, 0;
    cout << d1[en.first][en.second];
    return 0;
}
*/
#include<bits/stdc++.h>

using namespace std;

#define FTB(i,a,b) for(LL i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(LL i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(LL i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(LL i=a,_b=b;i>_b;i--)
#define endl "\n"
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define debug cout<<"VL\n"
#define coYES cout<<"YES\n"
#define coNO cout<<"NO\n"
#define coyes cout<<"yes\n"
#define cono cout<<"no\n"
#define coYes cout<<"Yes\n"
#define coNo cout<<"No\n"
#define PI 3.1415926535897
#define lbnd(f,s,gt) lower_bound(f,s,gt)
#define ubnd(f,s,gt) upper_bound(f,s,gt)
#define y1 aghksdmlsjdfjavljvlckdfmg
#define lamtron(n) fixed<<setprecision(n)
#define ALL(s) s.begin(),s.end()
#define ONLINE_JUDGE gshysrthrrthbd

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> inline T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

typedef double DB;
typedef long long LL;
typedef unsigned long long UL;
typedef long double LD;
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<bool> VB;



LL n,m,d,h[]={1,-1,0,0},k[]={0,0,-1,1};
vector<vector<char>> s;
vector<vector<int>> res;

struct DATA{
    LL a,b,c;
};


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>d;
    res.resize(n+1,VI(m+1,0));
    s.resize(n+1,vector<char>(m+1));
    II dau,cuoi;
    queue<DATA> Q;
    FTB(i,1,n) FTB(j,1,m){
        cin>>s[i][j];
        if(s[i][j]=='M'){
            Q.push({i,j,-d-1});
            res[i][j]=-d-1;
        }
        else if(s[i][j]=='S') dau={i,j};
        else if(s[i][j]=='F') cuoi={i,j};
    }
    while(Q.size()){
        LL x=Q.front().a,y=Q.front().b,g=Q.front().c;Q.pop();
        if(g>res[x][y]) continue;
        FT(i,0,4){
            LL u=x+h[i],v=y+k[i];
            if(u<1||u>n||v<1||v>m||g+1>res[u][v]) continue;
            res[u][v]=g+1;
            if(g<-1) Q.push({u,v,g+1});
        }

    }

    if(res[dau.fi][dau.se]||res[cuoi.fi][cuoi.se]){
        cout<<-1;
        return 0;
    }
    queue<II> q;
    q.push(dau);
    while(q.size()){
        LL x=q.front().fi,y=q.front().se;q.pop();
        FT(i,0,4){
            LL u=x+h[i],v=y+k[i];
            if(u<1||u>n||v<1||v>m||res[u][v]) continue;
            res[u][v]=res[x][y]+1;
            if(cuoi==II{u,v}){
                cout<<res[u][v];
                return 0;
            }
            q.push({u,v});
        }

    }
    cout<<-1;

	return 0;
}
