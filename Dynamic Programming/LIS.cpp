ll Input[2*N + 5], n ;

void LIS()
{
    sll lis;
    cin>>n;
    for( int i = 0 ; i < n ; i++ )
    {
        cin>>Input[i];
        if(lis.count(Input[i]))continue;
        lis.insert( Input[i]);
        auto it = lis.find( Input[i]);
        it++;

        if( it != lis.end()) lis.erase(it);
    }
    cout<<SZ(lis)<<endl ;
}
