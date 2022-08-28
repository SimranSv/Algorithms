// Simran Vedpathak
// Full Comdingbazi [ↂ■■ↂ]
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ss second
#define ff first

const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
// 101
// 010
// 001
ll expo(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        b = (b >> 1);
        a *= a;
    }
    return ans;
}

vll seivey(1e6 + 10);
void seive()
{
    ll n = 1e6;
    seivey[1] = 1;
    seivey[2] = 2;
    for (int i = 2; i <= n; i++)
    {
        seivey[i] = i;
    }
    for (int i = 2; i <= n; i += 2)
    {
        seivey[i] = 2;
    }
    for (int i = 3; i * i < n; i++)
    {
        if (seivey[i] == i)
        {
            for (int j = i*i; j <=n; j += i)
            {

                seivey[j] = i;
            }
        }
    }
}
void spf()
{
    for (int i = 1; i < 30; i++)
        cout << seivey[i] << " ";
}
int main()
{
    FAST;
    ll n;
    n = 1;
    seive();
    // cin >> n;
    while (n--)
        spf();
}