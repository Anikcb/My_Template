int modInv ( int a, int m )
 {
    int x, y;
    int g = gcdExtended( a, m, &x, &y );
    if(g!=1)return -1;
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
