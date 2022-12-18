ll inv[mxx];
void inv_fun(ll n,ll m)
{
    inv[1] = 1;
    for ( int i = 2; i <= n; i++ )
    {
        inv[i] = (-(m/i) * inv[m%i] ) % m;
        inv[i] = inv[i] + m;
    }
}
