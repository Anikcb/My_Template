ll n;
vll adj[mxx*2];
vector<char> color;
vll parent;
ll dis[mxx*2];

ll cycle_start, cycle_end;

bool dfs(ll v)
{
    color[v] = 1;
    for (ll u : adj[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;
            dis[u]=dis[v]+1;
            if (dfs(u))
                return true;
        }
        else if (color[u] == 1 && abs(dis[v]-dis[u])>1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle()
{
    color.assign(n+3, 0);
    parent.assign(n+3, -1);
    cycle_start = -1;

    for (ll v = 1; v <= n; v++)
    {
        if (color[v] == 0 && dfs(v))break;
    }

    if (cycle_start == -1)cout << "IMPOSSIBLE"<<endl;
    else
    {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout<<SZ(cycle)<<endl;
        for(ll i=0;i<SZ(cycle);i++)cout<<cycle[i]<<" ";
        cout << endl;
    }
}
