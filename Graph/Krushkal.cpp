
struct edge
{
    ll u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
ll parent[mxx*2];
vector<edge> e;

ll find(ll r)
{
    return (parent[r] == r) ? r : parent[r]=find(parent[r]);
}

ll min_spanning_tree(ll n)
{
    sort(e.begin(), e.end());
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    ll count = 0, s = 0;
    for (ll i = 0; i < SZ(e); i++)
    {
        ll u = find(e[i].u);
        ll v = find(e[i].v);
        if (u != v)
        {
            parent[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                break;
        }
    }
    return s;
}



int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    cout << mst(n) << endl;
    return 0;
}
