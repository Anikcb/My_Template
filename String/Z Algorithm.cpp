void z_function(string s)
{
    cout<<s<<endl;
    ll n = (ll) s.length();
    vector < ll > Z(n);
    Z[0] = 0;
    for (ll i = 1, L = 0, R = 0; i < n; ++i)
    {
        if (i <= R) Z[i] = min (R - i + 1, Z[i - L]);
        else Z[i] = 0;
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) ++Z[i];

        if (i + Z[i] - 1 > R)L = i, R = i + Z[i] - 1;

    }
    for(ll i=0;i<n;i++)cout<<Z[i]<<" ";
}
