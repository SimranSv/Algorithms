// Coming back to CP soon guys...
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define stll set<ll>
#define msgll multiset<ll, greater<>>
#define msll multiset<ll>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define ss second
#define ff first
#define read(n, x)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll k;                  \
        cin >> k;              \
        x.pb(k);               \
    }
#define rep(i, j, k) for (ll i = j; i < k; i++)
#define st(v) sort(v.begin(), v.end())
#define sz(x) (ll) x.size()
#define no cout << "No\n";
#define yes cout << "Yes\n";
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
ll expo(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
double eps = 1e-6;
void Letsgo()
{
    //Time Complexity O(n+n);

    string s;
    cin >> s;
    vll lps(sz(s));
    
    rep(i, 1, sz(s))
    {
        ll j=lps[i-1];

        while (j>0&&(s[i] != s[j]))
        {
            j = lps[j - 1];
            
        }
        if(s[i]==s[j])
        j++;
        lps[i] = j;
        
    }
    rep(i, 0, sz(s)) cout << lps[i] << " ";
}
int main()
{
    FAST;

    ll n = 1, i = 0;
    // cin >> n;

    while (n--)
    {
        Letsgo();
    }
}