// Simran Vedpathak
// Full Comdingbazi ᓚᘏᗢ
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
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
vector<ll> v(2e6 + 10);
vll inv(2e6 + 10);
void fact()
{
    ll facto = 1;
    v[0] = 1;
    inv[0] = 1;
    rep(i, 1, 2e6 + 1)
    {

        v[i] = (v[i - 1] * i) % mod;
        inv[i] = expo(v[i], mod - 2) % mod;
    }
}
void Letsgo()
{
    ll n, m;
    cin >> n >> m;
    cout << (v[n] % mod*inv[m]%mod* inv[n - m] % mod) % mod << '\n';
}
int main()
{
    FAST;
    fact();
    ll n;
    cin >> n;
    // n = 1;
    while (n--)
    {
        Letsgo();
    }
    // idk why,but i have started liking CP more than anything
    // Welcome to 800 fam
}