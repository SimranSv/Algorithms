// Simran Vedpathak
// Full Comdingbazi

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll N = 1e5 + 10;
void build(ll ind, ll low, ll high, vll &v, vll &seg)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, v, seg);
    build(2 * ind + 2, mid + 1, high, v, seg);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int l, int r, int low, int high, vll &seg)
{
    if (high < l || low > r)
        return INT_MAX; // no overlap
    if (low >= l && high <= r)
    {
        return seg[ind];
    }
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, l, r, low, mid, seg);
    int right = query(2 * ind + 2, l, r, mid + 1, high, seg);
    return min(left, right);
}
void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    vll seg(4 * n);

    build(0, 0, n - 1, v, seg);
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;

     cout<<query(0,l,r,0,n-1,seg);
    }
}
// i don't know whether i will succeed or not,but i am sure  about one thing, that i will try my best
int main()
{
    FAST;
    ll n;
    // n = 1;
    cin >> n;
    while (n--)
        solve();
}