// It’s not for print. It’s just an dfs(), but can traverse and find the diameter of a graph with any value(here it is the max length gcd>1). (CODEFORCES 1101D)
ll arr[mxx*2];
ll A[mxx*2];
set< pll >s;
vll edge[mxx*2],v[mxx*2];

ll dfs(ll x,ll vis,ll d)
{
    s.insert({x,d});
    ll cnt=A[x]=1;
    for(auto u:edge[x])
    {
        if(u!=vis&&arr[u]%d==0)
        {
            cnt=max(cnt,dfs(u,x,d));
            cnt=max(cnt,A[x]+A[u]);
            A[x]=max(A[x],A[u]+1);
        }
    }
    re cnt;
}

int main()
{
    IOS;
    ll tst=1;
    // cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,val,res=0,a,b;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>val;
            arr[i]=val;
            for(ll j=2;j*j<=val;j++)
            {
                if(val%j==0)
                {
                    while(val%j==0)val/=j;
                    v[i].pb(j);
                }
            }
            if(val>1)v[i].pb(val);
        }
        for(ll i=1;i<n;i++)
        {
            cin>>a>>b;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        for(ll i=1;i<=n;i++)
        {
            for(auto d:v[i])
            {
                if(s.find({i,d})==s.end())res=max(res,dfs(i,i,d));
            }
        }
        cout<<res<<endl;

    }

    return 0;
}
