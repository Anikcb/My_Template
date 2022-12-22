vector<ll>edge[1000];
ll parent[1000];
ll level[1000];
bool visit[1000];
void BFS(ll s,ll d)
{
    queue<ll>Q;
    Q.push(s);
    while(!Q.empty())
    {
        ll cnt=Q.front();
        visit[cnt]=true;
        Q.pop();
        for(ll i=0;i<edge[cnt].size();i++)
        {
           ll v=edge[cnt][i];
           while(!visit[v])
           {
               level[v]=level[cnt]+1;
               visit[v]=true;
               parent[v]=cnt;
               Q.push(v);
           }
        }
    }
    cout<<level[d]<<endl;
    while(d!=s)cout<<d<<" ",d=parent[d];
    cout<<endl;
}
