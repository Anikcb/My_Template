// How many time’s a prime “P” is in N!
// N=6,P=2
// N! = 1*2*3*4*5*6.
// N! = 1*2*3*(2*2)*5*(2*3).
// That means there are 4 2’s in 6!




ll PrimePower (ll n , ll p )
{
    ll freq = 0;
    ll x = n;
    while ( x )
    {
        freq += x / p;
        x = x / p;
    }

    return freq;
}
