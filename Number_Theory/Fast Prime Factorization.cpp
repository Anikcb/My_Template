ll arr[mxx];
vector<ll>v;

void seive()
{
    ll i,j;
    for(i=1;i<=mxx;i++)
        arr[i]=i;
    for(i=4;i<mxx;i+=2)
    {
        arr[i]=2;
    }

    for(i=3;i*i<=mxx;i++)
    {
        if(arr[i]==i)
        {
            for(j=i*i;j<=mxx;j+=i)
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }
}

void check(ll n)
{
    while(n!=1)
    {
        v.push_back(arr[n]);
        n=n/arr[n];
    }

}
