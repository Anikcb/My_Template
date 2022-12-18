struct state
{
    ll len, link;
    bool isclone;
    unordered_map<char,ll>next;
};
state st[2*mxx];
ll sz, last,t,TC;
bool terminal[2*mxx];
vector<ll>adj[2*mxx];

void initialize()
{
    last=0;
    st[0].len=0;
    st[0].link=-1;
    sz=1;
}
void automata(string s)
{
    initialize();
    ll n = SZ(s);
    for(ll i=0; i<n; i++)
    {
        char c = s[i];
        ll cur = sz++;
        st[cur].len= st[last].len+1;
        ll p;
        for(p=last; p!=-1 && !st[p].next[c]; p=st[p].link)
            st[p].next[c]=cur;
        if(p==-1)
            st[cur].link=0;
        else
        {
            ll q = st[p].next[c];
            if(st[p].len+1==st[q].len)
                st[cur].link=q;
            else
            {
                ll clone = sz++;
                st[clone].isclone=1;
                st[clone].len=st[p].len+1;
                st[clone].next=st[q].next;
                st[clone].link=st[q].link;
                for(; p!=-1 && st[p].next[c]==q; p=st[p].link)
                    st[p].next[c]=clone;
                st[q].link=st[cur].link=clone;
            }
        }
        last = cur;
    }
}

ll node[2*mxx];
ll dfs(ll s)
{
    if(node[s]!=-1)
        return node[s];
    ll n = adj[s].size();
    ll ret=1;
    if(st[s].isclone)
        ret=0;
    for(ll i=0; i<n; i++)
    {
        ret = ret+dfs(adj[s][i]);
    }
    return node[s]=ret;
}

char a[N];
vector<pair<ll,ll>>res;
ll occurance()
{
    memn(node);
    automata(a);
    for(ll i=1; i<sz; i++)
    {
        adj[st[i].link].pb(i);
    }
    ll ret=dfs(0);
    for(ll p=last; p!=-1; p=st[p].link)
    {
        terminal[p]=1;
        cout<<"p = "<<p<<endl;
    }
    ll n= strlen(a),p=0;
    for(ll i=0; i<n; i++)
    {
        p=st[p].next[a[i]];
        if(terminal[p])
            res.pb({i+1, node[p]});
    }
    n=res.size();
    printf("%d\n",n);
    for(ll i=0; i<n; i++)
    {
        printf("%d %d\n", res[i].first, res[i].second);
    }
}

string lcs (string & s, string & t) {
	sa_init();
	for (int i=0; i<(int)s.length(); ++i)
		sa_extend (s[i]);

	int v = 0, l = 0,
		best = 0, bestpos = 0;
	for (int i=0; i<(int)t.length(); ++i) {
		while (v && ! st[v].next.count(t[i])) {
			v = st[v].link;
			l = st[v].len;
		}
		if (st[v].next.count(t[i])) {
			v = st[v].next[t[i]];
			++l;
		}
		if (l > best)
			best = l,  bestpos = i;
	}
	return (t.substr (bestpos-best+1, best));
}

int main()
{
    scanf("%s",a);
    occurance();
    return 0;
}
