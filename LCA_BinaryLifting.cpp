// Simran Vedpathak
// Full Comdingbazi
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll n, m;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
vll height(N);

vll adj[N];
vll parent(N);

void dfs(ll root, ll par, vector<vector<ll>> &rootstore)
{
    rootstore[root][0] = par;
    for (auto &i : adj[root])
    {
        if (i == par)
            continue;
        parent[i] = root;

        height[i] = height[root] + 1;

        dfs(i, root, rootstore);
    }
}

ll lca(ll x, ll y, vector<vector<ll>> &rootstore)
{
    for (int i = 1; i <= (ll)ceil(log2(n)); i++)
    {
        for (int j = 1; j <= n; j++)
        {

            ll par = rootstore[j][i - 1];
            if (par != -1)
            {
                rootstore[j][i] = rootstore[par][i - 1];
            }
        }
    }
    if (height[x] < height[y])
        swap(x, y);
    ll diff = height[x] - height[y];
    // O(logn)
    while (diff > 0)
    {
        ll val = ceil(log2(diff));
        x = rootstore[x][val];
        diff -= (1 << val);
    }

    ll Maxn = ceil((ll)(log2(n)));
    // cout<<Maxn<<'\n';

    if (x == y)
        return x;
    else
    {
        for (int i = Maxn; i >= 0; i--)
        {
            if (rootstore[x][i] != -1 && (rootstore[x][i] != rootstore[y][i]))
            {
                x = rootstore[x][i], y = rootstore[y][i];
            }
        }
    }

    return parent[y];
}
void solve()
{

    cin >> n >> m;
    vector<vector<ll>> rootstore(n + 1, vector<ll>((ll)ceil(log2(n) + 1), -1));
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    parent[1] = -1;
    dfs(1, -1, rootstore);
    ll q;
    cin >> q;
    // O(q*logn)
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << lca(x, y, rootstore) << '\n'; //<< '\n';
    }
    // TESTing Bro
    //  for (auto &i : rootstore)
    //  {
    //      for (auto &j : i)
    //      {
    //          cout << j << " ";
    //      }
    //      cout << '\n';
    //  }
}
// Bhai,mujhe patta nahi mera kya hoga,pr i will try my best bcz mujhe regret nahi karna yarrr
int main()
{
    FAST;
    ll n;
    n = 1;
    // cin >> n;
    while (n--)
        solve();
}
