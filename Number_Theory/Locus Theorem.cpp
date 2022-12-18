
ll NCRmodP(ll n, ll r,ll p)
{
    if(n < r)return 0 ;
    ll den = (fact[r]*fact[(n-r)])%p;
    den =bigmod(den, p-2, p);
    return (fact[n]*den)%p;
}
ll Divider_Maker(ll n, ll r, ll p)
{
    if( n==0 && r==0)return 1;
    ll N = n%p, R = r%p;
    ll i =  NCRmodP(N, R, p);
    return (Divider_Maker(n/p, r/p, p) * i)%p;
}
ll Locus_Result(ll n, ll r, ll p)
{
    fact[0]=1;
    for(int i=1; i<p; i++)fact[i]=(i*fact[i-1])%p;
    return Divider_Maker(n, r, p);
}
