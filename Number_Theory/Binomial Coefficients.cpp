ll NcR(ll n, ll r)
{
    if(r > n - r) r = n - r;
    ll ans = 1,i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
