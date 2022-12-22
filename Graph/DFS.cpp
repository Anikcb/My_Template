vector<ll>adj[10005];
ll color[10005];
ll time_in[10005],time_out[10005];
int dfs_timer,n;

void dfs(int v)
{
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
    {
        if (color[u] == 0)
        {
             dfs(u);
        }
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}
