ll n,edge;
const long long int INF = 1e15;
vector< pair<ll,ll> > adj[100002];
vector<ll> restore_path(ll s, ll t, vector<ll> const& p)
{
    vector<ll> path;
    for (ll v = t; v != s; v = p[v])path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}


void dijkstra(ll s, vector<ll> & d, vector<ll> & p)
{
    d.assign(n+1, INF);
    p.assign(n+1, -1);
    d[s] = 0;

    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty())
    {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}


void dijkstra(ll s, vector<ll> & d, vector<ll> & p)
{
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])continue;

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
