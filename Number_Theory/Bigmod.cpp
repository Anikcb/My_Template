
ll bigmod ( ll a, ll p, ll m )
{
    ll res = 1;
    ll x = a%m;
    if(x==0)return 0;

    while ( p )
    {
        if ( p & 1 )
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}
