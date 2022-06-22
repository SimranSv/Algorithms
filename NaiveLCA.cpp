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

const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
vll height(N);
vll adj[N];
vll rootstore(N);
void dfs(ll root, ll par)
{
    for (auto &i : adj[root])
    {
        if (i == par)
            continue;
        height[i] = height[root] + 1;
        rootstore[i]=root;
        dfs(i, root);
    }
}
//O(n) worst case Time Complexity
ll naivelca(ll x,ll y){
    if(height[x]<height[y])swap(x,y);
        while(height[x]!=height[y]){
            x=rootstore[x];

        }
        if(x==y)return x;
        else {
            while(x!=y){
               x=rootstore[x];
               y=rootstore[y]; 
            }
            
        }

    
    return x;


}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, -1);
    ll q;
    cin>>q;
    // Total query+lca Time Complexity is O(q*n)
    while (q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<naivelca(x,y)<<'\n';
    }
}
//Bhai,mujhe patta nahi mera kya hoga,pr i will try my best bcz mujhe regret nahi karna yarrr
int main()
{
    FAST;
    ll n;
    n = 1;
    // cin >> n;
    while (n--)
        solve();
}
