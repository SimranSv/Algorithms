// Author : AkSHAYA
#include <bits/stdc++.h>
using namespace std;

// Macros
#define fast ios_base::sync_with_stdio(0);
#define io      \
    cin.tie(0); \
    cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define in(array) \
    ll x;         \
    cin >> x;     \
    array.pb(x);
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define tc    \
    ll T;     \
    cin >> T; \
    while (T--)
#define ll long long
#define ull unsigned long long
#define lld long double
#define sz(x) long(x.size())
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define YES cout << "YES" \
                 << "\n";
#define NO cout << "NO" \
                << "\n";
#define yes cout << "Yes" \
                 << "\n";
#define no cout << "No" \
                << "\n";

// Constants
const lld PI = 3.141592653589793238;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

// debug
#ifndef ONLINE_JUDGE
#define debug(x)        \
    cerr << #x << "--"; \
    _print(x);          \
    cerr << "\n";
#else
#define debug(x)
#endif
template <class T>
void _print(T x)
{
    cerr << x;
}
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Mathematical functions
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return ((a / gcd(a, b)) * b); }
ll binpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans % m * a % m) % m;
        a = (a % m * a % m) % m;
        b >>= 1;
    }
    return ans % m;
}
bool is_prime(ll n)
{
    if (n == 2)
        return true;
    else if (n <= 1 || n > 1000000 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
void factors(ll n, vector<ll> &f)
{
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                f.push_back(i);
            else
            {
                f.push_back(i);
                f.push_back(n / i);
            }
        }
    }
}
//**************************************************************************//
vl a(1e5 + 1);
vl b(1e5 + 1);
vl pref(1e5 + 1);

ll phiold(ll n)
{ //
    ll res = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

void precompute()
{

    // debug(a);
    ll n = 100001;
    fo(i, 0, 1e5 + 1)
    {
        a[i] = i;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] == i)
        {
            for (ll j = i; j <= n; j += i)
                a[j] -= a[j] / i;
        }
    } // debug(a);
    pref[1] = a[1];
    fo(i, 2, 1e5 + 1)
    {
        pref[i] = (pref[i - 1] % mod + a[i] % mod) % mod;
    } // debug(pref);
}

void solve()
{
    ll n;
    cin >> n;
    ll ans1 = 0;
    fo(i, 1, n + 1)
    {
        ans1 = (ans1 % mod + (a[i] % mod * a[i] % mod) % mod) % mod;
    }
    ll ans2 = 0;
    fo(i, 1, n)
    {
        ans2 += (a[i] % mod * (pref[n] - pref[i])) % mod;
    }
    cout << (ans1 + ans2) % mod << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    fast io
    precompute();
    tc solve();
    return 0;
}