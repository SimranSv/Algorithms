//Coming back to CP soon guys...
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
     ll n;
     cin>>n;
     vll v;
     read(n,v);

     ll curr_sum=0;
     ll sum=0;
     ll tot_sum=0;
     ll kadanesum=0;
     ll kadanemax=LONG_LONG_MIN;
     
     rep(i,0,n){
        curr_sum+=v[i];
        tot_sum+=v[i];
     
        kadanesum+=v[i];
        //normal kadane
        kadanemax=max(kadanemax,kadanesum);
        if(kadanesum<0)kadanesum=0;
        //Find minimum subarray sum 
        sum=min(sum,curr_sum);
        if(curr_sum>0)curr_sum=0;
     }
    if(kadanemax<0){
        cout<<kadanemax<<'\n';
        return;
    }
     //maximum(totalsum-minimumsum,kadanemax)
     cout<<max(kadanemax,tot_sum-sum)<<'\n';

    
}
int main()
{
    FAST;

    ll n=1, i = 0;
    // cin >> n;

    while (n--)
    {
        Letsgo();
    }
    
}
