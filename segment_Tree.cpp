class SEGTREE
{
public:
    vll seg;
    SEGTREE(ll n)
    {
        seg.resize(4 * n);
    }
    void build(ll ind, ll low, ll high, vll &v)
    {
        if (low == high)
        {
            seg[ind] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int l, int r, int low, int high)
    {
        if (high < l || low > r)
            return INT_MAX; // no overlap
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, l, r, low, mid);
        int right = query(2 * ind + 2, l, r, mid + 1, high);
        return min(left, right);
    }
    void update(int i, int ind, int change, int low, int high)
    {
        if (low == high)
        {
            seg[i] = change;
            return;
        }
        ll mid = (low + high) / 2;
        if (ind <= mid)
            update(2 * i + 1, ind, change, low, mid);
        else
            update(2 * i + 2, ind, change, mid + 1, high);
        seg[i] = min(seg[i * 2 + 1], seg[2 * i + 2]);
    }
    void print()
    {
        for (auto &i : seg)
            cout << i << " ";
        cout << '\n';
    }
};
