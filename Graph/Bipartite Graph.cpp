
ll n;
vll adj[mxx*3];
bool is_bipartite;
pll bip(vll &side,ll st)
{
    ll parity[3]={};    side[st] = 0;
    queue<ll> q;  q.push(st);
    while (!q.empty()) {
        ll v = q.front(); q.pop();
        parity[side[v]]++;
        for (ll u : adj[v]) {
            if (side[u] == -1) {
                side[u] = side[v] ^ 1;
                q.push(u);
            }
            else is_bipartite &= side[u] != side[v];
        }
    }
    return {parity[0],parity[1]};
}
void solve()
{
    vll side(n, -1);
    vector< pll >res;
    is_bipartite = true;
    for(ll st=0;st<n;st++)
    {
        if(side[st]==-1)
        {
            pll p=bip(side,st);
            if(is_bipartite)res.pb({p.ff,p.ss});
        }
    }
    if(!is_bipartite)cout<<"Not Bipartite"<<endl;
    else for(ll i=0;i<SZ(res);i++)cout<<res[i].ff<<" - "<<res[i].ss<<endl;
}
